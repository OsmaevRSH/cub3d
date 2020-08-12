/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheresi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 19:02:42 by ltheresi          #+#    #+#             */
/*   Updated: 2020/05/03 16:03:44 by ltheresi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char tmp_c;
	char *tmp_s;
	char *tmp_ptr;

	tmp_c = (char)c;
	tmp_s = (char *)s;
	tmp_ptr = tmp_s;
	while (*tmp_s)
		tmp_s++;
	if (tmp_c == '\0')
		return (tmp_s);
	tmp_s--;
	while (tmp_s != tmp_ptr - 1)
	{
		if (*tmp_s == tmp_c)
		{
			return (tmp_s);
		}
		tmp_s--;
	}
	return (0);
}
