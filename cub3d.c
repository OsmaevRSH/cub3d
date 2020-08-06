#include "cub3d.h"

void init_color(t_color *color)
{
	color->RED = 0x00FF0000;
	color->GREEN = 0x0000FF00;
	color->BLUE = 0x000000FF;
	color->WHITE = 0x00FFFFFF;
	color->BLACK = 0x00000000;
}

void    init_player(t_player *player)
{
//	player->player_x = 1024;
//	player->player_y = 330;
// player->player_angle -= 0.3;
}

double ft_get_distance(t_mlx *mlx, t_sprite *sprite)
{
	double sprite_dist = sqrt(pow(mlx->player.player_x - sprite->x, 2) + pow(mlx->player.player_y - sprite->y, 2));
	return (sprite_dist);
}

void	ft_swap_elem_in_list(t_sprite *first, t_sprite *second, t_sprite **head)
{
	t_sprite *tmp;

	tmp = *head;
	if (first == *head)
	{
		first->next = second->next;
		second->next = first;
		*head = second;
	}
	else
	{
		while (tmp->next != first)
			tmp = tmp->next;
		first->next = second->next;
		second->next = first;
		tmp->next = second;
	}
}

void	ft_list_sort(t_sprite **sprite)
{
	t_sprite *tmp;
	int count_elem_in_list = ft_count_sprites(*sprite);
	int count;
	int flag_if_all_done = 0;
	while (flag_if_all_done != count_elem_in_list - 1)
	{
		flag_if_all_done = 0;
		count = count_elem_in_list - 1;
		tmp = *sprite;
		while (count--)
		{
			if (tmp->distance < tmp->next->distance)
				ft_swap_elem_in_list(tmp, tmp->next, sprite);
			else
			{
				flag_if_all_done++;
				tmp = tmp->next;
			}
		}
	}
}

void	replace(t_mlx *mlx)
{
	int count_sprites;
	t_sprite *tmp;
	double *arr_dist;
	double vector = - M_PI / 6;
	double step =M_PI / (3 * WIDTH);
	double x = 0;
	int i = 0;
	mlx_destroy_image(mlx->mlx, mlx->mlx_img);
	if(!(mlx->mlx_img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT)))
		exit(0);
	if(!(mlx->mlx_addr = mlx_get_data_addr(mlx->mlx_img, &mlx->mlx_bits_per_pixel, &mlx->mlx_line_length, &mlx->mlx_endian)))
		exit(0);
	while (vector < M_PI / 6 && x < WIDTH)
	{
		trace(mlx, vector, (int)x);
		x += 1;
		vector += step;
	}
	count_sprites = ft_count_sprites(mlx->head_for_sprite_list);
	while (i < count_sprites)
	{
		tmp = ft_search_sprite(i, mlx->head_for_sprite_list);
		tmp->distance = ft_get_distance(mlx, tmp);
		i++;
	}
	ft_list_sort(&mlx->head_for_sprite_list);
	tmp = mlx->head_for_sprite_list;
	while (count_sprites--)
	{
		mlx->sprite.x = tmp->x;
		mlx->sprite.y = tmp->y;
		tmp = tmp->next;
		draw_Sprite(mlx);
	}
	drawMap(mlx);
	drawPlayer(mlx, (unsigned int)mlx->player.player_x >> 2u, (unsigned int)mlx->player.player_y >> 2u);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->mlx_img, 0, 0);
}

int  key_press(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 13 || keycode == 126) //w
    {
		if ((mlx->map.worldMap[(unsigned int)(mlx->player.player_y + 10 * sin(mlx->player.player_angle)) >> 6u][(unsigned int)(mlx->player.player_x) >> 6u]) == '1')
			mlx->player.player_y += 0;
		else
			mlx->player.player_y += 10 * sin(mlx->player.player_angle);
		if ((mlx->map.worldMap[(unsigned int)(mlx->player.player_y) >> 6u][(unsigned int)(mlx->player.player_x + 10 * cos(mlx->player.player_angle)) >> 6u]) == '1')
			mlx->player.player_y += 0;
		else
        	mlx->player.player_x += 10 * cos(mlx->player.player_angle);
    }
	if (keycode == 123) //<-
	{
		mlx->player.player_angle -= 0.05;
		if (mlx->player.player_angle < 0)
			mlx->player.player_angle += 2.0 * M_PI;
	}
	if (keycode == 1 || keycode == 125) //s
    {
		if ((mlx->map.worldMap[(unsigned int)(mlx->player.player_y - 10 * sin(mlx->player.player_angle)) >> 6u][(unsigned int)(mlx->player.player_x) >> 6u]) == '1')
			mlx->player.player_y += 0;
		else
			mlx->player.player_y -= 10 * sin(mlx->player.player_angle);
		if ((mlx->map.worldMap[(unsigned int)(mlx->player.player_y) >> 6u][(unsigned int)(mlx->player.player_x - 10 * cos(mlx->player.player_angle)) >> 6u]) == '1')
			mlx->player.player_y += 0;
		else
        	mlx->player.player_x -= 10 * cos(mlx->player.player_angle);
    }
	if (keycode == 124) //->
	{
		mlx->player.player_angle += 0.05;
		if (mlx->player.player_angle > 2.0*M_PI)
			mlx->player.player_angle -= 2.0 * M_PI;
	}
	if (keycode == 0) //a
	{
		if ((mlx->map.worldMap[(unsigned int)(mlx->player.player_y - 10 * cos(mlx->player.player_angle)) >> 6u][(unsigned int)(mlx->player.player_x) >> 6u]) == '1')
			mlx->player.player_y += 0;
		else
			mlx->player.player_y -= 10 * cos(mlx->player.player_angle);
		if ((mlx->map.worldMap[(unsigned int)(mlx->player.player_y) >> 6u][(unsigned int)(mlx->player.player_x + 10 * sin(mlx->player.player_angle)) >> 6u]) == '1')
			mlx->player.player_y += 0;
		else
			mlx->player.player_x += 10 * sin(mlx->player.player_angle);
	}
	if (keycode == 2) //d
	{
		if ((mlx->map.worldMap[(unsigned int)(mlx->player.player_y + 10 * cos(mlx->player.player_angle)) >> 6u][(unsigned int)(mlx->player.player_x) >> 6u]) == '1')
			mlx->player.player_y += 0;
		else
			mlx->player.player_y += 10 * cos(mlx->player.player_angle);
		if ((mlx->map.worldMap[(unsigned int)(mlx->player.player_y) >> 6u][(unsigned int)(mlx->player.player_x - 10 * sin(mlx->player.player_angle)) >> 6u]) == '1')
			mlx->player.player_y += 0;
		else
			mlx->player.player_x -= 10 * sin(mlx->player.player_angle);
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
				my_mlx_pixel_put(mlx, (int)x, (int)y, mlx->color.BLACK);
			else
				my_mlx_pixel_put(mlx, (int)x, (int)y, mlx->color.WHITE);
			y++;
		}
		y = 0;
		x++;
	}
}

