/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init_map_matrix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 02:55:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/02/11 02:55:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		fdf_init_map_matrix(t_map *map_info)
{
	char	**arr;
	int 	i;
	int 	j;
	t_point tmp;

	MALL_CHECK(map_info->matrix = (t_point **)malloc(
			sizeof(t_point *) * (map_info->height + 1)))
	map_info->matrix[map_info->height] = NULL;
	i = -1;
	while (++i < map_info->height)
	{
		j = -1;
		if (!(arr = ft_strsplit(map_info->map[i])))
			exit(1);
		while (++j < map_info->width)
		{
			MALL_CHECK(map_info->matrix[i] = (t_point *)malloc(
					sizeof(t_point) * (map_info->width + 1)));
			if (!(arr[j]) || (j + 1 == map_info->width && arr[j + 1]))
				exit(0);
			tmp.x = j;
			tmp.y = i;
			tmp.z = ft_atoi(arr[j]);
			tmp.color = 0x12FF00;
			map_info->matrix[i][j] = tmp;
		}
	}
}
