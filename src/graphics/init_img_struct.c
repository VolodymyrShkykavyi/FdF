/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 17:34:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/02/07 17:34:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_mlx_image.h"

void	init_img_struct(t_mlx *mlx, int width,  int height)
{
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, width, height);
	mlx->img.img_data = (unsigned int *)mlx_get_data_addr(mlx->img.img_ptr,
												&mlx->img.bpp,
												&mlx->img.size_line,
												&mlx->img.endian);
}
