/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheresi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 20:35:05 by ltheresi          #+#    #+#             */
/*   Updated: 2020/05/03 16:02:03 by ltheresi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmp_dst;
	unsigned char	*tmp_src;

	tmp_src = (unsigned char *)src;
	tmp_dst = (unsigned char *)dst;
	if (!tmp_src && !tmp_dst)
	{
		return (dst);
	}
	else if (tmp_src < tmp_dst)
	{
		tmp_dst += len - 1;
		tmp_src += len - 1;
		while (len--)
			*(tmp_dst--) = *(tmp_src--);
	}
	else
	{
		while (len--)
		{
			*(tmp_dst++) = *(tmp_src++);
		}
	}
	return (dst);
}
