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

	MALL_CHECK(map_info->matrix = (t_point **)malloc(
			sizeof(t_point *) * (map_info->height + 1)))
	MALL_CHECK(map_info->result = (t_point **)malloc(
			sizeof(t_point *) * (map_info->height + 1)))
	map_info->matrix[map_info->height] = NULL;
	map_info->result[map_info->height] = NULL;
	i = -1;
	while (++i < map_info->height)
	{
		j = -1;
		MALL_CHECK(arr = ft_strsplit(map_info->map[i]));
		while (++j < map_info->width)
		{
			MALL_CHECK(map_info->matrix[i] = (t_point *)malloc(
					sizeof(t_point) * (map_info->width + 1)))
			MALL_CHECK(map_info->result[i] = (t_point *)malloc(
					sizeof(t_point) * (map_info->width + 1)))
			map_info->matrix[i][map_info->width] = NULL;
			map_info->result[i][map_info->width] = NULL;
			MALL_CHECK((arr[j]) || (j + 1 == map_info->width && arr[j + 1]))
			map_info->matrix[i][j].x = j;
			map_info->result[i][j].x = j;
			map_info->matrix[i][j].y = i;
			map_info->result[i][j].y = i;
			map_info->matrix[i][j].z = ft_atoi(arr[j]);
			map_info->matrix[i][j].z = map_info->matrix[i][j].z;
			map_info->matrix[i][j].color = 0x12FF00;
			map_info->result[i][j].color = 0x12FF00;
		}
		ft_free_2arr(arr);
	}
}
