/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_frame.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheresi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 20:51:46 by ltheresi          #+#    #+#             */
/*   Updated: 2020/08/06 20:51:48 by ltheresi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void				ft_create_sprites(int count_sprites, t_mlx *mlx)
{
	t_sprite		*tmp;
	int				i;

	i = 0;
	while (i < count_sprites)
	{
		tmp = ft_search_sprite(i, mlx->head_for_sprite_list);
		tmp->distance = ft_get_distance(mlx, tmp);
		i++;
	}
	ft_list_sort(&mlx->head_for_sprite_list);
	tmp = mlx->head_for_sprite_list;
	while (count_sprites--)
	{
		mlx->sprite.x = tmp->x;
		mlx->sprite.y = tmp->y;
		draw_Sprite(mlx, tmp);
		tmp = tmp->next;
	}
}

void				ft_trace_in_replace(t_mlx *mlx,
					double vector, double step, int *x)
{
	while (vector < M_PI / 6 && *x < mlx->map.R.width)
	{
		trace(mlx, vector, (int)(*x));
		(*x) += 1;
		vector += step;
	}
}

void				replace(t_mlx *mlx, double vector, double step)
{
	int				count_sprites;
	int				x;
	unsigned int	value_x;
	unsigned int	value_y;

	value_y = mlx->map.R.height <= 300 ? 4u : 3u;
	value_x = mlx->map.R.width <= 500 ? 4u : 3u;
	x = 0;
	mlx_destroy_image(mlx->mlx, mlx->mlx_img);
	if (!(mlx->mlx_img = mlx_new_image(mlx->mlx,
	mlx->map.R.width, mlx->map.R.height)))
		ft_free_mlx(mlx, 1);
	if (!(mlx->mlx_addr = mlx_get_data_addr(mlx->mlx_img,
	&mlx->mlx_bits_per_pixel, &mlx->mlx_line_length, &mlx->mlx_endian)))
		ft_free_mlx(mlx, 1);
	ft_trace_in_replace(mlx, vector, step, &x);
	count_sprites = ft_count_sprites(mlx->head_for_sprite_list);
	if (count_sprites > 0)
		ft_create_sprites(count_sprites, mlx);
	ft_draw_map(mlx);
	ft_draw_sprite(mlx, (unsigned int)mlx->player.x >> value_x,
	(unsigned int)mlx->player.y >> value_y);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->mlx_img, 0, 0);
}
