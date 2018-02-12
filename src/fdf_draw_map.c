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
	ft_bzero(mlx->img.img_data, (size_t)mlx->height * mlx->width * 4);
	while (++i < map_info->height)
	{
		j = -1;
		while (++j < map_info->width)
		{
			if (j + 1 < map_info->width)
			{
				draw_gradient_bresenham_line(mlx, map_info->result[i][j],
											map_info->result[i][j + 1]);
			}
			if (i + 1 < map_info->height)
				draw_gradient_bresenham_line(mlx, map_info->result[i][j],
											map_info->result[i + 1][j]);
		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img_ptr, 0, 0);
	printf("draw map end\n");
}
