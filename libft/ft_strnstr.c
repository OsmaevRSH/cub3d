/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheresi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 19:55:06 by ltheresi          #+#    #+#             */
/*   Updated: 2020/05/03 16:03:39 by ltheresi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = -1;
	j = 0;
	if (!needle[0])
		return ((char *)&haystack[++i]);
	while (len && haystack[++i])
	{
		if (haystack[i] == needle[j])
		{
			while (haystack[i++] == needle[j++] && len--)
			{
				if (!needle[j])
					return ((char *)&(haystack[i - j]));
				if (!len)
					return (0);
			}
			i -= j;
			len += j;
			j = 0;
		}
		len--;
	}
	return (0);
}
