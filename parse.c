/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 13:22:16 by knoda             #+#    #+#             */
/*   Updated: 2021/11/15 15:39:39 by knoda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_my_strdup(const char *s)
{
	int		i;
	char	*res;

	if (s == NULL)
		return (ft_my_strdup(""));
	res = (char	*)malloc((ft_strlen(s) + 1) * sizeof(char));
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

	buf = NULL;
	tmp = NULL;
	if ((buf = (char	*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		if ((*rv = read(fd, buf, BUFFER_SIZE)) != -1)
			if ((tmp = ft_my_strdup(*line)))
			{
				free(*line);
				buf[*rv] = '\0';
				if ((*line = ft_strjoin(tmp, buf)))
				{
					free(tmp);
					free(buf);
					return ;
				}
			}
	free(buf);
	free(tmp);
	*rv = -1;
}

char	*read_all(char *path)
{
	int		rv;
	char	*line;
	int		fd;

	rv = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit_error("check your .ber file path\n");
	line = NULL;
	while (rv != -1)
	{
		get_read(fd, &rv, &line);
		if (rv == 0)
			break;
	}
	close(fd);
	return (line);
}

void	set_map(char **map, char *line)
{
	char	*p;
	
	p = line;
	while (*p)
	{
		if (*p == '\n')
		{
			*map = ft_substr(line, 0, p - line);
			map++;
			line = p + 1;
		}
		p++;
	}
	if (p - line > 0)
	{
		*map = ft_substr(line, 0, p - line);
		map++;
	}
	*map = NULL;
}

char	**parse(char *path)
{
	char	*line;
	char	**m;
	int		i;
	
	line = read_all(path);
	m = (char **)my_calloc(100, sizeof(char *));
	i = 0;
	set_map(m, line);
	return (m);
}