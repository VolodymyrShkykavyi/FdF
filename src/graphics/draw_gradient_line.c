/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_gradient_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 11:39:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/02/09 11:39:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	draw_gradient_straight_line(t_mlx *mlx, t_point p1, t_point p2)
{
	t_line		line;
	t_gradient	grad;

	if ((p1.x == p2.x && p1.y == p2.y) || p1.color == p2.color)
	{
		draw_straight_line(mlx, p1, p2, p1.color);
		return ;
	}
	fdf_init_lineparams(&line, &p1, &p2);
	fdf_init_gradientparams(&grad, &p1, &p2);
	while (p1.x != p2.x || p1.y != p2.y)
	{
		put_pixel_to_img(&mlx->img, p1.x, p1.y, p1.color);
		p1.x += line.dirx;
		p1.y += line.diry;
		p1.color = fdf_getnext_color_gradient(&grad);
	}
	put_pixel_to_img(&mlx->img, p2.x, p2.y, p2.color);
}

void	draw_gradient_bresenham_line(t_mlx *mlx, t_point p1, t_point p2)
{
	int 		error;
	t_gradient	grad;
	t_line		line;

	fdf_init_lineparams(&line, &p1,&p2);
	fdf_init_gradientparams(&grad, &p1, &p2);
	error = line.dx - line.dy;
	while (p1.x != p2.x || p1.y != p2.y)
	{
		if (p1.x < mlx->width && p1.y < mlx->height)
			put_pixel_to_img(&mlx->img, p1.x, p1.y, p1.color);
		if (error * 2 > -line.dy && p1.x != p2.x)
		{
			error -= line.dy;
			p1.x += line.dirx;
		}
		if (error * 2 < line.dx && p1.y != p2.y)
		{
			error += line.dx;
			p1.y += line.diry;
		}
		p1.color = fdf_getnext_color_gradient(&grad);
	}
	put_pixel_to_img(&mlx->img, p2.x, p2.y, p2.color);
}
