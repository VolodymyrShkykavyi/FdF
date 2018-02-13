/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 03:25:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/02/11 03:25:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fdf_rot_x_change(int degree, t_map *map_info)
{
	map_info->rot_x += degree * M_PI / 180;
}

void	fdf_rot_y_change(int degree, t_map *map_info)
{
	map_info->rot_y += degree * M_PI / 180;
}

void	fdf_rot_z_change(int degree, t_map *map_info)
{
	map_info->rot_z += degree * M_PI / 180;
}
