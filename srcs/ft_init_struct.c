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

#include "../includes/cub3d.h"

void	ft_init_mlx_img(t_mlx *mlx)
{
	mlx->mlx_img = mlx_new_image(mlx->mlx, mlx->map.r.width,
	mlx->map.r.height);
	mlx->texture.t1.mlx_img = mlx_xpm_file_to_image(mlx->mlx,
	mlx->map.so, &mlx->texture.t1.weight, &mlx->texture.t1.height);
	mlx->texture.t2.mlx_img = mlx_xpm_file_to_image(mlx->mlx,
	mlx->map.no, &mlx->texture.t2.weight, &mlx->texture.t2.height);
	mlx->texture.t3.mlx_img = mlx_xpm_file_to_image(mlx->mlx,
	mlx->map.ea, &mlx->texture.t3.weight, &mlx->texture.t3.height);
	mlx->texture.t4.mlx_img = mlx_xpm_file_to_image(mlx->mlx,
	mlx->map.we, &mlx->texture.t4.weight, &mlx->texture.t4.height);
	mlx->texture.sprite_1.mlx_img = mlx_xpm_file_to_image(mlx->mlx,
	mlx->map.s, &mlx->texture.sprite_1.weight, &mlx->texture.sprite_1.height);
	mlx->texture.sprite_2.mlx_img = mlx_xpm_file_to_image(mlx->mlx,
	mlx->map.ss, &mlx->texture.sprite_2.weight, &mlx->texture.sprite_2.height);
}

void	ft_init_mlx_addr(t_mlx *mlx)
{
	mlx->mlx_addr = mlx_get_data_addr(mlx->mlx_img, &mlx->mlx_bits_per_pixel,
	&mlx->mlx_line_length, &mlx->mlx_endian);
	mlx->texture.t1.mlx_addr = (int *)mlx_get_data_addr(mlx->texture.t1.mlx_img,
	&mlx->texture.t1.mlx_bits_per_pixel, &mlx->texture.t1.mlx_line_length,
	&mlx->texture.t1.mlx_endian);
	mlx->texture.t2.mlx_addr = (int *)mlx_get_data_addr(mlx->texture.t2.mlx_img,
	&mlx->texture.t2.mlx_bits_per_pixel, &mlx->texture.t2.mlx_line_length,
	&mlx->texture.t2.mlx_endian);
	mlx->texture.t3.mlx_addr = (int *)mlx_get_data_addr(mlx->texture.t3.mlx_img,
	&mlx->texture.t3.mlx_bits_per_pixel, &mlx->texture.t3.mlx_line_length,
	&mlx->texture.t3.mlx_endian);
	mlx->texture.t4.mlx_addr = (int *)mlx_get_data_addr(mlx->texture.t4.mlx_img,
	&mlx->texture.t4.mlx_bits_per_pixel, &mlx->texture.t4.mlx_line_length,
	&mlx->texture.t4.mlx_endian);
	mlx->texture.sprite_1.mlx_addr =
	(int *)mlx_get_data_addr(mlx->texture.sprite_1.mlx_img,
	&mlx->texture.sprite_1.mlx_bits_per_pixel,
	&mlx->texture.sprite_1.mlx_line_length, &mlx->texture.sprite_1.mlx_endian);
	mlx->texture.sprite_2.mlx_addr =
	(int *)mlx_get_data_addr(mlx->texture.sprite_2.mlx_img,
	&mlx->texture.sprite_2.mlx_bits_per_pixel,
	&mlx->texture.sprite_2.mlx_line_length, &mlx->texture.sprite_2.mlx_endian);
}

void	ft_init_textures(t_mlx *mlx)
{
	if (!(mlx->texture.arr_len_trace =
	(double *)malloc(sizeof(double) * mlx->map.r.width)))
		ft_free_mlx(mlx, 1);
	mlx->mlx_win = mlx_new_window(mlx->mlx, mlx->map.r.width,
	mlx->map.r.height, "cub3d");
	ft_init_mlx_img(mlx);
	ft_init_mlx_addr(mlx);
}
