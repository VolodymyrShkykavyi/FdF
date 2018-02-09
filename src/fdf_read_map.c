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
	return (h);
}

int		fdf_read_map(char **argv, t_map *map_info)
{
	map_info->height = fdf_get_map_heaight(argv);
	if (!(map_info->map = (char **)ft_memalloc(
			sizeof(char *) * (map_info->height + 1))))
		return (1);

	return (0);
}