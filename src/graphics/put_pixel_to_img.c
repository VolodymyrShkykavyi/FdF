/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_to_img.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 16:26:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/02/07 16:26:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_mlx_image.h"

void	put_pixel_to_img(t_img *img, int x, int y, int color)
{
	int		width;

	width = img->size_line / (img->bpp / 8);
	if (x < 0 || y < 0 || width <= 0)
		return ;
	if (!(img->img_ptr) || !(img->img_data))
		return ;
	if (color < 0)
		color = 0;
	if (x > img->size_line)
		return ;
	img->img_data[width * y + x] = color;
}
