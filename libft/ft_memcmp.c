/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheresi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 22:41:30 by ltheresi          #+#    #+#             */
/*   Updated: 2020/05/03 16:01:51 by ltheresi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *tmp_s1;
	unsigned char *tmp_s2;

	tmp_s1 = (unsigned char *)s1;
	tmp_s2 = (unsigned char *)s2;
	while (n--)
	{
		if (*tmp_s1 > *tmp_s2)
			return (*tmp_s1 - *tmp_s2);
		else if (*tmp_s1 < *tmp_s2)
			return (-(*tmp_s2 - *tmp_s1));
		else
		{
			tmp_s2++;
			tmp_s1++;
		}
	}
	return (0);
}
