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
#include <stdlib.h>
#include <printf.h>
#include "../includes/fdf.h"
#include "../includes/ft_mlx_image.h"

/*
** key code:
** 53 - esc
*/

int 	pressed_key(int key, void *param)
{
	printf("key = %i\n", key);
	if (key == 53)
		exit(0);
	if (param)
		printf("hi %s\n", (char *)param);
	return (0);

}

int		mouse_click(int btn, int x, int y, void *param)
{

	printf("mouse: btn: %i x = %i y = %i", btn, x, y);
	if (param)
		printf("hi %s\n", (char *)param);
	if (x >= 5 && x <= 20 && y <= -3)
		exit (0);
	return (0);
}


int 	main(void)
{

	int		i;
	t_mlx	*mlx_info;

	i = 0;
	mlx_info = init_mlx_and_img(500, 300, "my title");
	while (++i < 100)
		put_pixel_to_img(&(mlx_info->img), i, 30, 0xFF00FF);
	mlx_mouse_hook(mlx_info->win_ptr, &mouse_click, NULL);
	mlx_key_hook(mlx_info->win_ptr, &pressed_key, NULL);

	mlx_put_image_to_window(mlx_info->mlx_ptr, mlx_info->win_ptr, mlx_info->img.img_ptr, 10, 30);
	mlx_loop(mlx_info->mlx_ptr);
	return (0);
}
