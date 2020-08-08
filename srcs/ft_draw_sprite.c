/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheresi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 20:51:03 by ltheresi          #+#    #+#             */
/*   Updated: 2020/08/06 20:51:05 by ltheresi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_draw_sprite_one(t_mlx *mlx)
{
	mlx->draw_sprite.step_for_angle = M_PI / (3.0 * mlx->map.R.width);
	mlx->draw_sprite.sprite_dir = atan2(mlx->sprite.y - mlx->player.y, mlx->sprite.x - mlx->player.x);
	while (mlx->draw_sprite.sprite_dir > 2 * M_PI)
		mlx->draw_sprite.sprite_dir -= 2 * M_PI;
	while (mlx->draw_sprite.sprite_dir < 0)
		mlx->draw_sprite.sprite_dir += 2 * M_PI;
	mlx->draw_sprite.sprite_dist = sqrt(pow(mlx->player.x - mlx->sprite.x, 2) + pow(mlx->player.y - mlx->sprite.y, 2));
	mlx->draw_sprite.sprite_screen_size = (int)(mlx->map.R.height / mlx->draw_sprite.sprite_dist * 64);
	if (fabs(mlx->draw_sprite.sprite_dir - mlx->player.angle) > (M_PI / 6.0) + (mlx->draw_sprite.sprite_screen_size / 2.0 * mlx->draw_sprite.step_for_angle) && fabs(mlx->draw_sprite.sprite_dir - mlx->player.angle) < (11.0 * M_PI / 6.0) - (mlx->draw_sprite.sprite_screen_size / 2.0 * mlx->draw_sprite.step_for_angle))
		return (1);
	mlx->draw_sprite.angel = mlx->draw_sprite.sprite_dir - mlx->player.angle;
	while (mlx->draw_sprite.angel < -M_PI)
		mlx->draw_sprite.angel += (2*M_PI);
	while (mlx->draw_sprite.angel > M_PI)
		mlx->draw_sprite.angel -= (2*M_PI);
	return (0);
}

void	ft_draw_sprite_two(t_mlx *mlx)
{
	mlx->draw_sprite.x_offset = (int)((mlx->draw_sprite.angel / (M_PI / 6.0) * (mlx->map.R.width / 2.0) + (mlx->map.R.width / 2.0)) - mlx->draw_sprite.sprite_screen_size / 2.0);
	if (mlx->draw_sprite.x_offset > mlx->map.R.width)
		mlx->draw_sprite.x_offset = mlx->map.R.width - 1;
	if (mlx->draw_sprite.x_offset < 0)
		mlx->draw_sprite.x_offset = 0;
	mlx->draw_sprite.y_offset = mlx->map.R.height / 2 - mlx->draw_sprite.sprite_screen_size / 2 + mlx->player.tilt;
	mlx->draw_sprite.check_x = mlx->draw_sprite.x_offset + mlx->draw_sprite.sprite_screen_size;
	if (mlx->draw_sprite.check_x > mlx->map.R.width)
		mlx->draw_sprite.check_x = mlx->map.R.width;
	mlx->draw_sprite.check_y = mlx->draw_sprite.y_offset + mlx->draw_sprite.sprite_screen_size;
	if (mlx->draw_sprite.check_y> mlx->map.R.height)
		mlx->draw_sprite.check_y = mlx->map.R.height;
	if (mlx->draw_sprite.angel - (mlx->draw_sprite.sprite_screen_size / 2.0 * mlx->draw_sprite.step_for_angle) < -M_PI / 6.0)
	{
		mlx->draw_sprite.save = -M_PI / 6.0 - (mlx->draw_sprite.angel - (mlx->draw_sprite.sprite_screen_size / 2.0 * mlx->draw_sprite.step_for_angle));
		mlx->draw_sprite.save = mlx->draw_sprite.save / mlx->draw_sprite.step_for_angle;
		mlx->draw_sprite.x_offset += (int)mlx->draw_sprite.save;
		mlx->draw_sprite.i = (int)mlx->draw_sprite.save;
		mlx->draw_sprite.check_x -= (int)mlx->draw_sprite.save;
	}
}

void	ft_draw_sprite_three(t_mlx *mlx, t_sprite *sprite, int save)
{
	while (mlx->draw_sprite.x_offset < mlx->draw_sprite.check_x)
	{
		mlx->draw_sprite.h_k = (int)((mlx->draw_sprite.j - save) * mlx->draw_sprite.h_koef);
		mlx->draw_sprite.w_k = (int)(mlx->draw_sprite.i * mlx->draw_sprite.h_koef);
		if (sprite->id == 0)
			mlx->draw_sprite.color = mlx->texture.sprite_1.mlx_addr[mlx->draw_sprite.h_k * 64 + (mlx->draw_sprite.w_k % 64)];
		else
			mlx->draw_sprite.color = mlx->texture.sprite_2.mlx_addr[mlx->draw_sprite.h_k * 64 + (mlx->draw_sprite.w_k % 64)];
		if (mlx->draw_sprite.color > 0 && mlx->draw_sprite.sprite_dist < mlx->texture.arr_len_trace[mlx->draw_sprite.x_offset] && mlx->draw_sprite.y_offset > 0)
			my_mlx_pixel_put(mlx, mlx->draw_sprite.x_offset, mlx->draw_sprite.y_offset, mlx->draw_sprite.color);
		mlx->draw_sprite.x_offset++;
		mlx->draw_sprite.i++;
	}
	mlx->draw_sprite.i = 0;
	mlx->draw_sprite.j++;
	mlx->draw_sprite.x_offset = (int)((mlx->draw_sprite.angel / (M_PI / 6.0) * (mlx->map.R.width / 2.0) + (mlx->map.R.width / 2.0)) - mlx->draw_sprite.sprite_screen_size / 2.0);
	if (mlx->draw_sprite.angel - (mlx->draw_sprite.sprite_screen_size / 2.0 * mlx->draw_sprite.step_for_angle) < -M_PI / 6.0)
	{
		mlx->draw_sprite.x_offset += (int)mlx->draw_sprite.save;
		mlx->draw_sprite.i = (int)mlx->draw_sprite.save;
	}
	if (mlx->draw_sprite.x_offset > mlx->map.R.width)
		mlx->draw_sprite.x_offset = mlx->map.R.width - 1;
	if (mlx->draw_sprite.x_offset < 0)
		mlx->draw_sprite.x_offset = 0;
	mlx->draw_sprite.y_offset++;
}
