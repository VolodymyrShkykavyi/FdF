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
#include <stdlib.h>

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

int 	pressed_key(int key)
{
	printf("key = %i\n", key);
	if (key == 53)
		exit(0);
	return (0);

}

int		mouse_click(int btn, int x, int y)
{

	printf("mouse: btn: %i x = %i y = %i\n", btn, x, y);
	if (x >= 5 && x <= 20 && y <= -3)
		exit (0);
	return (0);
}

int 	close_hook()
{
	printf("pressed close button\n");
	exit(0);
}

void	fdf_run_hooks(void *win_ptr)
{
	mlx_mouse_hook(win_ptr, &mouse_click, NULL);
	mlx_key_hook(win_ptr, &pressed_key, NULL);
	mlx_hook(win_ptr, 17, 0, &close_hook, NULL);
}