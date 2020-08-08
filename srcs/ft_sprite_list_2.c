/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_list_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheresi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 20:52:07 by ltheresi          #+#    #+#             */
/*   Updated: 2020/08/06 20:52:09 by ltheresi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			ft_list_sort(t_sprite **sprite)
{
	int			count_elem_in_list;
	int			count;
	int			flag_if_all_done;
	t_sprite	*tmp;

	count_elem_in_list = ft_count_sprites(*sprite);
	flag_if_all_done = 0;
	while (flag_if_all_done != count_elem_in_list - 1)
	{
		flag_if_all_done = 0;
		count = count_elem_in_list - 1;
		tmp = *sprite;
		while (count--)
		{
			if (tmp->distance < tmp->next->distance)
				ft_swap_elem_in_list(tmp, tmp->next, sprite);
			else
			{
				flag_if_all_done++;
				tmp = tmp->next;
			}
		}
	}
}

void		ft_delete_sprite(t_sprite *goal, t_sprite **head)
{
	t_sprite *tmp;
	size_t save_id;

	save_id = goal->tex_id;
	tmp = *head;
	if (goal == *head)
	{
		*head = goal->next;
		free(goal);
	}
	else
	{
		while (tmp->next != goal)
			tmp = tmp->next;
		tmp->next = goal->next;
		free(goal);
	}
	tmp = *head;
	while (tmp)
	{
		if (tmp->tex_id > save_id)
			tmp->tex_id = tmp->tex_id - 1;
		tmp = tmp->next;
	}
}

double			ft_get_distance(t_mlx *mlx, t_sprite *sprite)
{
	double		sprite_dist;

	sprite_dist = sqrt(pow(mlx->player.x - sprite->x, 2) + pow(mlx->player.y - sprite->y, 2));
	return (sprite_dist);
}

void		ft_delete_sprite_by_rectangle(t_sprite **head, int x_rectangle, int y_rectangle)
{
	t_sprite *tmp;

	tmp = *head;
	while (tmp)
	{
		if ((int)(tmp->x / 64) == x_rectangle && (int)(tmp->y / 64) == y_rectangle)
			break;
		tmp = tmp->next;
	}
	ft_delete_sprite(tmp, head);
}