void 	draw_Sprite(t_mlx *mlx)
{
	int x_offset;
	int y_offset;
	double save;
	int i = 0, j = 0;
	double step_for_angle = M_PI / (3.0 * WIDTH);
	double sprite_dir = atan2(mlx->sprite.y - mlx->player.player_y, mlx->sprite.x - mlx->player.player_x);
	while (sprite_dir > 2 * M_PI)
		sprite_dir -= 2 * M_PI;
	while (sprite_dir < 0)
		sprite_dir += 2 * M_PI;
	double angel;
	double sprite_dist = sqrt(pow(mlx->player.player_x - mlx->sprite.x, 2) + pow(mlx->player.player_y - mlx->sprite.y, 2));
	int sprite_screen_size = HEIGHT / sprite_dist * 64;
	if (fabs(sprite_dir - mlx->player.player_angle) > (M_PI / 6.0) + (sprite_screen_size / 2.0 * step_for_angle) && fabs(sprite_dir - mlx->player.player_angle) < (11.0 * M_PI / 6.0) - (sprite_screen_size / 2.0 * step_for_angle))
		return ;
	angel = sprite_dir - mlx->player.player_angle;
	while (angel < -M_PI)
		angel += (2*M_PI);
	while (angel > M_PI)
		angel -= (2*M_PI);

	x_offset = (int)((angel / (M_PI / 6.0) * (WIDTH / 2.0) + (WIDTH / 2.0)) - sprite_screen_size / 2.0);
	if (x_offset > WIDTH)
		x_offset = WIDTH - 1;
	if (x_offset < 0)
		x_offset = 0;
	y_offset = HEIGHT / 2 - sprite_screen_size / 2;
	int check_x = x_offset + sprite_screen_size;
	if (check_x > WIDTH)
		check_x = WIDTH;
	int check_y = y_offset + sprite_screen_size;
	if (check_y > HEIGHT)
		check_y = HEIGHT;

	if (angel - (sprite_screen_size / 2.0 * step_for_angle) < -M_PI / 6.0)
	{
		save = -M_PI / 6.0 - (angel - (sprite_screen_size / 2.0 * step_for_angle));
		save = save / step_for_angle;
		x_offset += (int)save;
		i = (int)save;
		check_x -= (int)save;
	}

	double h_koef = 64.0 / sprite_screen_size;
	int h_k, w_k;
	int color;
	while (y_offset < check_y)
	{
		while (x_offset < check_x)
		{
			h_k = (int)(j * h_koef);
			w_k = (int)(i * h_koef);
			color = mlx->texture.sprite.mlx_addr[h_k * 64 + (w_k % 64)];
			if (color > 0 && sprite_dist < mlx->texture.arr_len_trace[x_offset])
				my_mlx_pixel_put(mlx, x_offset, y_offset, color);
			x_offset++;
			i++;
		}
		i = 0;
		j++;
		x_offset = (int)((angel / (M_PI / 6.0) * (WIDTH / 2.0) + (WIDTH / 2.0)) - sprite_screen_size / 2.0);
		if (angel - (sprite_screen_size / 2.0 * step_for_angle) < -M_PI / 6.0)
		{
			x_offset += (int)save;
			i = (int)save;
		}
		if (x_offset > WIDTH)
			x_offset = WIDTH - 1;
		if (x_offset < 0)
			x_offset = 0;
		y_offset++;
	}
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
       my_mlx_pixel_put(mlx, (int)(x + i * cos(mlx->player.player_angle)), (int)(y + i * sin(mlx->player.player_angle)), mlx->color.RED);
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
	init_color(&mlx.color);
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

	init_player(&mlx.player);
	 while (vector < M_PI / 6)
	 {
	 	trace(&mlx, vector, (int)x);
	 	x += 1;
	 	vector += step;
	 }
	drawMap(&mlx);
	drawPlayer(&mlx, mlx.player.player_x / 4, mlx.player.player_y / 4);
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
	save_bmp(&mlx);
//	screenshot(&mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.mlx_img, 0, 0);
	mlx_hook(mlx.mlx_win, 2, 0L, key_press, &mlx);
	mlx_hook(mlx.mlx_win, 17, 0L, close_window, &mlx);
	mlx_loop(mlx.mlx);
    return (0);
}
