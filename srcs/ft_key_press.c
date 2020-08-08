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


static void ft_go_left_right(int keycode, t_mlx *mlx)
{
	if (keycode == 0)
	{
		if ((mlx->map.worldMap[(unsigned int)(mlx->player.y - 10 * cos(mlx->player.angle)) >> 6u][(unsigned int)(mlx->player.x) >> 6u]) != '1')
			mlx->player.y -= 10 * cos(mlx->player.angle);
		if ((mlx->map.worldMap[(unsigned int)(mlx->player.y) >> 6u][(unsigned int)(mlx->player.x + 10 * sin(mlx->player.angle)) >> 6u]) != '1')
			mlx->player.x += 10 * sin(mlx->player.angle);
	}
	if (keycode == 2)
	{
		if ((mlx->map.worldMap[(unsigned int)(mlx->player.y + 10 * cos(mlx->player.angle)) >> 6u][(unsigned int)(mlx->player.x) >> 6u]) != '1')
			mlx->player.y += 10 * cos(mlx->player.angle);
		if ((mlx->map.worldMap[(unsigned int)(mlx->player.y) >> 6u][(unsigned int)(mlx->player.x - 10 * sin(mlx->player.angle)) >> 6u]) != '1')
			mlx->player.x -= 10 * sin(mlx->player.angle);
	}
}

static void ft_go_forward_back(int keycode, t_mlx *mlx)
{
	if (keycode == 13 || keycode == 126)
	{
		if ((mlx->map.worldMap[(unsigned int)(mlx->player.y + 10 * sin(mlx->player.angle)) >> 6u][(unsigned int)(mlx->player.x) >> 6u]) != '1')
			mlx->player.y += 10 * sin(mlx->player.angle);
		if ((mlx->map.worldMap[(unsigned int)(mlx->player.y) >> 6u][(unsigned int)(mlx->player.x + 10 * cos(mlx->player.angle)) >> 6u]) != '1')
			mlx->player.x += 10 * cos(mlx->player.angle);
	}
	if (keycode == 1 || keycode == 125)
	{
		if ((mlx->map.worldMap[(unsigned int)(mlx->player.y - 10 * sin(mlx->player.angle)) >> 6u][(unsigned int)(mlx->player.x) >> 6u]) != '1')
			mlx->player.y -= 10 * sin(mlx->player.angle);
		if ((mlx->map.worldMap[(unsigned int)(mlx->player.y) >> 6u][(unsigned int)(mlx->player.x - 10 * cos(mlx->player.angle)) >> 6u]) != '1')
			mlx->player.x -= 10 * cos(mlx->player.angle);
	}
}

int close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit(0);
}

int  key_press(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		exit(0);
	ft_left_right(keycode, mlx);
	ft_go_left_right(keycode, mlx);
	ft_go_forward_back(keycode, mlx);
	if ((mlx->map.worldMap[(unsigned int)(mlx->player.y) >> 6u][(unsigned int)(mlx->player.x) >> 6u]) == '2')
	{
		ft_delete_sprite_by_rectangle(&mlx->head_for_sprite_list, (int)(mlx->player.x) / 64, (int)(mlx->player.y) / 64);
		(mlx->map.worldMap[(unsigned int)(mlx->player.y) >> 6u][(unsigned int)(mlx->player.x) >> 6u]) = '.';
	}
	replace(mlx);
	return (0);
}
