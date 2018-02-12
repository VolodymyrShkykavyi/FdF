/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 13:52:11 by vshkykav          #+#    #+#             */
/*   Updated: 2018/02/07 13:52:13 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <printf.h>
#include "../includes/fdf.h"
#include "../includes/ft_mlx_image.h"




int 	main(int argc, char **argv)
{

	int		i;
	t_mlx	*mlx_info;
	t_map	map_info;
	t_point	p1;
	t_point	p2;

	if (argc == 1)
	{
		ft_printf("Usage : %s <filename>\n", argv[0]);
		return (0);
	}

	mlx_info = init_mlx_and_img(800, 600, "FdF");
	fdf_run_hooks(mlx_info->win_ptr);
	//read map and save it
	fdf_read_map(argv, &map_info);
	map_info.line_len = 20;
	map_info.bot_color = 0x4f3207; //brown
	map_info.top_color = 0xffffff;
	map_info.move_x = 0;
	map_info.move_y = 0;
	//ft_printarr(map_info.map);
	//printf("res of read map %i\n", fdf_read_map(argv, &map_info));
	//translate map into matrix
	fdf_init_map_matrix(mlx_info, &map_info);
	fdf_get_result_map(&map_info);
	fdf_draw_map(&map_info, mlx_info);

	i = 0;
	/*while (++i < 300)
		put_pixel_to_img(&(mlx_info->img), i, 70, 0x00ffff);
	i = 0;
	while (++i < 300)
		put_pixel_to_img(&(mlx_info->img), i, 75, 0x00ffff);*/
//	p1.x = 50;
//	p1.y = 50;
//	p2.x = 450;
//	p2.y = 100;
//	p1.color = 0xFFFFFF;
//	p2.color = 0xFF0000;
//	draw_gradient_bresenham_line(mlx_info, p1, p2);

	mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr, mlx_info->img.img_ptr, 0, 0);
	mlx_loop(mlx_info->mlx_ptr);
	return (0);
}
