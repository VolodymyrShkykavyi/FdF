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
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_point;

typedef struct	s_map
{
	char		**map;
	int			width;
	int 		height;
	t_point		center;
}				t_map;

void			draw_straight_line(t_mlx *mlx, t_point p1, t_point p2,
								   int color);
void			draw_bresenham_line(t_mlx *mlx, t_point p1, t_point p2);
void			swap_points(t_point *p1, t_point *p2);
int				fdf_change_alpha_in_argb(int color, int alpha);
int				fdf_get_argb(int a, int r, int g, int b);
float			get_fraction(float num);
void			fdf_run_hooks(void *win_ptr);
int		fdf_read_map(char **argv, t_map *map_info);
#endif