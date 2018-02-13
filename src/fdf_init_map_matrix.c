/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init_map_matrix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 02:55:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/02/11 02:55:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_init_result_matrix(t_mlx *mlx, t_map *map_info)
{
	int		i;
	int		j;

	map_info->offset_x = mlx->width / 2;
	map_info->offset_y = mlx->height / 2;
	MALL_CHECK((map_info->result = (t_point **)malloc(
			sizeof(t_point *) * (map_info->height))));
	i = -1;
	while (++i < map_info->height)
	{
		j = -1;
		MALL_CHECK((map_info->result[i] = (t_point *)malloc(
				sizeof(t_point) * map_info->width)));
		while (++j < map_info->width)
		{
			map_info->result[i][j].x = map_info->matrix[i][j].x;
			map_info->result[i][j].y = map_info->matrix[i][j].y;
			map_info->result[i][j].z = map_info->matrix[i][j].z;
			map_info->result[i][j].color = map_info->matrix[i][j].color;
		}
	}
}

static void	fdf_save_map_point(t_mlx *mlx, t_map *map_info, t_point p,
								char **arr)
{
	int i;

	map_info->matrix[p.y][p.x].x = p.x - map_info->width / 2;
	map_info->matrix[p.y][p.x].y = p.y - map_info->height / 2;
	map_info->matrix[p.y][p.x].z = ft_atoi(arr[p.x]);
	i = 0;
	while (arr[p.x] && (ft_isdigit(arr[p.x][i]) || arr[p.x][i] == '-'))
		i++;
	if (i != 0 && arr[p.x][i] == '\0')
		map_info->matrix[p.y][p.x].color = -1;
	else if (i == 0 || arr[p.x][i] != ',')
	{
		ft_putstr("not a valid map\n");
		exit(2);
	}
	else
		map_info->matrix[p.y][p.x].color = ft_atoi_hex(&(arr[p.x][i + 1]));
	if (p.x == 0 && p.y == 0)
	{
		map_info->min_z = map_info->matrix[p.y][p.x].z;
		map_info->max_z = map_info->matrix[p.y][p.x].z;
	}
}

void		fdf_init_map_matrix(t_mlx *mlx, t_map *map_info)
{
	char	**arr;
	t_point	p;

	MALL_CHECK((map_info->matrix = (t_point **)malloc(
			sizeof(t_point *) * (map_info->height))));
	p.y = -1;
	while (++p.y < map_info->height)
	{
		p.x = -1;
		MALL_CHECK((arr = ft_strsplit(map_info->map[p.y], ' ')));
		MALL_CHECK((map_info->matrix[p.y] = (t_point *)malloc(
				sizeof(t_point) * (map_info->width))));
		while (++p.x < map_info->width)
		{
			fdf_save_map_point(mlx, map_info, p, arr);
			if (map_info->min_z > map_info->matrix[p.y][p.x].z)
				map_info->min_z = map_info->matrix[p.y][p.x].z;
			if (map_info->max_z < map_info->matrix[p.y][p.x].z)
				map_info->max_z = map_info->matrix[p.y][p.x].z;
		}
		ft_free_2arr(arr);
	}
	fdf_map_point_colors(map_info, 0);
	fdf_init_result_matrix(mlx, map_info);
}
