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

# define MALL_CHECK(x) if(!x) exit(1);
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
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
	t_point		**matrix;
	t_point		**result;
	int			line_len;
	int			width;
	int 		height;
	int			bot_color;
	int 		top_color;
	int			rotate_ox;
	int 		rotate_oy;
	int 		rotate_oz;
}				t_map;

typedef struct	s_line
{
	int 		dx;
	int 		dy;
	int			dirx;
	int 		diry;
}				t_line;

typedef struct	s_gradient
{
	float 		r;
	float 		g;
	float 		b;
	float 		dr;
	float 		dg;
	float 		db;
}				t_gradient;

void			draw_straight_line(t_mlx *mlx, t_point p1, t_point p2,
								   int color);
void			draw_bresenham_line(t_mlx *mlx, t_point p1, t_point p2,
									int color);
void			swap_points(t_point *p1, t_point *p2);
float			get_fraction(float num);
void			fdf_run_hooks(void *win_ptr);
int				fdf_read_map(char **argv, t_map *map_info);

void			fdf_init_lineparams(t_line *line, t_point *p1, t_point *p2);
void			fdf_init_gradientparams(t_gradient *grad, t_point *p1, t_point *p2);


unsigned char	rgb_get_bvalue(int color);
int				rgb_get_color(int r, int g, int b);
unsigned char	rgb_get_gvalue(int color);
unsigned char	rgb_get_rvalue(int color);
int 			fdf_getnext_color_gradient(t_gradient *grad);
void			draw_gradient_straight_line(t_mlx *mlx, t_point p1, t_point p2);
void			draw_gradient_bresenham_line(t_mlx *mlx, t_point p1, t_point p2);
void	fdf_draw_map(t_map *map_info, t_mlx *mlx);
int		fdf_init_map_matrix(t_mlx *mlx, t_map *map_info);
#endif