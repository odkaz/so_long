/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knoda <knoda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 13:22:16 by knoda             #+#    #+#             */
/*   Updated: 2021/11/17 18:41:47 by knoda            ###   ########.fr       */
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

void		check_extension(char *path)
{
	int		i;
	char	*dot;

	i = 0;
	while (path[i])
		i++;
	if (i < 4)
		exit_error("check your .ber file path");
	dot = ft_substr(path, i - 4, 4);
	if (ft_strncmp(dot, ".ber", 4) != 0)
	{
		free(dot);
		exit_error("the file should be .ber extension");
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
		exit_error("check your .ber file path");
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

void	set_grid(t_map *m, char *line)
{
	char	*p;
	int		i;

	m->grid = (char **)my_calloc(m->h + 1, sizeof(char *));
	p = line;
	i = 0;
	while (*p)
	{
		if (*p == '\n')
		{
			m->grid[i] = ft_substr(line, 0, p - line);
			i++;
			line = p + 1;
		}
		p++;
	}
	if (p - line > 0)
	{
		m->grid[i] = ft_substr(line, 0, p - line);
		i++;
	}
	m->grid[i] = NULL;
}

int	width_count(char *line)
{
	int		w;

	w = 0;
	while (line[w])
	{
		if (line[w] == '\n')
			break ;
		w++;
	}
	return (w);
}

int	height_count(char *line)
{
	int		w;
	int		h;
	
	h = 0;
	if (*line)
		w = width_count(line);
	else
		exit_error("map is invalid");
	while (*line)
	{
		if (*line == '\n')
			line++;
		if (w != width_count(line))
			exit_error("the map should be rectangular");
		if (w)
		{
			line += w;
			h++;
		}
	}
	return (h);
}

t_map	*parse(char *path, t_map *map)
{
	char	*line;

	line = read_all(path);
	(*map).w = width_count(line);
	(*map).h = height_count(line);
	set_grid(map, line);
	check_grid(*map);
	check_walls(*map);
	return (map);
}