/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheresi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 15:21:37 by ltheresi          #+#    #+#             */
/*   Updated: 2020/05/05 20:30:10 by ltheresi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		while (s[i] != c && s[i])
			i++;
		count++;
		while (s[i] == c && s[i])
			i++;
	}
	count += 1;
	return (count);
}

static int	count_char(char const *s, char c)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (s[i] && s[i] != c)
	{
		count++;
		i++;
	}
	count++;
	return (count);
}

static void	ft_collect(char **str, const char *ptr)
{
	char	**tmp;
	char	*tmp_ptr;

	tmp = str;
	while (*str != ptr)
	{
		tmp_ptr = *str;
		str++;
		free(tmp_ptr);
	}
	free(tmp);
}

static char	*ft_get_str(char **tmp_str, char *str, char const *s, char c)
{
	char *tmp_ptr;

	if (!(tmp_ptr = (char *)malloc(sizeof(char) * count_char(s, c))))
	{
		ft_collect(tmp_str, str);
		return (0);
	}
	return (tmp_ptr);
}

char		**ft_split(char const *s, char c)
{
	char	**str;
	char	**tmp_str;
	char	*ptr;

	if (!s)
		return (0);
	if (!(str = (char **)malloc(sizeof(char *) * count_words(s, c))))
		return (0);
	tmp_str = str;
	while (*s == c && *s)
		s++;
	while (*s)
	{
		*str = ft_get_str(tmp_str, *str, s, c);
		ptr = *str;
		while (*s != c && *s)
			*(*str)++ = *s++;
		**str = '\0';
		while (*s == c && *s)
			s++;
		*str++ = ptr;
	}
	*str = 0;
	return (tmp_str);
}
