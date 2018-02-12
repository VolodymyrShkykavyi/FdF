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

int 	pressed_key(int key, t_map *map)
{
	printf("pressed key = %i\n", key);
	if (key == 53)
		exit(0);
	return (0);

}

int		realezed_key(int key, t_map *map)
{
	if (key == -1) //C -center map
	{
		map->move_x = 0;
		map->move_y = 0;
		//rotate
	}
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

void	fdf_run_hooks(void *win_ptr, t_map *map)
{
	mlx_mouse_hook(win_ptr, &mouse_click, NULL);
	mlx_key_hook(win_ptr, &realezed_key, map);
	mlx_hook(win_ptr, 17, 0, &close_hook, NULL);
	mlx_hook(win_ptr, 2, 3, &pressed_key, map);
}