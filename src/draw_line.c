/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:37:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/02/07 15:37:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void 	draw_straight_line(t_mlx *mlx, t_point p1, t_point p2, int color)
{
	if (p1.x > p2.x || p1.y > p2.y)
		swap_points(&p1, &p2);
	if (p1.y == p2.y)
	{
		while (p1.x <= p2.x)
			put_pixel_to_img(&mlx->img, p1.x++, p1.y, color);
	}
	else
	{
		while (p1.y <= p2.y)
			put_pixel_to_img(&mlx->img, p1.x, p1.y++, color);
	}
}

void	draw_wu_line(t_mlx *mlx, t_point p1, t_point p2)
{
	int		dx;
	int		dy;
	float	gradient;
	float	iter;

	dx = ABS(p1.x - p2.x);
	dy = ABS(p1.y - p2.y);
	if (dx == 0 || dy == 0)
		draw_straight_line(mlx, p1, p2, p1.color);
	if (dx > dy)
	{
		if (p1.x > p2.x)
			swap_points(&p1, &p2);
		gradient = (float)dy / dx;
		iter = p1.y + gradient;
		put_pixel_to_img(&mlx->img, p1.x, p1.y, p1.color);
		while (++p1.x < p2.x)
		{
			put_pixel_to_img(&mlx->img, p1.x, (int)iter,
							fdf_change_alpha_in_argb(p1.color,
										255 - 255 * get_fraction(iter)));
			put_pixel_to_img(&mlx->img, p1.x, (int)iter + 1,
							fdf_change_alpha_in_argb(p1.color,
										255 * get_fraction(iter)));
			iter += gradient;
		}
		put_pixel_to_img(&mlx->img, p2.x, p2.y, p2.color);
	}
	else
	{
		if (p1.y > p2.y)
			swap_points(&p1, &p2);
		gradient = (float)dx / dy;
		iter = p1.x + gradient;
		put_pixel_to_img(&mlx->img, p1.x, p1.y, p1.color);
		while (++p1.y < p2.y)
		{
			put_pixel_to_img(&mlx->img, (int)iter, p1.y,
							fdf_change_alpha_in_argb(p1.color),
										255 - 255 * get_fraction(iter));
			put_pixel_to_img(&mlx->img, (int)iter + 1, p1.y,
							 fdf_change_alpha_in_argb(p1.color,
													  255 * get_fraction(iter)));
			iter += gradient;
		}
		put_pixel_to_img(&mlx->img, p2.x, p2.y, p2.color);
	}
}
