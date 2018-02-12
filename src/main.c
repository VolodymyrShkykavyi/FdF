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
	t_mlx	*mlx_info;
	t_map	map_info;

	if (argc == 1)
	{
		ft_printf("Usage : %s <filename>\n", argv[0]);
		return (0);
	}
	//map_info.line_len = 20;
	map_info.bot_color = 0x4f3207; //brown
	map_info.top_color = 0xffffff;
	if (argc == 4)
	{
		map_info.bot_color = ft_atoi_hex(argv[2]);
		map_info.top_color = ft_atoi_hex(argv[3]);
	}
	map_info.move_x = 0;
	map_info.move_y = 0;
	mlx_info = init_mlx_and_img(1024, 768, "FdF");
	//read map and save it
	fdf_read_map(argv, &map_info);
	fdf_init_map_matrix(mlx_info, &map_info);
	map_info.line_len = mlx_info->height * 4 / (6 * map_info.height);
	map_info.line_len = (map_info.line_len > 35) ? 35 : map_info.line_len;
	fdf_get_result_map(&map_info);
	fdf_draw_map(&map_info, mlx_info);

	fdf_run_hooks(mlx_info, &map_info);
	//printf("before loop\n");
	mlx_string_put(mlx_info->mlx_ptr, mlx_info->win_ptr, 50, 700, 0xFF0000, "iADFSDF");
	mlx_loop(mlx_info->mlx_ptr);
	return (0);
}
