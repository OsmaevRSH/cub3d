/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheresi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 20:50:21 by ltheresi          #+#    #+#             */
/*   Updated: 2020/08/06 20:50:24 by ltheresi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void 	draw_Sprite(t_mlx *mlx, t_sprite *sprite)
{
	int save = 0;
	ft_bzero(&mlx->dr_spr, sizeof(mlx->dr_spr));
	if (ft_draw_sprite_one(mlx))
		return;
	ft_draw_sprite_two(mlx);
	mlx->dr_spr.h_koef = 64.0 / mlx->dr_spr.spr_sc_size;
	while (mlx->dr_spr.y_offset < mlx->dr_spr.check_y)
		ft_draw_sprite_three(mlx, sprite, save);
}

int         main()
{
	t_mlx   mlx;
	char *output_count_sprites;
	ft_bzero(&mlx, sizeof(mlx));
    mlx.mlx = mlx_init();
	ft_parce("maps/map1.cub", &mlx);
	ft_init_textures(&mlx);
	replace(&mlx, -M_PI / 6, M_PI / (3 * mlx.map.R.width));
	output_count_sprites = ft_strjoin("Number of collected sprites: ", ft_itoa(mlx.collect_sprites));
	mlx_string_put(mlx.mlx, mlx.mlx_win, (int)(mlx.map.R.width / 2 - ft_strlen(output_count_sprites) / 2), mlx.map.R.height - 100, 0x00000FFFF, output_count_sprites);
	free(output_count_sprites);
//	save_bmp(&mlx);
	mlx_hook(mlx.mlx_win, 2, 0L, key_press, &mlx);
	mlx_hook(mlx.mlx_win, 17, 0L, close_window, &mlx);
	mlx_loop(mlx.mlx);
    return (0);
}
