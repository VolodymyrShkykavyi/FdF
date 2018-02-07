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
	t_point	tmp;

	if (p1.x > p2.x || p1.y > p2.y)
	{
		tmp = p1;
		p1 = p2;
		p2 = tmp;
	}
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

void	draw_wu_line(t_mlx *mlx, t_point p1, t_point p2, int color)
{
	int		dx;
	int		dy;
	t_point	tmp;

	dx = ABS(p1.x - p2.x);
	dy = ABS(p1.y - p2.y);
	if (dx == 0 || dy == 0)
		draw_straight_line(mlx, p1, p2, color);
	if (dx > dy)
	{
		if (p1.x > p2.x)
		{
			tmp = p1;
			p1 = p2;
			p2 = tmp;
		}
	}
	else
	{

	}
}
