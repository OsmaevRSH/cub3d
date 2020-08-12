/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheresi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 15:41:33 by ltheresi          #+#    #+#             */
/*   Updated: 2020/05/03 16:01:40 by ltheresi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *destination, const void *source, int c, size_t n)
{
	unsigned char *tmp_dest;
	unsigned char *tmp_src;
	unsigned char tmp_c;

	tmp_dest = (unsigned char *)destination;
	tmp_src = (unsigned char *)source;
	tmp_c = (unsigned char)c;
	if (!tmp_src && !tmp_dest)
	{
		return (destination);
	}
	while (n--)
	{
		*tmp_dest = *tmp_src;
		if (*tmp_dest == (unsigned char)tmp_c)
			return (++tmp_dest);
		tmp_dest++;
		tmp_src++;
	}
	return (0);
}
