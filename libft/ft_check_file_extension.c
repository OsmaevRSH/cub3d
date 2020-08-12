/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file_extention.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheresi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 16:29:04 by ltheresi          #+#    #+#             */
/*   Updated: 2020/07/29 16:29:07 by ltheresi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_check_file_extension(char *str, char *check)
{
	if (!str || !check)
		return (0);
	while (*str != '\0')
		str++;
	while (*str != '.')
		str--;
	str++;
	return (!ft_strncmp(str, check, ft_strlen(check)));
}
