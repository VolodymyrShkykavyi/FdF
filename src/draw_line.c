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

void 	draw_straight_line(t_point p1, t_point p2, void *mlx_ptr,
						   void *win_ptr)
{
	t_point	tmp;

	if (p1.x > p2.x || p1.y > p2.y)
	{
		tmp = p1;
		p1 = p2;
		p2 = tmp;
	}
	while (p1.x <= p2.x)
		mlx_pixel_put(mlx_ptr, win_ptr, p1.x++, p1.y, p1.color);
	while (p1.y <= p2.y)
		mlx_pixel_put(mlx_ptr, win_ptr, p1.x, p1.y++, p1.color);
}

void	draw_wu_line(t_point p1, t_point p2, void *mlx_ptr, void *win_ptr)
{
	int		dx;
	int		dy;

	dx = ABS(p1.x - p2.x);
	dy = ABS(p1.y - p2.y);
	if (dx == 0 || dy == 0)
		draw_straight_line(p1, p2, mlx_ptr, win_ptr);
}
