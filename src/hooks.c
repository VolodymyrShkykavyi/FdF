/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 20:05:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/02/08 20:05:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** key code:
** 53 - esc
**
** event:
** 2 - KeyPress
** 3 - KeyRelease
** 4 - ButtonPress
** 5 - ButtonRelease
** 17 - DestroyNotify
*/

void	fdf_set_move_info(int key, t_all *info)
{
	if (key == 126)
		info->map->move_y -= 5;
	else if (key == 125)
		info->map->move_y += 5;
	else if (key == 123)
		info->map->move_x -= 5;
	else if (key == 124)
		info->map->move_x += 5;
}

void	hook_rotate(int key, t_all *info)
{
	if (key == 13)
		fdf_rot_x_change(-5, info->map);
	else if (key == 1)
		fdf_rot_x_change(5, info->map);
	else if (key == 0)
		fdf_rot_y_change(-5, info->map);
	else if (key == 2)
		fdf_rot_y_change(5, info->map);
	else if (key == 12)
		fdf_rot_z_change(-5, info->map);
	else if (key == 14)
		fdf_rot_z_change(5, info->map);
	else if (key == 8)
	{
		info->map->move_x = 0;
		info->map->move_y = 0;
	}
	else if (key == 15)
	{
		info->map->move_x = 0;
		info->map->move_y = 0;
		info->map->rot_z = 0;
		info->map->rot_x = 0;
		info->map->rot_y = 0;
		info->map->line_len = info->map->start_line_len;
	}
}

int		hook_close(void)
{
	exit(0);
}

int		pressed_key(int key, t_all *info)
{
	if (key == 53)
		exit(0);
	if (key >= 123 && key <= 126)
		fdf_set_move_info(key, info);
	if (key == 48)
		info->show_control = (info->show_control) ? 0 : 1;
	else if (key == 69)
	{
		if (info->mlx->height / 6 > info->map->line_len)
			info->map->line_len += 3;
	}
	else if (key == 78)
	{
		if (info->map->line_len > 3)
			info->map->line_len -= 3;
	}
	else if ((key >= 18 && key <= 21) || key == 23)
		change_color_scheme(key, info);
	else if (key >= 83 && key <= 86)
		hook_projection(key, info);
	else
		hook_rotate(key, info);
	fdf_get_result_map(info->map);
	fdf_draw_map(info->map, info->mlx, info->show_control);
	return (0);
}

void	fdf_run_hooks(t_mlx *mlx, t_map *map)
{
	static t_all	info;

	info.map = map;
	info.mlx = mlx;
	info.show_control = 0;
	mlx_hook(mlx->win_ptr, 17, 0, &hook_close, NULL);
	mlx_hook(mlx->win_ptr, 2, 3, &pressed_key, &info);
}
