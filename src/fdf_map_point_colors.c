/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_point_colors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 23:19:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/02/12 23:19:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** set gradient colors for map from bottom to top
** if reset_flag set to 1 - reset all saved color to new
*/

void	fdf_map_point_colors(t_map *map_info, int reset_flag)
{
	int			i;
	int			j;
	t_gradient	grad;
	t_point		p1;
	t_point		p2;

	i = -1;
	p1.x = 0;
	p2.x = 0;
	p1.y = map_info->min_z;
	p2.y = map_info->max_z;
	p1.color = map_info->bot_color;
	p2.color = map_info->top_color;
	fdf_init_gradientparams(&grad, &p1, &p2);
	while (++i < map_info->height)
	{
		j = -1;
		while (++j < map_info->width)
			if (map_info->matrix[i][j].color == -1 || reset_flag == 1)
				map_info->matrix[i][j].color = rgb_get_color(
						grad.r + grad.dr * (map_info->matrix[i][j].z - p1.y),
						grad.g + grad.dg * (map_info->matrix[i][j].z - p1.y),
						grad.b + grad.db * (map_info->matrix[i][j].z - p1.y));
	}
}
