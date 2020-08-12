/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheresi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 14:21:13 by ltheresi          #+#    #+#             */
/*   Updated: 2020/05/03 15:59:57 by ltheresi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char *tmp_dest;

	tmp_dest = (unsigned char *)s;
	while (n--)
	{
		*tmp_dest = '\0';
		tmp_dest++;
	}
}
