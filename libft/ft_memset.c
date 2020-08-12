/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheresi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 13:50:40 by ltheresi          #+#    #+#             */
/*   Updated: 2020/05/03 16:02:11 by ltheresi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *tmp_dest;
	unsigned char tmp_c;

	tmp_dest = (unsigned char *)b;
	tmp_c = (unsigned char)c;
	while (len--)
	{
		*tmp_dest = tmp_c;
		tmp_dest++;
	}
	return (b);
}
