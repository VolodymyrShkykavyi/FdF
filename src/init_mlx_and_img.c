/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_and_img.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 18:03:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/02/07 18:03:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_mlx_image.h"
#include "stdlib.h"

t_mlx	*init_mlx_and_img(int width, int height, char *title)
{
	t_mlx	*mlx_info;

	mlx_info =  (t_mlx *)malloc(sizeof(t_mlx));
	mlx_info->mlx_ptr = mlx_init();
	mlx_info->win_ptr = mlx_new_window(mlx_info->mlx_ptr, width, height, title);
	init_img_struct(mlx_info, width, height);
	return (mlx_info);
}