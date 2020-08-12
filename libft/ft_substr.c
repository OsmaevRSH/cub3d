/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheresi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 13:02:53 by ltheresi          #+#    #+#             */
/*   Updated: 2020/05/05 20:36:38 by ltheresi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	size;

	i = 0;
	if (!s)
		return (0);
	if (ft_strlen(s) < start + 1)
	{
		if (!(str = (char *)malloc(sizeof(char))))
			return (0);
		str[0] = '\0';
		return (str);
	}
	size = ft_strlen(s + start);
	len = (size < len) ? size : len;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	while (i < len && s[start])
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
