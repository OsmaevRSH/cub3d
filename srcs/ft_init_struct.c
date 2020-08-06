/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheresi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 20:51:23 by ltheresi          #+#    #+#             */
/*   Updated: 2020/08/06 20:51:25 by ltheresi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_trace.h"

void	ft_init_tracer_struct(t_trace *trace)
{
	trace->projected_slice_height = 0;
	trace->first_point_ax = 0;
	trace->first_point_ay = 0;
	trace->first_point_bx = 0;
	trace->first_point_by = 0;
	trace->len1 = 0;
	trace->len2 = 0;
	trace->len_line = 0;
	trace->i = 0;
	trace->angle = 0;
	trace->len_to_viewport = 0;
	trace->h_koef = 0;
	trace->up_start = 0;
	trace->h_texture = 0;
	trace->down_stop = 0;
	trace->save = 0;
	trace->color = 0;
	trace->check_1 = 0;
	trace->check_2 = 0;
	trace->flag1 = 0;
	trace->flag2 = 0;
	trace->tx = 0;
	trace->h_k = 0;
	trace->k = 0;
	trace->dst = 0;
}

void	ft_init_draw_sprite_struct(t_draw_sprite *sprite)
{
	sprite->i = 0;
	sprite->j = 0;
	sprite->h_k = 0;
	sprite->w_k = 0;
	sprite->check_x = 0;
	sprite->check_y = 0;
	sprite->color = 0;
	sprite->x_offset = 0;
	sprite->y_offset = 0;
	sprite->sprite_screen_size = 0;
	sprite->save = 0;
	sprite->step_for_angle = 0;
	sprite->sprite_dir = 0;
	sprite->angel = 0;
	sprite->sprite_dist = 0;
	sprite->h_koef = 0;
}

void	ft_init_textures(t_mlx *mlx)
{
	mlx->texture.arr_len_trace = (double *)malloc(sizeof(double) * mlx->map.R.width);
	mlx->mlx_win = mlx_new_window(mlx->mlx, mlx->map.R.width, mlx->map.R.height, "cub3d");
	mlx->mlx_img = mlx_new_image(mlx->mlx, mlx->map.R.width, mlx->map.R.height);
	mlx->texture.t1.mlx_img = mlx_xpm_file_to_image(mlx->mlx, mlx->map.SO, &mlx->texture.t1.weight, &mlx->texture.t1.height);
	mlx->texture.t2.mlx_img = mlx_xpm_file_to_image(mlx->mlx, mlx->map.NO, &mlx->texture.t2.weight, &mlx->texture.t2.height);
	mlx->texture.t3.mlx_img = mlx_xpm_file_to_image(mlx->mlx, mlx->map.EA, &mlx->texture.t3.weight, &mlx->texture.t3.height);
	mlx->texture.t4.mlx_img = mlx_xpm_file_to_image(mlx->mlx, mlx->map.WE, &mlx->texture.t4.weight, &mlx->texture.t4.height);
	mlx->texture.sprite.mlx_img = mlx_xpm_file_to_image(mlx->mlx, mlx->map.S, &mlx->texture.sprite.weight, &mlx->texture.sprite.height);
	mlx->mlx_addr = mlx_get_data_addr(mlx->mlx_img, &mlx->mlx_bits_per_pixel, &mlx->mlx_line_length, &mlx->mlx_endian);
	mlx->texture.t1.mlx_addr = (int *)mlx_get_data_addr(mlx->texture.t1.mlx_img, &mlx->texture.t1.mlx_bits_per_pixel, &mlx->texture.t1.mlx_line_length, &mlx->texture.t1.mlx_endian);
	mlx->texture.t2.mlx_addr = (int *)mlx_get_data_addr(mlx->texture.t2.mlx_img, &mlx->texture.t2.mlx_bits_per_pixel, &mlx->texture.t2.mlx_line_length, &mlx->texture.t2.mlx_endian);
	mlx->texture.t3.mlx_addr = (int *)mlx_get_data_addr(mlx->texture.t3.mlx_img, &mlx->texture.t3.mlx_bits_per_pixel, &mlx->texture.t3.mlx_line_length, &mlx->texture.t3.mlx_endian);
	mlx->texture.t4.mlx_addr = (int *)mlx_get_data_addr(mlx->texture.t4.mlx_img, &mlx->texture.t4.mlx_bits_per_pixel, &mlx->texture.t4.mlx_line_length, &mlx->texture.t4.mlx_endian);
	mlx->texture.sprite.mlx_addr = (int *)mlx_get_data_addr(mlx->texture.sprite.mlx_img, &mlx->texture.sprite.mlx_bits_per_pixel, &mlx->texture.sprite.mlx_line_length, &mlx->texture.sprite.mlx_endian);
}
