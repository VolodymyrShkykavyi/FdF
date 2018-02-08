/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_change_alpha_in_argb.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 00:38:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/02/08 00:38:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		 fdf_change_alpha_in_argb(int color, int alpha)
{
	return ((color - (int)(color / 0xFFFFFF) * 0x01000000) + (/*0xFF - */alpha) * 0x01000000);
}