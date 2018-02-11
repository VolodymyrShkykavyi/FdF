/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <vshkykav@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 19:23:00 by vshkykav          #+#    #+#             */
/*   Updated: 2018/02/11 19:23:00 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi_hex(const char *str)
{
	unsigned long long int	res;

	res = 0;
	if (!str)
		return (0);
	if (*(str) == '0' && (*(str + 1) == 'x' || *(str + 1) == 'X'))
		str += 2;
	while ((*str >= '0' && *str <= '9') ||
			(ft_tolower(*str) >= 'a' && ft_tolower(*str) <= 'f'))
	{
		res *= 16;
		if (*str >= '0' && *str <= '9')
			res += *str - '0';
		else
			res += ft_tolower(*str) - 'a' + 10;
		str++;
	}
	return (res);
}
