/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheresi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 16:55:47 by ltheresi          #+#    #+#             */
/*   Updated: 2020/05/03 16:03:11 by ltheresi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	int		tmp_size;

	tmp_size = (int)dstsize;
	if (ft_strlen(dst) < dstsize)
		len = ft_strlen(src) + ft_strlen(dst);
	else
		len = ft_strlen(src) + dstsize;
	while (*dst)
	{
		dst++;
		tmp_size--;
	}
	if (tmp_size > 0)
	{
		while (tmp_size - 1 && *src)
		{
			*dst++ = *src++;
			tmp_size--;
		}
		*dst = '\0';
	}
	return (len);
}
