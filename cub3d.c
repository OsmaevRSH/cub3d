#include "cub3d.h"

int  key_press(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 13 || keycode == 126) //w
    {
		if ((mlx->map.worldMap[(unsigned int)(mlx->player.y + 10 * sin(mlx->player.angle)) >> 6u][(unsigned int)(mlx->player.x) >> 6u]) == '1')
			mlx->player.y += 0;
		else
			mlx->player.y += 10 * sin(mlx->player.angle);
		if ((mlx->map.worldMap[(unsigned int)(mlx->player.y) >> 6u][(unsigned int)(mlx->player.x + 10 * cos(mlx->player.angle)) >> 6u]) == '1')
			mlx->player.y += 0;
		else
        	mlx->player.x += 10 * cos(mlx->player.angle);
    }
	if (keycode == 123) //<-
	{
		mlx->player.angle -= 0.05;
		if (mlx->player.angle < 0)
			mlx->player.angle += 2.0 * M_PI;
	}
	if (keycode == 1 || keycode == 125) //s
    {
		if ((mlx->map.worldMap[(unsigned int)(mlx->player.y - 10 * sin(mlx->player.angle)) >> 6u][(unsigned int)(mlx->player.x) >> 6u]) == '1')
			mlx->player.y += 0;
		else
			mlx->player.y -= 10 * sin(mlx->player.angle);
		if ((mlx->map.worldMap[(unsigned int)(mlx->player.y) >> 6u][(unsigned int)(mlx->player.x - 10 * cos(mlx->player.angle)) >> 6u]) == '1')
			mlx->player.y += 0;
		else
        	mlx->player.x -= 10 * cos(mlx->player.angle);
    }
	if (keycode == 124) //->
	{
		mlx->player.angle += 0.05;
		if (mlx->player.angle > 2.0 * M_PI)
			mlx->player.angle -= 2.0 * M_PI;
	}
	if (keycode == 0) //a
	{
		if ((mlx->map.worldMap[(unsigned int)(mlx->player.y - 10 * cos(mlx->player.angle)) >> 6u][(unsigned int)(mlx->player.x) >> 6u]) == '1')
			mlx->player.y += 0;
		else
			mlx->player.y -= 10 * cos(mlx->player.angle);
		if ((mlx->map.worldMap[(unsigned int)(mlx->player.y) >> 6u][(unsigned int)(mlx->player.x + 10 * sin(mlx->player.angle)) >> 6u]) == '1')
			mlx->player.y += 0;
		else
			mlx->player.x += 10 * sin(mlx->player.angle);
	}
	if (keycode == 2) //d
	{
		if ((mlx->map.worldMap[(unsigned int)(mlx->player.y + 10 * cos(mlx->player.angle)) >> 6u][(unsigned int)(mlx->player.x) >> 6u]) == '1')
			mlx->player.y += 0;
		else
			mlx->player.y += 10 * cos(mlx->player.angle);
		if ((mlx->map.worldMap[(unsigned int)(mlx->player.y) >> 6u][(unsigned int)(mlx->player.x - 10 * sin(mlx->player.angle)) >> 6u]) == '1')
			mlx->player.y += 0;
		else
			mlx->player.x -= 10 * sin(mlx->player.angle);
	}
	replace(mlx);
	return (0);
}


void        my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char    *dst;

	dst = mlx->mlx_addr + (abs(y) * mlx->mlx_line_length + abs(x) * ((unsigned int)mlx->mlx_bits_per_pixel >> 3u));
	*(unsigned int*)dst = color;
}

void	drawMap(t_mlx *mlx)
{
	unsigned int x = 0;
	unsigned int y = 0;
	unsigned int map_x = mapWidth;
	unsigned int map_y = mapHeight;

	while (x < map_x << 4u)
	{
		while (y < map_y << 4u)
		{
			if (mlx->map.worldMap[y >> 4u][x >> 4u] == '1')
				my_mlx_pixel_put(mlx, (int)x, (int)y, 0x0000FF00);
			else
				my_mlx_pixel_put(mlx, (int)x, (int)y, 0x000000FF);
			y++;
		}
		y = 0;
		x++;
	}
}

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

void    drawPlayer(t_mlx *mlx, double x, double y)
{
   int len_line = 16;
   double i = 0;
   double tmp_x;
   double tmp_y;

   tmp_x = x - 4;
   tmp_y = y - 4;
   while (i <= len_line)
   {
       my_mlx_pixel_put(mlx, (int)(x + i * cos(mlx->player.angle)), (int)(y + i * sin(mlx->player.angle)), mlx->color.RED);
       i++;
   }
   while (tmp_x < x + 3)
   {
       while (tmp_y < y + 3)
       {
           my_mlx_pixel_put(mlx, (int)tmp_x, (int)tmp_y, mlx->color.RED);
           tmp_y++;
       }
       tmp_y = y - 4;
       tmp_x++;
   }
}

