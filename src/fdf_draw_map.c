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
	//printf("start drawing\n");
	while (++i < map_info->height)
	{
		j = -1;
		while (++j < map_info->width)
		{
			if (j + 1 < map_info->width)
			{
				draw_gradient_bresenham_line(mlx, map_info->result[i][j],
											map_info->result[i][j + 1]);
//				printf("draw from(i:%d J:%d) x = %d y = %d to x = %d y = %d\n", i, j,map_info->matrix[i][j].x, map_info->matrix[i][j].y, map_info->matrix[i][j + 1].x, map_info->matrix[i][j + 1].y);

//				printf("res matrix y[%d] x[%d][z] = [%d][%d][%d]\n", i, j, map_info->matrix[i][j].y , map_info->matrix[i][j].x, map_info->matrix[i][j].z);

			}
			if (i + 1 < map_info->height)
				draw_gradient_bresenham_line(mlx, map_info->result[i][j],
											map_info->result[i + 1][j]);
		}
	}
	//printf("end drawing\n");
}
