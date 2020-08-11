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

void		draw_sprite(t_mlx *mlx, t_sprite *sprite)
{
	int		save;

	save = 0;
	ft_bzero(&mlx->dr_spr, sizeof(mlx->dr_spr));
	if (ft_draw_sprite_one(mlx))
		return ;
	ft_draw_sprite_two(mlx);
	mlx->dr_spr.h_koef = 64.0 / mlx->dr_spr.spr_sc_size;
	while (mlx->dr_spr.y_offset < mlx->dr_spr.check_y)
		ft_draw_sprite_three(mlx, sprite, save);
}

void		ft_argc_3(int argc, char **argv, t_mlx *mlx)
{
	if (argc == 3 && !ft_strncmp(argv[2], "--save", 6))
	{
		replace(mlx, -M_PI / 6, M_PI / (3 * mlx->map.r.width), 0);
		save_bmp(mlx);
		ft_free_mlx(mlx, 0);
	}
	if (argc == 3 && ft_strncmp(argv[2], "--save", 6))
	{
		ft_putstr_fd("Error:\nInvalid parameters\n", 1);
		ft_free_mlx(mlx, 1);
	}
}

int			ft_write_cub(t_mlx *mlx, char **argv, int argc)
{
	char	*output_count_sprites;
	char	*count;
	int a, b;

	ft_bzero(mlx, sizeof(*mlx));
	mlx->mlx = mlx_init();
	mlx_get_screen_size(mlx->mlx, &a, &b);
	ft_parce(argv[1], mlx);
	ft_init_textures(mlx);
	ft_argc_3(argc, argv, mlx);
	replace(mlx, -M_PI / 6, M_PI / (3 * mlx->map.r.width), 1);
	count = ft_itoa(mlx->collect_sprites);
	output_count_sprites = ft_strjoin("Number of collected sprites: ", count);
	mlx_string_put(mlx->mlx, mlx->mlx_win, (int)(mlx->map.r.width
	/ 2 - 5 * ft_strlen(output_count_sprites)), mlx->map.r.height - 50,
	0x00000FFFF, output_count_sprites);
	free(output_count_sprites);
	free(count);
	mlx_hook(mlx->mlx_win, 2, 0L, key_press, mlx);
	mlx_hook(mlx->mlx_win, 17, 0L, close_window, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}

int			main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc != 2 && argc != 3)
	{
		write(1, "Error\nInvalid number of arguments\n", 34);
		exit(0);
	}
	else
		return (ft_write_cub(&mlx, argv, argc));
}
