/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheresi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 18:46:39 by ltheresi          #+#    #+#             */
/*   Updated: 2020/05/03 16:02:55 by ltheresi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char tmp_c;
	char *tmp_s;

	tmp_c = (char)c;
	tmp_s = (char *)s;
	if (tmp_c == '\0')
	{
		while (*tmp_s)
			tmp_s++;
		return (tmp_s);
	}
	while (*tmp_s)
	{
		if (*tmp_s == tmp_c)
			return (tmp_s);
		tmp_s++;
	}
	return (0);
}
