/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheresi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 19:07:43 by ltheresi          #+#    #+#             */
/*   Updated: 2020/05/03 16:00:42 by ltheresi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count(long long tmp_n)
{
	int			len;

	len = 0;
	if (tmp_n == 0)
		return (1);
	if (tmp_n < 0)
		len++;
	while (tmp_n)
	{
		tmp_n /= 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char		*str;
	int			len;
	long long	tmp_n;

	tmp_n = (long long int)n;
	len = ft_count(tmp_n);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	str[len--] = '\0';
	if (tmp_n < 0)
	{
		str[0] = '-';
		tmp_n *= -1;
	}
	while (tmp_n > 9)
	{
		str[len--] = (char)((tmp_n % 10) + 48);
		tmp_n /= 10;
	}
	str[len] = (char)(tmp_n + 48);
	return (str);
}
