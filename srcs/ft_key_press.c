/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_press.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheresi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 20:51:34 by ltheresi          #+#    #+#             */
/*   Updated: 2020/08/06 20:51:36 by ltheresi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			ft_left_right(int keycode, t_mlx *mlx)
{
	if (keycode == 123)
	{
		mlx->player.angle -= 0.05;
		if (mlx->player.angle < 0)
			mlx->player.angle += 2.0 * M_PI;
	}
	if (keycode == 124)
	{
		mlx->player.angle += 0.05;
		if (mlx->player.angle > 2.0 * M_PI)
			mlx->player.angle -= 2.0 * M_PI;
	}
}

void			ft_tilt_up_down(int keycode, t_mlx *mlx)
{
	if (keycode == 125)
	{
		if (mlx->player.tilt > -250)
			mlx->player.tilt -= 10;
	}
	if (keycode == 126)
	{
		if (mlx->player.tilt < 250)
			mlx->player.tilt += 10;
	}
}

void			ft_go_left_right(int keycode, t_mlx *mlx)
{
	if (keycode == 0)
	{
		if ((mlx->map.world_map[(unsigned int)(mlx->player.y - (SPEED + 3) *
		cos(mlx->player.angle)) >> 6u]
		[(unsigned int)(mlx->player.x) >> 6u]) != '1')
			mlx->player.y -= SPEED * cos(mlx->player.angle);
		if ((mlx->map.world_map[(unsigned int)(mlx->player.y) >> 6u]
		[(unsigned int)(mlx->player.x + (SPEED + 3) * sin(mlx->player.angle))
		>> 6u]) != '1')
			mlx->player.x += SPEED * sin(mlx->player.angle);
	}
	if (keycode == 2)
	{
		if ((mlx->map.world_map[(unsigned int)(mlx->player.y + (SPEED + 3) *
		cos(mlx->player.angle)) >> 6u][(unsigned int)
		(mlx->player.x) >> 6u]) != '1')
			mlx->player.y += SPEED * cos(mlx->player.angle);
		if ((mlx->map.world_map[(unsigned int)(mlx->player.y) >> 6u]
		[(unsigned int)(mlx->player.x - (SPEED + 3) * sin(mlx->player.angle))
		>> 6u]) != '1')
			mlx->player.x -= SPEED * sin(mlx->player.angle);
	}
}

void			ft_go_forward_back(int keycode, t_mlx *mlx)
{
	if (keycode == 13)
	{
		if ((mlx->map.world_map[(unsigned int)(mlx->player.y + (SPEED + 3) *
		sin(mlx->player.angle)) >> 6u][(unsigned int)(mlx->player.x)
		>> 6u]) != '1')
			mlx->player.y += SPEED * sin(mlx->player.angle);
		if ((mlx->map.world_map[(unsigned int)(mlx->player.y) >> 6u]
		[(unsigned int)(mlx->player.x + (SPEED + 3) * cos(mlx->player.angle))
		>> 6u]) != '1')
			mlx->player.x += SPEED * cos(mlx->player.angle);
	}
	if (keycode == 1)
	{
		if ((mlx->map.world_map[(unsigned int)(mlx->player.y - (SPEED + 3) *
		sin(mlx->player.angle)) >> 6u][(unsigned int)(mlx->player.x)
		>> 6u]) != '1')
			mlx->player.y -= SPEED * sin(mlx->player.angle);
		if ((mlx->map.world_map[(unsigned int)(mlx->player.y) >> 6u]
		[(unsigned int)(mlx->player.x - (SPEED + 3) * cos(mlx->player.angle))
		>> 6u]) != '1')
			mlx->player.x -= SPEED * cos(mlx->player.angle);
	}
}

int				key_press(int keycode, t_mlx *mlx)
{
	char		*output_count_sprites;
	char		*count;

	if (keycode == 53)
		ft_free_mlx(mlx, 0);
	ft_key_events(keycode, mlx);
	if ((mlx->map.world_map[(unsigned int)(mlx->player.y) >> 6u]
	[(unsigned int)(mlx->player.x) >> 6u]) == '2')
	{
		mlx->collect_sprites++;
		ft_delete_sprite_by_rectangle(&mlx->head_for_sprite_list,
		(int)(mlx->player.x) / 64, (int)(mlx->player.y) / 64);
		(mlx->map.world_map[(unsigned int)(mlx->player.y) >> 6u]
		[(unsigned int)(mlx->player.x) >> 6u]) = '.';
	}
	replace(mlx, -M_PI / 6, M_PI / (3 * mlx->map.r.width), 1);
	output_count_sprites = ft_strjoin("Number of collected sprites: ",
	count = ft_itoa(mlx->collect_sprites));
	free(count);
	mlx_string_put(mlx->mlx, mlx->mlx_win, (int)(mlx->map.r.width
	/ 2 - 5 * ft_strlen(output_count_sprites)), mlx->map.r.height - 50,
	0x00000FFFF, output_count_sprites);
	free(output_count_sprites);
	return (0);
}
