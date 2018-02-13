/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 14:34:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/02/13 14:34:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_color_scheme(int key, t_all *info)
{
	info->map->bot_color = 0x4cad41;
	info->map->top_color = 0x93147a;
	if (key == 18)
	{
		info->map->bot_color = 0xFF0000;
		info->map->top_color = 0x00FF00;
	}
	else if (key == 19)
	{
		info->map->bot_color = 0x7a098c;
		info->map->top_color = 0xbf3507;
	}
	else if (key == 20)
	{
		info->map->bot_color = 0xcec21c;
		info->map->top_color = 0x1889db;
	}
	else if (key == 21)
	{
		info->map->bot_color = 0xb71807;
		info->map->top_color = 0x0745c1;
	}
	fdf_map_point_colors(info->map, 1);
}

void	hook_iso_projection(int key, t_all *info)
{
	if (key == 86)
	{
		info->map->move_x = 0;
		info->map->move_y = 0;
		info->map->rot_z = 0;
		info->map->rot_y = -M_PI_4;
		info->map->rot_x = 0;
		fdf_rot_x_change(-35, info->map);
	}
}

void	hook_projection(int key, t_all *info)
{
	if (key == 83)
	{
		info->map->move_x = 0;
		info->map->move_y = 0;
		info->map->rot_z = 0;
		info->map->rot_x = 0;
		info->map->rot_y = 0;
	}
	else if (key == 84)
	{
		info->map->move_x = 0;
		info->map->move_y = 0;
		info->map->rot_z = 0;
		info->map->rot_x = -M_PI_2;
		info->map->rot_y = 0;
	}
	else if (key == 85)
	{
		info->map->move_x = 0;
		info->map->move_y = 0;
		info->map->rot_z = 0;
		info->map->rot_x = -M_PI_2;
		info->map->rot_y = -M_PI_2;
	}
	hook_iso_projection(key, info);
}