int close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit(0);
}

int         main()
{
	t_mlx   mlx;
	mlx.head_for_sprite_list = NULL;
	double vector = - M_PI / 6;
	double step = M_PI / (3 * WIDTH);
	int x = 0;
    mlx.mlx = mlx_init();
	ft_parce("map1.cub", &mlx);
	mlx.texture.arr_len_trace = (double *)malloc(sizeof(double) * WIDTH);
    if(!(mlx.mlx_win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "cub3d")))
		exit(0);
	if(!(mlx.mlx_img = mlx_new_image(mlx.mlx, WIDTH, HEIGHT)))
		exit(0);
	mlx.texture.t1.mlx_img = mlx_xpm_file_to_image(mlx.mlx, mlx.map.SO, &mlx.texture.t1.weight, &mlx.texture.t1.height);
	mlx.texture.t2.mlx_img = mlx_xpm_file_to_image(mlx.mlx, mlx.map.NO, &mlx.texture.t2.weight, &mlx.texture.t2.height);
	mlx.texture.t3.mlx_img = mlx_xpm_file_to_image(mlx.mlx, mlx.map.EA, &mlx.texture.t3.weight, &mlx.texture.t3.height);
	mlx.texture.t4.mlx_img = mlx_xpm_file_to_image(mlx.mlx, mlx.map.WE, &mlx.texture.t4.weight, &mlx.texture.t4.height);
	mlx.texture.sprite.mlx_img = mlx_xpm_file_to_image(mlx.mlx, mlx.map.S, &mlx.texture.sprite.weight, &mlx.texture.sprite.height);
	if (!(mlx.mlx_addr = mlx_get_data_addr(mlx.mlx_img, &mlx.mlx_bits_per_pixel, &mlx.mlx_line_length, &mlx.mlx_endian)))
		exit(0);
	mlx.texture.t1.mlx_addr = (int *)mlx_get_data_addr(mlx.texture.t1.mlx_img, &mlx.texture.t1.mlx_bits_per_pixel, &mlx.texture.t1.mlx_line_length, &mlx.texture.t1.mlx_endian);
	mlx.texture.t2.mlx_addr = (int *)mlx_get_data_addr(mlx.texture.t2.mlx_img, &mlx.texture.t2.mlx_bits_per_pixel, &mlx.texture.t2.mlx_line_length, &mlx.texture.t2.mlx_endian);
	mlx.texture.t3.mlx_addr = (int *)mlx_get_data_addr(mlx.texture.t3.mlx_img, &mlx.texture.t3.mlx_bits_per_pixel, &mlx.texture.t3.mlx_line_length, &mlx.texture.t3.mlx_endian);
	mlx.texture.t4.mlx_addr = (int *)mlx_get_data_addr(mlx.texture.t4.mlx_img, &mlx.texture.t4.mlx_bits_per_pixel, &mlx.texture.t4.mlx_line_length, &mlx.texture.t4.mlx_endian);
	mlx.texture.sprite.mlx_addr = (int *)mlx_get_data_addr(mlx.texture.sprite.mlx_img, &mlx.texture.sprite.mlx_bits_per_pixel, &mlx.texture.sprite.mlx_line_length, &mlx.texture.sprite.mlx_endian);
	 while (vector < M_PI / 6)
	 {
	 	trace(&mlx, vector, (int)x);
	 	x += 1;
	 	vector += step;
	 }
	drawMap(&mlx);
	drawPlayer(&mlx, mlx.player.x / 4, mlx.player.y / 4);
	int count_sprites;
	int i = 0;
	t_sprite *tmp;
	count_sprites = ft_count_sprites(mlx.head_for_sprite_list);
	while (i < count_sprites)
	{
		tmp = ft_search_sprite(i, mlx.head_for_sprite_list);
		tmp->distance = ft_get_distance(&mlx, tmp);
		i++;
	}
	ft_list_sort(&mlx.head_for_sprite_list);
	tmp = mlx.head_for_sprite_list;
	while (count_sprites--)
	{
		mlx.sprite.x = tmp->x;
		mlx.sprite.y = tmp->y;
		tmp = tmp->next;
		draw_Sprite(&mlx);
	}
//	save_bmp(&mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.mlx_img, 0, 0);
	mlx_hook(mlx.mlx_win, 2, 0L, key_press, &mlx);
	mlx_hook(mlx.mlx_win, 17, 0L, close_window, &mlx);
	mlx_loop(mlx.mlx);
    return (0);
}
