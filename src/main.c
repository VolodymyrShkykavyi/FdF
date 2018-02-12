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
#include "fdf.h"

static void	fdf_init_map_properties(int argc, char **argv, t_map *map_info)
{
	if (argc == 4)
	{
		map_info->bot_color = ft_atoi_hex(argv[2]);
		map_info->top_color = ft_atoi_hex(argv[3]);
	}
	else
	{
		map_info->bot_color = 0x4f3207;
		map_info->top_color = 0xffffff;
	}
	map_info->move_x = 0;
	map_info->move_y = 0;
	map_info->line_len = mlx_info->height * 4 / (6 * map_info.height) + 1;
	map_info->line_len = (map_info.line_len > 35) ? 35 : map_info.line_len;
}

int 	main(int argc, char **argv)
{
	t_mlx	*mlx_info;
	t_map	map_info;

	if (argc == 1)
	{
		ft_printf("Usage : %s <filename>\n", argv[0]);
		return (0);
	}
	mlx_info = init_mlx_and_img(1024, 768, "FdF");
	fdf_read_map(argv, &map_info);
	fdf_init_map_properties(argc, argv, &map_info);
	fdf_init_map_matrix(mlx_info, &map_info);
	fdf_get_result_map(&map_info);
	fdf_draw_map(&map_info, mlx_info);
	fdf_run_hooks(mlx_info, &map_info);
	mlx_loop(mlx_info->mlx_ptr);
	return (0);
}
