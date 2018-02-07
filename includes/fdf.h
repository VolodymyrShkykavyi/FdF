/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:40:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/02/07 15:40:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# define ABS(x) ((x > 0) ? (x) : (-x))

typedef struct	s_point
{
	int			x;
	int			y;
	int			color;
}				t_point;


void 	draw_straight_line(t_point p1, t_point p2, void *mlx_ptr,
						   void *win_ptr);
#endif