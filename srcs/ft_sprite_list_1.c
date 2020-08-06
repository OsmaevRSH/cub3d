/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheresi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 11:55:07 by ltheresi          #+#    #+#             */
/*   Updated: 2020/08/06 20:52:00 by ltheresi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static t_sprite	*ft_create_new_sprite(int x, int y, size_t id)
{
	t_sprite	*new_list;

	if (!(new_list = (t_sprite *)malloc(sizeof(t_sprite))))
		return (0);
	new_list->x = x;
	new_list->y = y;
	new_list->next = NULL;
	new_list->tex_id = id;
	return (new_list);
}

void			ft_push_back_new_sprite(int x, int y,
				size_t id, t_sprite **head)
{
	t_sprite	*tmp_list;

	tmp_list = *head;
	if (!tmp_list)
		*head = ft_create_new_sprite(x, y, id);
	else
	{
		while (tmp_list->next)
			tmp_list = tmp_list->next;
		tmp_list->next = ft_create_new_sprite(x, y, id);
	}
}

int				ft_count_sprites(t_sprite *head)
{
	size_t		count;

	count = 0;
	while (head)
	{
		head = head->next;
		count++;
	}
	return (count);
}

t_sprite		*ft_search_sprite(size_t id, t_sprite *head)
{
	while (head)
	{
		if (head->tex_id == id)
			return (head);
		head = head->next;
	}
	return (0);
}

void			ft_swap_elem_in_list(t_sprite *first, t_sprite *second, t_sprite **head)
{
	t_sprite	*tmp;

	tmp = *head;
	if (first == *head)
	{
		first->next = second->next;
		second->next = first;
		*head = second;
	}
	else
	{
		while (tmp->next != first)
			tmp = tmp->next;
		first->next = second->next;
		second->next = first;
		tmp->next = second;
	}
}
