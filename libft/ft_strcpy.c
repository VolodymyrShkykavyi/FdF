/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshkykav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 15:22:58 by vshkykav          #+#    #+#             */
/*   Updated: 2017/10/28 19:14:35 by vshkykav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dst, const char *src)
{
	char *start;

	start = dst;
	while (*src)
		*(dst++) = *(src++);
	*dst = '\0';
	return (start);
}
