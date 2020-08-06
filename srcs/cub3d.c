#include "../includes/cub3d.h"

void 	draw_Sprite(t_mlx *mlx)
{
	ft_init_draw_sprite_struct(&mlx->draw_sprite);
	if (ft_draw_sprite_one(mlx))
		return;
	ft_draw_sprite_two(mlx);
	mlx->draw_sprite.h_koef = 64.0 / mlx->draw_sprite.sprite_screen_size;
	while (mlx->draw_sprite.y_offset < mlx->draw_sprite.check_y)
		ft_draw_sprite_three(mlx);
}

int         main()
{
	t_mlx   mlx;
	mlx.head_for_sprite_list = NULL;
    mlx.mlx = mlx_init();
	ft_parce("maps/map1.cub", &mlx);
	ft_init_textures(&mlx);
	replace(&mlx);
	mlx_hook(mlx.mlx_win, 2, 0L, key_press, &mlx);
	mlx_hook(mlx.mlx_win, 17, 0L, close_window, &mlx);
	mlx_loop(mlx.mlx);
    return (0);
}
