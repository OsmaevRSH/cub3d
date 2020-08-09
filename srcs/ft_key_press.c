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

static void		ft_left_right(int keycode, t_mlx *mlx)
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

static void		ft_tilt_up_down(int keycode, t_mlx *mlx)
{
	if (keycode == 125)
	{
		if (mlx->player.tilt > -500)
			mlx->player.tilt -= 10;
	}
	if (keycode == 126)
	{
		if (mlx->player.tilt < 500)
			mlx->player.tilt += 10;
	}
}

static void		ft_go_left_right(int keycode, t_mlx *mlx)
{
	if (keycode == 0)
	{
		if ((mlx->map.worldMap[(unsigned int)(mlx->player.y - 15 *
		cos(mlx->player.angle)) >> 6u]
		[(unsigned int)(mlx->player.x) >> 6u]) != '1')
			mlx->player.y -= SPEED * cos(mlx->player.angle);
		if ((mlx->map.worldMap[(unsigned int)(mlx->player.y) >> 6u]
		[(unsigned int)(mlx->player.x + 15 * sin(mlx->player.angle))
		>> 6u]) != '1')
			mlx->player.x += SPEED * sin(mlx->player.angle);
	}
	if (keycode == 2)
	{
		if ((mlx->map.worldMap[(unsigned int)(mlx->player.y + 15 *
		cos(mlx->player.angle)) >> 6u][(unsigned int)
		(mlx->player.x) >> 6u]) != '1')
			mlx->player.y += SPEED * cos(mlx->player.angle);
		if ((mlx->map.worldMap[(unsigned int)(mlx->player.y) >> 6u]
		[(unsigned int)(mlx->player.x - 15 * sin(mlx->player.angle))
		>> 6u]) != '1')
			mlx->player.x -= SPEED * sin(mlx->player.angle);
	}
}

static void		ft_go_forward_back(int keycode, t_mlx *mlx)
{
	if (keycode == 13)
	{
		if ((mlx->map.worldMap[(unsigned int)(mlx->player.y + 15 *
		sin(mlx->player.angle)) >> 6u][(unsigned int)(mlx->player.x)
		>> 6u]) != '1')
			mlx->player.y += SPEED * sin(mlx->player.angle);
		if ((mlx->map.worldMap[(unsigned int)(mlx->player.y) >> 6u]
		[(unsigned int)(mlx->player.x + 15 * cos(mlx->player.angle))
		>> 6u]) != '1')
			mlx->player.x += SPEED * cos(mlx->player.angle);
	}
	if (keycode == 1)
	{
		if ((mlx->map.worldMap[(unsigned int)(mlx->player.y - 15 *
		sin(mlx->player.angle)) >> 6u][(unsigned int)(mlx->player.x)
		>> 6u]) != '1')
			mlx->player.y -= SPEED * sin(mlx->player.angle);
		if ((mlx->map.worldMap[(unsigned int)(mlx->player.y) >> 6u]
		[(unsigned int)(mlx->player.x - 15 * cos(mlx->player.angle))
		>> 6u]) != '1')
			mlx->player.x -= SPEED * cos(mlx->player.angle);
	}
}

int				key_press(int keycode, t_mlx *mlx)
{
	char		*output_count_sprites;

	if (keycode == 53)
		exit(0);
	ft_left_right(keycode, mlx);
	ft_go_left_right(keycode, mlx);
	ft_go_forward_back(keycode, mlx);
	ft_tilt_up_down(keycode, mlx);
	if ((mlx->map.worldMap[(unsigned int)(mlx->player.y) >> 6u]
	[(unsigned int)(mlx->player.x) >> 6u]) == '2')
	{
		mlx->collect_sprites++;
		ft_delete_sprite_by_rectangle(&mlx->head_for_sprite_list,
				(int)(mlx->player.x) / 64, (int)(mlx->player.y) / 64);
		(mlx->map.worldMap[(unsigned int)(mlx->player.y) >> 6u]
		[(unsigned int)(mlx->player.x) >> 6u]) = '.';
	}
	replace(mlx, -M_PI / 6, M_PI / (3 * mlx->map.R.width));
	output_count_sprites = ft_strjoin("Number of collected sprites: ",
			ft_itoa(mlx->collect_sprites));
	mlx_string_put(mlx->mlx, mlx->mlx_win, (int)(mlx->map.R.width /
	2 - ft_strlen(output_count_sprites) / 2), mlx->map.R.height - 100,
			0x00000FFFF, output_count_sprites);
	free(output_count_sprites);
	return (0);
}
