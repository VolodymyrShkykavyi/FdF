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

#include "../../includes/fdf.h"


#include <stdio.h>

void 	draw_straight_line(t_mlx *mlx, t_point p1, t_point p2, int color)
{
	t_line	line;

	fdf_init_lineparams(&line, &p1, &p2);
	while (p1.x != p2.x && p1.y != p2.y)
	{
		put_pixel_to_img(&mlx->img, p1.x, p1.y, color);
		p1.x += line.dirx;
		p1.y += line.diry;
	}
	put_pixel_to_img(&mlx->img, p2.x, p2.y, color);
}

void	draw_bresenham_line(t_mlx *mlx, t_point p1, t_point p2, int color)
{
	int 	error;
	t_line	line;

	fdf_init_lineparams(&line, &p1, &p2);
	error = line.dx - line.dy;
	while (p1.x != p2.x || p1.y != p2.y)
	{
		put_pixel_to_img(&mlx->img, p1.x, p1.y, color);
		if (error * 2 > -line.dy)
		{
			error -= line.dy;
			p1.x += line.dirx;
		}
		if (error * 2 < line.dx)
		{
			error += line.dx;
			p1.y += line.diry;
		}
	}
	put_pixel_to_img(&mlx->img, p2.x, p2.y, color);
}

/*
void	draw_wu_line(t_mlx *mlx, t_point p1, t_point p2)
{
	int		dx;
	int		dy;
	float	gradient;
	float	iter;
	int 	opacity;

	dx = ft_abs(p1.x - p2.x);
	dy = ft_abs(p1.y - p2.y);
	printf("dx %i, dy %i\n", dx, dy);
	if (dx == 0 || dy == 0)
		draw_straight_line(mlx, p1, p2, p1.color);
	if (dx > dy)
	{
		printf("draw wu line: dx > dy\n");
		if (p1.x > p2.x)
			swap_points(&p1, &p2);
		gradient = ((float)dy) / dx;
		printf("gradient %f\n", gradient);
		iter = p1.y + gradient;
		put_pixel_to_img(&mlx->img, p1.x, p1.y, p1.color);
		while (++p1.x < p2.x)
		{
			printf("in while p1.x = %d  alpha1 = %x alpa2 = %x iter = %f int iter = %i\n", p1.x,fdf_change_alpha_in_argb(p1.color,
											 255 * (1 - get_fraction(iter))),
				   fdf_change_alpha_in_argb(p1.color, 255 * get_fraction(iter)), iter, (int)iter);

			opacity = 0xFF * get_fraction(iter);
			put_pixel_to_img(&mlx->img, p1.x, nearbyint(iter),
							fdf_change_alpha_in_argb(p1.color, 0xFF - opacity));
			put_pixel_to_img(&mlx->img, p1.x, nearbyint(iter) + 1,
							fdf_change_alpha_in_argb(p1.color, opacity));



							 iter += gradient;
		}
		put_pixel_to_img(&mlx->img, p2.x, p2.y, p2.color);
	}
	else
	{
		printf("draw wu line: dx < dy\n");
		if (p1.y > p2.y)
			swap_points(&p1, &p2);
		gradient = (float)dx / dy;
		iter = p1.x + gradient;
		put_pixel_to_img(&mlx->img, p1.x, p1.y, p1.color);
		while (++p1.y < p2.y)
		{
			put_pixel_to_img(&mlx->img, (int)iter, p1.y,
							fdf_change_alpha_in_argb(p1.color,
										255 - 255 * get_fraction(iter)));
			put_pixel_to_img(&mlx->img, (int)iter + 1, p1.y,
							 fdf_change_alpha_in_argb(p1.color,
													  255 * get_fraction(iter)));
			iter += gradient;
		}
		put_pixel_to_img(&mlx->img, p2.x, p2.y, p2.color);
	}
}
*/
