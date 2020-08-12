/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheresi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 12:00:51 by ltheresi          #+#    #+#             */
/*   Updated: 2020/05/03 16:03:00 by ltheresi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*new_str;
	size_t	len_str;
	size_t	i;

	len_str = ft_strlen(s1);
	i = 0;
	if (!(new_str = (char *)malloc((len_str + 1) * sizeof(char))))
		return (0);
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
