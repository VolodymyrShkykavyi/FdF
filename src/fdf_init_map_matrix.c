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

#include "../includes/fdf.h"

static void	fdf_init_result_matrix(t_map *map_info)
{
	int 	i;
	int		j;

	MALL_CHECK((map_info->result = (t_point **)malloc(
			sizeof(t_point *) * (map_info->height))))

	i = -1;
	while (++i < map_info->height)
	{
		j = -1;
		MALL_CHECK((map_info->result[i] = (t_point *)malloc(
				sizeof(t_point) * map_info->width)))
		while (++j < map_info->width)
		{
			map_info->result[i][j].x = map_info->matrix[i][j].x;
			map_info->result[i][j].y = map_info->matrix[i][j].y;
			map_info->result[i][j].z = map_info->matrix[i][j].z;
			map_info->result[i][j].color = map_info->matrix[i][j].color;
		}
	}
}

static void	fdf_save_map_point(t_mlx *mlx, t_map *map_info, t_point p, char **arr)
{
	int offset_x;
	int offset_y;
	int i;

	offset_x = map_info->width / 2;
	offset_y = map_info->height / 2;
	map_info->matrix[p.y][p.x].x = p.x - offset_x;
	map_info->matrix[p.y][p.x].y = p.y - offset_y;
	map_info->matrix[p.y][p.x].z = ft_atoi(arr[p.x]);
	i = 0;
	while (ft_isdigit(arr[p.x][i]))
		i++;
	if (arr[p.x][i] == '\0')
		map_info->matrix[p.y][p.x].color = -1;
	else if (arr[p.x][i] != ',')
	{
		ft_putstr("not a valid map\n");
		exit(2);
	}
	else
	{
		map_info->matrix[p.y][p.x].color = ft_atoi_hex(&(arr[p.x][i + 1]));
		//printf("input: %s  color in int: %i, hex %x\n", &(arr[p.x][i + 1]), map_info->matrix[p.y][p.x].color, map_info->matrix[p.y][p.x].color);
	}
}

static void	fdf_map_point_colors(t_map *map_info, int min_z, int max_z)
{
	int 		i;
	int 		j;
	t_gradient	grad;
	t_point		p1;
	t_point		p2;

	i = -1;
	p1.x = 0;
	p2.x = 0;
	p1.y = min_z;
	p2.y = max_z;
	p1.color = map_info->bot_color;
	p2.color = map_info->top_color;
	fdf_init_gradientparams(&grad, p1, p2);
	while (++i < map_info->height)
	{
		j = -1;
		while (++j < map_info->width)
			if (map_info->matrix[i][j].color == -1)
				map_info->matrix[i][j].color = rgb_get_color(
						grad.r + grad.dr * (map_info->matrix[i][j].z - min_z),
						grad.g + grad.dg * (map_info->matrix[i][j].z - min_z),
						grad.b + grad.db * (map_info->matrix[i][j].z - min_z));
	}
}

void		fdf_init_map_matrix(t_mlx *mlx, t_map *map_info)
{
	char	**arr;
	t_point	p;
	int 	min_z;
	int 	max_z;

	MALL_CHECK((map_info->matrix = (t_point **)malloc(
			sizeof(t_point *) * (map_info->height))))
	p.y = -1;
	while (++p.y < map_info->height)
	{
		p.x = -1;
		MALL_CHECK((arr = ft_strsplit(map_info->map[p.y], ' ')))
		MALL_CHECK((map_info->matrix[p.y] = (t_point *)malloc(
				sizeof(t_point) * (map_info->width))))
		while (++p.x < map_info->width)
		{
			fdf_save_map_point(mlx, map_info, p, arr);
			if (min_z > map_info->matrix[p.y][p.x].z || (p.x == 0 && p.y == 0))
				min_z = map_info->matrix[p.y][p.x].z;
			if (max_z < map_info->matrix[p.y][p.x].z || (p.x == 0 && p.y == 0))
				max_z = map_info->matrix[p.y][p.x].z;
		}
		ft_free_2arr(arr);
	}
	fdf_map_point_colors(map_info, min_z, max_z);
	fdf_init_result_matrix(map_info);
}
