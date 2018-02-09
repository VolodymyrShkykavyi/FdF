/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 12:03:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/02/09 12:03:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fdf_init_lineparams(t_line *line, t_point *p1, t_point *p2)
{
	if (!line || !p1 || !p2)
		return ;
	line->dx = ft_abs(p1->x - p2->x);
	line->dy = ft_abs(p1->y - p2->y);
	line->dirx = (p1->x < p2->x) ? 1 : -1;
	line->dirx = (p1->x == p2->x) ? 0 : line->dirx;
	line->diry = (p1->y < p2->y) ? 1 : -1;
	line->diry = (p1->y == p2->y) ? 0 : line->diry;
}

void	fdf_init_gradientparams(t_gradient *grad, t_point *p1, t_point *p2)
{
	int 	len;

	grad->r = rgb_get_rvalue(p1->color);
	grad->g = rgb_get_gvalue(p1->color);
	grad->b = rgb_get_bvalue(p1->color);
	len = sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2));
	grad->dr = (rgb_get_rvalue(p2->color) - grad->r) / len;
	grad->dg = (rgb_get_gvalue(p2->color) - grad->g) / len;
	grad->db = (rgb_get_bvalue(p2->color) - grad->b) / len;
}

int 	fdf_getnext_color_gradient(t_gradient *grad)
{
	int 	color;

	grad->r += grad->dr;
	grad->g += grad->dg;
	grad->b += grad->db;
	color = rgb_get_color(grad->r, grad->g, grad->b);
	return (color);
}