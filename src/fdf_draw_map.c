/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 12:27:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/02/11 12:27:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fdf_draw_map(t_map *map_info, t_mlx *mlx)
{
	int 	i;
	int 	j;

	i = -1;
	while (map_info->result[++i])
	{
		j = -1;
		while (map_info->result[i][++j])
		{
			if (j + 1 < map_info->width)
				draw_gradient_bresenham_line(mlx, map_info->result[i][j],
											 map_info->result[i][j + 1]);
			if (i + 1 < map_info->height)
				draw_gradient_bresenham_line(mlx, map_info->result[i][j],
											 map_info->result[i + 1][j]);
		}
	}
}
