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
# include "ft_mlx_image.h"

# define ABS(x) ((x > 0) ? (x) : (-x))

/*
** 0xAARRGGBB - AA(alpha channel), RR(red), GG(green), BB(blue)
*/
typedef struct	s_point
{
	int			x;
	int			y;
	int			color;
}				t_point;


void			draw_straight_line(t_mlx *mlx, t_point p1, t_point p2,
								   int color);
void			draw_wu_line(t_mlx *mlx, t_point p1, t_point p2, int color);

#endif