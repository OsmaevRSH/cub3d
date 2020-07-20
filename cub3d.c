#include "cub3d.h"

void init_color(t_color *color)
{
	color->RED = 0x00FF0000;
	color->GREEN = 0x0000FF00;
	color->BLUE = 0x000000FF;
}

void    init_player(t_player *player)
{
	player->player_x = 40;
	player->player_y = 40;
	player->player_angle = 0;
}

void	replace(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->mlx_img);
	if(!(mlx->mlx_img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT)))
		exit(0);
	if(!(mlx->mlx_addr = mlx_get_data_addr(mlx->mlx_img, &mlx->mlx_bits_per_pixel, &mlx->mlx_line_length, &mlx->mlx_endian)))
		exit(0);
	drawMap(mlx);
	drawPlayer(mlx, (int)mlx->player.player_x, (int)mlx->player.player_y);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->mlx_img, 0, 0);
}

int  key_press(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 13) //w
		mlx->player.player_y -= 5;
	if (keycode == 0) //a
	{
		mlx->player.player_angle += 0.1;
		if (mlx->player.player_angle > 2*PI)
			mlx->player.player_angle -= 2*PI;
	}
	if (keycode == 1) //s
		mlx->player.player_y += 5;
	if (keycode == 2) //d
	{
		mlx->player.player_angle -= 0.1;
		if (mlx->player.player_angle < 2*PI)
			mlx->player.player_angle += 2*PI;
	}
	
	replace(mlx);
	return (0);
}

void        my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char    *dst;
	
	dst = mlx->mlx_addr + (y * mlx->mlx_line_length + x * (mlx->mlx_bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	drawMap(t_mlx *mlx)
{
	int x = 0;
	int y = 0;
	
	while (x < mapWidth*20)
	{
		while (y < mapHeight*20)
		{
			if (worldMap[y/20][x/20] == 1)
				my_mlx_pixel_put(mlx, x, y, mlx->color.RED);
			else
				my_mlx_pixel_put(mlx, x, y, mlx->color.BLUE);
			y++;
		}
		y = 0;
		x++;
	}
}

void    drawPlayer(t_mlx *mlx, int x, int y)
{
	int pos_x;
	int pos_y;
	
	pos_x = x - 5;
	pos_y = y - 5;
	
	while (pos_x < x + 5)
	{
		while (pos_y < y + 5)
		{
			my_mlx_pixel_put(mlx, pos_x, pos_y, mlx->color.GREEN);
			pos_y++;
		}
		pos_y = y - 5;
		pos_x++;
	}
}

int         main()
{
	t_mlx   mlx;

	init_color(&mlx.color);
	init_player(&mlx.player);
    mlx.mlx = mlx_init();
    if(!(mlx.mlx_win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "cub3d")))
		exit(0);
	if(!(mlx.mlx_img = mlx_new_image(mlx.mlx, WIDTH, HEIGHT)))
		exit(0);
	if (!(mlx.mlx_addr = mlx_get_data_addr(mlx.mlx_img, &mlx.mlx_bits_per_pixel, &mlx.mlx_line_length, &mlx.mlx_endian)))
		exit(0);
	drawMap(&mlx);
	drawPlayer(&mlx, (int)mlx.player.player_x, (int)mlx.player.player_y);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.mlx_img, 0, 0);
	mlx_hook(mlx.mlx_win, 2, 0L, key_press, &mlx);
	mlx_loop(mlx.mlx);
    return (0);
}