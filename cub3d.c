#include "cub3d.h"

void init_color(t_color *color)
{
	color->RED = 0x00FF0000;
	color->GREEN = 0x0000FF00;
	color->BLUE = 0x000000FF;
}

void    init_player(t_player *player)
{
	player->player_x = 70;
	player->player_y = 70;
	player->player_angle = PI/2;
	player->player_dax = 0;
	player->player_day = 0;
}

void	replace(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->mlx_img);
	if(!(mlx->mlx_img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT)))
		exit(0);
	if(!(mlx->mlx_addr = mlx_get_data_addr(mlx->mlx_img, &mlx->mlx_bits_per_pixel, &mlx->mlx_line_length, &mlx->mlx_endian)))
		exit(0);
	drawMap(mlx);
	drawPlayer(mlx, mlx->player.player_x, mlx->player.player_y);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->mlx_img, 0, 0);
}

int  key_press(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 13) //w
    {
        mlx->player.player_y += 5 * sin(mlx->player.player_angle);
        mlx->player.player_x += 5 * cos(mlx->player.player_angle);
    }

	if (keycode == 0) //a
	{
		mlx->player.player_angle -= 0.1;
		mlx->player.player_dax = cos(mlx->player.player_angle) * 5;
		if (mlx->player.player_angle < 0)
			mlx->player.player_angle += 2*PI;
	}
	if (keycode == 1) //s
    {
        mlx->player.player_y -= 5 * sin(mlx->player.player_angle);
        mlx->player.player_x -= 5 * cos(mlx->player.player_angle);
    }

	if (keycode == 2) //d
	{
		mlx->player.player_angle += 0.1;
		if (mlx->player.player_angle > 2*PI)
			mlx->player.player_angle -= 2*PI;
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
	
	while (x < mapWidth*32)
	{
		while (y < mapHeight*32)
		{
			if (worldMap[y/32][x/32] == 1)
				my_mlx_pixel_put(mlx, x, y, mlx->color.RED);
			else
				my_mlx_pixel_put(mlx, x, y, mlx->color.BLUE);
			y++;
		}
		y = 0;
		x++;
	}
}

void    drawPlayer(t_mlx *mlx, double x, double y)
{
    int len_line = 64;
    double i = 0;
    double tmp_x;
    double tmp_y;

    tmp_x = x - 4;
    tmp_y = y - 4;

    while (i <= len_line)
    {
        my_mlx_pixel_put(mlx, (int)(x + i * cos(mlx->player.player_angle)), (int)(y + i * sin(mlx->player.player_angle)), mlx->color.RED);
        i++;
    }
    while (tmp_x < x + 4)
    {
        while (tmp_y < y + 4)
        {
            my_mlx_pixel_put(mlx, (int)tmp_x, (int)tmp_y, mlx->color.RED);
            tmp_y++;
        }
        tmp_y = y - 4;
        tmp_x++;
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
	drawPlayer(&mlx, mlx.player.player_x, mlx.player.player_y);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.mlx_img, 0, 0);
	mlx_hook(mlx.mlx_win, 2, 0L, key_press, &mlx);
	mlx_loop(mlx.mlx);
    return (0);
}