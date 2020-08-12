/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheresi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 13:23:56 by ltheresi          #+#    #+#             */
/*   Updated: 2020/05/03 16:03:49 by ltheresi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_left(const char *str, const char *set, size_t i)
{
	size_t		j;

	j = 0;
	while (str[i] && set[j])
	{
		if (str[i] == set[j])
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (i - 1);
}

static size_t	ft_right(const char *str, const char *set, size_t j)
{
	size_t		i;

	i = 0;
	while (str[j] && set[i])
	{
		if (str[j] == set[i])
		{
			j--;
			i = 0;
		}
		else
			i++;
	}
	return (j + 1);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	size_t		j;
	size_t		k;
	char		*result_str;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	k = 0;
	j = ft_strlen(s1) - 1;
	i = ft_left((char *)s1, (char *)set, i);
	if (i == j)
	{
		if (!(result_str = (char *)malloc(sizeof(char))))
			return (NULL);
		result_str[0] = '\0';
		return (result_str);
	}
	j = ft_right((char *)s1, (char *)set, j);
	if (!(result_str = (char *)malloc((j - ++i + 1) * sizeof(char))))
		return (NULL);
	while (i < j)
		result_str[k++] = s1[i++];
	result_str[k] = '\0';
	return (result_str);
}
