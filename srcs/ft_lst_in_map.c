/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_in_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheresi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 17:44:37 by ltheresi          #+#    #+#             */
/*   Updated: 2020/08/09 17:44:39 by ltheresi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static t_map_len	*ft_lst_map_new(int len, char *str)
{
	t_map_len		*data;

	if (!(data = (t_map_len *)malloc(sizeof(t_map_len))))
		return (0);
	data->len = len;
	data->str = str;
	data->next = NULL;
	return (data);
}

int					ft_lst_map_add(int len, char *str, t_map_len **head)
{
	t_map_len		*tmp;

	tmp = *head;
	if (!*head)
	{
		if (!(*head = ft_lst_map_new(len, str)))
			return (0);
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		if (!(tmp->next = ft_lst_map_new(len, str)))
			return (0);
	}
	return (1);
}

int					ft_search_max_len_in_lst(t_map_len **head)
{
	t_map_len		*tmp;
	int				max;

	max = -9999;
	tmp = *head;
	while (tmp)
	{
		if (tmp->len > max)
			max = tmp->len;
		tmp = tmp->next;
	}
	return (max);
}
