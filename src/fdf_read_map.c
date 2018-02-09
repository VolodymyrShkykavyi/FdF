/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_read_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 02:00:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/02/09 02:00:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <fcntl.h>

static int fdf_get_map_heaight(char **argv)
{
	char	*line;
	int		h;
	int		fd;

	h = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (1);
	while (get_next_line(fd, &line) > 0)
	{
		h++;
		free(line);
	}
	close(fd);
	return (h);
}

static int	fdf_save_map(char **argv, t_map *map_info)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (1);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		map_info->map[i++] = ft_strdup(line);
		free(&line);
	}
	close(fd);
	return (0);
}

int		fdf_read_map(char **argv, t_map *map_info)
{
	map_info->height = fdf_get_map_heaight(argv);
	if (!(map_info->map = (char **)ft_memalloc(
			sizeof(char *) * (map_info->height + 1))))
		return (1);
	if (fdf_save_map(argv, map_info))
		return (2);
	return (0);
}
