/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:35:50 by knoda             #+#    #+#             */
/*   Updated: 2021/11/22 18:36:32 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_my_strdup(const char *s)
{
	int		i;
	char	*res;

	if (s == NULL)
		return (ft_my_strdup(""));
	res = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

void	get_read(int fd, int *rv, char **line)
{
	char	*buf;
	char	*tmp;

	tmp = NULL;
	buf = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	*rv = read(fd, buf, BUFFER_SIZE);
	if (*rv != -1)
	{
		tmp = ft_my_strdup(*line);
		if (tmp)
		{
			free(*line);
			buf[*rv] = '\0';
			*line = ft_strjoin(tmp, buf);
			if (*line)
			{
				free(tmp);
				free(buf);
				return ;
			}
		}
	}
	free(buf);
	free(tmp);
	*rv = -1;
}

void	check_extension(char *path)
{
	int		i;
	char	*dot;

	i = 0;
	while (path[i])
		i++;
	if (i < 4)
		exit_error("check your .ber file path", NULL);
	dot = ft_substr(path, i - 4, 4);
	if (ft_strncmp(dot, ".ber", 4) != 0)
	{
		free(dot);
		exit_error("the file should be .ber extension", NULL);
	}
	free(dot);
}

char	*read_all(char *path)
{
	int		rv;
	char	*line;
	int		fd;

	rv = 0;
	check_extension(path);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit_error("check your .ber file path", NULL);
	line = NULL;
	while (rv != -1)
	{
		get_read(fd, &rv, &line);
		if (rv == 0)
			break ;
	}
	close(fd);
	return (line);
}
