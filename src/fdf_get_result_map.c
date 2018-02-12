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
	int 	j;

	i = -1;
	while (++i < map_info->height)
	{
		j = -1;
		while (++j < map_info->width)
		{
			map_info->result[i][j].x *= map_info->line_len;
			map_info->result[i][j].y *= map_info->line_len;
			map_info->result[i][j].z *= map_info->line_len;
		}
	}
}

static void	fdf_rotate_map(t_map *map_info)
{
	//yzx
	//https://studfiles.net/preview/985240/page:5/
	int		x;
	int 	y;
	int 	z;

	x = x * (cos(rot_z) * cos(rot_y)) + y * (cos(rot_x) * sin(rot_z) * cos(rot_y) + sin(rot_x) * sin(rot_y))
		+ z * (sin(rot_x) * sin(rot_z) * cos(rot_y) - cos(rot_x) * sin(rot_y));
	y = x * (-sin(rot_z)) + y * (cos(rot_x) * cos(rot_z)) + z * (sin(rot_x) * cos(rot_z));
	z = x *(cos(rot_z) * sin (rot_y)) + y * (cos(rot_x) * sin(rot_z) * sin(rot_y) - sin(rot_x) * cos(rot_y))
		+ z * (sin(rot_x) * sin(rot_y) * sin(rot_z) - cos(rot_x) * cos(rot_y));
}

static void	fdf_move_map(t_map *map_info)
{

}

void		fdf_get_result_map(t_map *map_info)
{
	fdf_zoom_map(map_info);
	fdf_rotate_map(map_info);
	fdf_move_map(map_info);
}
