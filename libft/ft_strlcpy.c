/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheresi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 23:28:45 by ltheresi          #+#    #+#             */
/*   Updated: 2020/05/03 16:03:16 by ltheresi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t len;

	len = 0;
	while (src[len])
		len++;
	if (dstsize)
	{
		while (dstsize - 1 && *src)
		{
			*dst++ = *src++;
			dstsize--;
		}
		*dst = '\0';
	}
	return (len);
}
