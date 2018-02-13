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

static int	fdf_get_map_height(char **argv)
{
	char	*line;
	int		h;
	int		fd;

	h = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("can't read file\n");
		exit (0);
	}
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
		exit (1);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		map_info->map[i++] = ft_strdup(line);
		ft_strdel(&line);
	}
	close(fd);
	return (0);
}

int			fdf_read_map(char **argv, t_map *map_info)
{
	char	**arr;
	int		i;

	map_info->height = fdf_get_map_height(argv);
	if (!(map_info->map = (char **)malloc(
			sizeof(char *) * (map_info->height + 1))))
		return (1);
	map_info->map[map_info->height] = NULL;
	if (fdf_save_map(argv, map_info))
		return (2);
	if (!(arr = ft_strsplit(map_info->map[0], ' ')))
		return (3);
	i = 0;
	while (arr[i])
		i++;
	map_info->width = i;
	ft_free_2arr(arr);
	return (0);
}
