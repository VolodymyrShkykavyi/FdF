/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_get_result_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 18:44:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/02/11 18:44:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	fdf_zoom_map(t_map *map_info)
{
	int		i;
	int		j;

	i = -1;
	while (++i < map_info->height)
	{
		j = -1;
		while (++j < map_info->width)
		{
			map_info->result[i][j].x = map_info->matrix[i][j].x *
					map_info->line_len;
			map_info->result[i][j].y = map_info->matrix[i][j].y *
					map_info->line_len;
			map_info->result[i][j].z = map_info->matrix[i][j].z *
					map_info->line_len;
			map_info->result[i][j].color = map_info->matrix[i][j].color;
		}
	}
}

static void	fdf_rotate_map_set_tmpcord(t_point *p, int *x, int *y, int *z)
{
	*x = p->x;
	*y = p->y;
	*z = p->z;
}

/*
** rotate map:
** 1. around OX
** 2. around OY
** 3. around OZ
*/

static void	fdf_rotate_map(t_map *map)
{
	int		x;
	int		y;
	int		z;
	int		i;
	int		j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			fdf_rotate_map_set_tmpcord(&(map->result[i][j]), &x, &y, &z);
			map->result[i][j].y = y * cos(map->rot_x) + z * sin(map->rot_x);
			map->result[i][j].z = -y * sin(map->rot_x) + z * cos(map->rot_x);
			fdf_rotate_map_set_tmpcord(&(map->result[i][j]), &x, &y, &z);
			map->result[i][j].x = x * cos(map->rot_y) + z * sin(map->rot_y);
			map->result[i][j].z = -x * sin(map->rot_y) + z * cos(map->rot_y);
			fdf_rotate_map_set_tmpcord(&(map->result[i][j]), &x, &y, &z);
			map->result[i][j].x = x * cos(map->rot_z) - y * sin(map->rot_z);
			map->result[i][j].y = x * sin(map->rot_z) + y * cos(map->rot_z);
		}
	}
}

void		fdf_move_map(t_map *map_info)
{
	int		i;
	int		j;

	i = -1;
	while (++i < map_info->height)
	{
		j = -1;
		while (++j < map_info->width)
		{
			map_info->result[i][j].x += map_info->offset_x + map_info->move_x;
			map_info->result[i][j].y += map_info->offset_y + map_info->move_y;
		}
	}
}

void		fdf_get_result_map(t_map *map_info)
{
	fdf_zoom_map(map_info);
	fdf_rotate_map(map_info);
	fdf_move_map(map_info);
}
