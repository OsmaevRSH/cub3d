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
	mlx->dr_spr.st_for_an = M_PI / (3.0 * mlx->map.R.width);
	mlx->dr_spr.sprite_dir = atan2(mlx->sprite.y - mlx->player.y,
	mlx->sprite.x - mlx->player.x);
	while (mlx->dr_spr.sprite_dir > 2 * M_PI)
		mlx->dr_spr.sprite_dir -= 2 * M_PI;
	while (mlx->dr_spr.sprite_dir < 0)
		mlx->dr_spr.sprite_dir += 2 * M_PI;
	mlx->dr_spr.sprite_dist = sqrt(pow(mlx->player.x - mlx->sprite.x, 2)
	+ pow(mlx->player.y - mlx->sprite.y, 2));
	mlx->dr_spr.spr_sc_size = (int)((((unsigned int)mlx->map.R.width) / tan(M_PI / 6.0) / (64 * mlx->dr_spr.sprite_dist)) * mlx->map.R.height);
	if (fabs(mlx->dr_spr.sprite_dir - mlx->player.angle) > (M_PI / 6.0)
		+ (mlx->dr_spr.spr_sc_size / 2.0 *
		mlx->dr_spr.st_for_an) && fabs(mlx->dr_spr.sprite_dir -
		mlx->player.angle) < (11.0 * M_PI / 6.0) - (mlx->dr_spr.
	spr_sc_size / 2.0 * mlx->dr_spr.st_for_an))
		return (1);
	mlx->dr_spr.angel = mlx->dr_spr.sprite_dir - mlx->player.angle;
	mlx->dr_spr.angel < -M_PI ? mlx->dr_spr.angel += (2 * M_PI) : 0;
	mlx->dr_spr.angel > M_PI ? mlx->dr_spr.angel -= (2 * M_PI) : 0;
	return (0);
}

void	ft_draw_sprite_two(t_mlx *mlx)
{
	mlx->dr_spr.x_offset = (int)((mlx->dr_spr.angel / (M_PI / 6.0)
	* (mlx->map.R.width / 2.0) + (mlx->map.R.width / 2.0)) -
	mlx->dr_spr.spr_sc_size / 2.0);
	if (mlx->dr_spr.x_offset > mlx->map.R.width)
		mlx->dr_spr.x_offset = mlx->map.R.width - 1;
	if (mlx->dr_spr.x_offset < 0)
		mlx->dr_spr.x_offset = 0;
	mlx->dr_spr.y_offset = mlx->map.R.height / 2 -
	mlx->dr_spr.spr_sc_size / 2 + mlx->player.tilt;
	mlx->dr_spr.check_x = mlx->dr_spr.x_offset + mlx->dr_spr.spr_sc_size;
	if (mlx->dr_spr.check_x > mlx->map.R.width)
		mlx->dr_spr.check_x = mlx->map.R.width;
	mlx->dr_spr.check_y = mlx->dr_spr.y_offset + mlx->dr_spr.spr_sc_size;
	if (mlx->dr_spr.check_y > mlx->map.R.height)
		mlx->dr_spr.check_y = mlx->map.R.height;
	if (mlx->dr_spr.angel - (mlx->dr_spr.spr_sc_size /
	2.0 * mlx->dr_spr.st_for_an) < -M_PI / 6.0)
	{
		mlx->dr_spr.save = -M_PI / 6.0 - (mlx->dr_spr.angel -
		(mlx->dr_spr.spr_sc_size / 2.0 * mlx->dr_spr.st_for_an));
		mlx->dr_spr.save = mlx->dr_spr.save / mlx->dr_spr.st_for_an;
		mlx->dr_spr.x_offset += (int)mlx->dr_spr.save;
		mlx->dr_spr.i = (int)mlx->dr_spr.save;
		mlx->dr_spr.check_x -= (int)mlx->dr_spr.save;
	}
}

void	ft_mini_while(t_mlx *mlx, t_sprite *sprite, int save)
{
	mlx->dr_spr.h_k = (int)((mlx->dr_spr.j - save) *
							mlx->dr_spr.h_koef);
	mlx->dr_spr.w_k = (int)(mlx->dr_spr.i * mlx->dr_spr.h_koef);
	if (sprite->id == 0)
		mlx->dr_spr.color = mlx->texture.sprite_1.mlx_addr
		[mlx->dr_spr.h_k * mlx->texture.sprite_1.weight + (mlx->dr_spr.w_k % mlx->texture.sprite_1.height)];
	else
		mlx->dr_spr.color = mlx->texture.sprite_2.mlx_addr
		[mlx->dr_spr.h_k * mlx->texture.sprite_2.weight + (mlx->dr_spr.w_k % mlx->texture.sprite_2.height)];
	if (mlx->dr_spr.color > 0 && mlx->dr_spr.sprite_dist <
		mlx->texture.arr_len_trace[mlx->dr_spr.x_offset] &&
		mlx->dr_spr.y_offset > 0)
		my_mlx_pixel_put(mlx, mlx->dr_spr.x_offset,
		mlx->dr_spr.y_offset, mlx->dr_spr.color);
	mlx->dr_spr.x_offset++;
	mlx->dr_spr.i++;
}

void	ft_draw_sprite_three(t_mlx *mlx, t_sprite *sprite, int save)
{
	while (mlx->dr_spr.x_offset < mlx->dr_spr.check_x)
		ft_mini_while(mlx, sprite, save);
	mlx->dr_spr.i = 0;
	mlx->dr_spr.j++;
	mlx->dr_spr.x_offset = (int)((mlx->dr_spr.angel / (M_PI / 6.0)
	* (mlx->map.R.width / 2.0) + (mlx->map.R.width / 2.0)) -
	mlx->dr_spr.spr_sc_size / 2.0);
	if (mlx->dr_spr.angel - (mlx->dr_spr.spr_sc_size / 2.0
	* mlx->dr_spr.st_for_an) < -M_PI / 6.0)
	{
		mlx->dr_spr.x_offset += (int)mlx->dr_spr.save;
		mlx->dr_spr.i = (int)mlx->dr_spr.save;
	}
	if (mlx->dr_spr.x_offset > mlx->map.R.width)
		mlx->dr_spr.x_offset = mlx->map.R.width - 1;
	if (mlx->dr_spr.x_offset < 0)
		mlx->dr_spr.x_offset = 0;
	mlx->dr_spr.y_offset++;
}
