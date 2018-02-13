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

void	fdf_print_controls(t_map *map_info, t_mlx *mlx)
{
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 50, 650,
				0x889191, "rotate:");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 50, 670,
				0x889191, "  OX: w, s   OY: a, d  OZ: q, e");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 50, 690, 0x889191, "move:");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 50, 710, 0x889191,
				"  arrow keys");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 550, 650,
				0x889191, "projection:");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 550, 670,
				0x889191, "  parallel: NUM1, NUM2, NUM3");
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 550, 690,
				0x889191, "  isometric: NUM4");
}

void	fdf_draw_map(t_map *map_info, t_mlx *mlx, int controls)
{
	int		i;
	int		j;

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
	if (controls)
		fdf_print_controls(map_info, mlx);
}
