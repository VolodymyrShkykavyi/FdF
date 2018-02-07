/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 21:25:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/02/07 21:25:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	swap_points(t_point *p1, t_point *p2)
{
	t_point		tmp;
	/*int		tmp;

	tmp = p1->x;
	p1->x = p2->x;
	p2->x = tmp;
	tmp = p1->y;
	p1->y = p2->y;
	p2->y = tmp;
	tmp = p1->z;
	p1->z = p2->z;
	p2->z = tmp;
	tmp = p1->color;
	p1->color = p2->color;
	p2->color = p1->color;*/
	tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}