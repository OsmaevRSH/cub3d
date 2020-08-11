/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheresi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 14:57:03 by ltheresi          #+#    #+#             */
/*   Updated: 2020/08/11 14:57:05 by ltheresi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		ft_free_map_list(t_map_len **head)
{
	t_map_len *tmp;

	tmp = *head;
	while (*head)
	{
		tmp = tmp->next;
		free((*head)->str);
		free(*head);
		*head = tmp;
	}
}

static void		ft_free_sprite_list(t_sprite **head)
{
	t_sprite *tmp;

	tmp = *head;
	while (*head)
	{
		tmp = tmp->next;
		free(*head);
		*head = tmp;
	}
}

static void		ft_free_map(t_mlx *mlx)
{
	int			i;

	i = 0;
	free(mlx->map.no);
	free(mlx->map.so);
	free(mlx->map.we);
	free(mlx->map.ea);
	free(mlx->map.s);
	free(mlx->map.ss);
	if (mlx->map.world_map)
	{
		while (mlx->map.world_map[i] != NULL)
			free(mlx->map.world_map[i++]);
		free(mlx->map.world_map);
	}
}

void			ft_free_mlx(t_mlx *mlx, int flag)
{
	ft_free_map(mlx);
	ft_free_map_list(&mlx->head_for_map_len_list);
	ft_free_sprite_list(&mlx->head_for_sprite_list);
	free(mlx->texture.arr_len_trace);
	if (flag == 1)
		exit(1);
	else
		exit(0);
}
