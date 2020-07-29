#include "cub3d.h"

//int mlx->map.worldMap[mapWidth][mapHeight]=
//		{
//				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
//				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//				{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1},
//				{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//				{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//				{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//				{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//				{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//				{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1},
//				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
//				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
//				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
//				{1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,1,1,1},
//				{1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1},
//				{1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1},
//				{1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
//				{1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,1,1,1},
//				{1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,0,0,0,1},
//				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
//				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
//		};

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
	player->player_x = 512;
	player->player_y = 160;
	player->player_angle = M_PI_2;
}

void	replace(t_mlx *mlx)
{
	double vector = - M_PI / 6;
	double step =M_PI / (3 * WIDTH);
	double x = 0;
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
//	drawMap(mlx);
//	drawPlayer(mlx, mlx->player.player_x / 8, mlx->player.player_y / 8);
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->mlx_img, 0, 0);
}

int  key_press(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 13 || keycode == 126) //w
    {
		if ((mlx->map.worldMap[(unsigned int)(mlx->player.player_y + 10 * sin(mlx->player.player_angle)) >> 5u][(unsigned int)(mlx->player.player_x) >> 5u]) == '1')
			mlx->player.player_y += 0;
		else
			mlx->player.player_y += 10 * sin(mlx->player.player_angle);
		if ((mlx->map.worldMap[(unsigned int)(mlx->player.player_y) >> 5u][(unsigned int)(mlx->player.player_x + 10 * cos(mlx->player.player_angle)) >> 5u]) == '1')
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
		if ((mlx->map.worldMap[(unsigned int)(mlx->player.player_y - 10 * sin(mlx->player.player_angle)) >> 5u][(unsigned int)(mlx->player.player_x) >> 5u]) == '1')
			mlx->player.player_y += 0;
		else
			mlx->player.player_y -= 10 * sin(mlx->player.player_angle);
		if ((mlx->map.worldMap[(unsigned int)(mlx->player.player_y) >> 5u][(unsigned int)(mlx->player.player_x - 10 * cos(mlx->player.player_angle)) >> 5u]) == '1')
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
		if ((mlx->map.worldMap[(unsigned int)(mlx->player.player_y - 10 * cos(mlx->player.player_angle)) >> 5u][(unsigned int)(mlx->player.player_x) >> 5u]) == '1')
			mlx->player.player_y += 0;
		else
			mlx->player.player_y -= 10 * cos(mlx->player.player_angle);
		if ((mlx->map.worldMap[(unsigned int)(mlx->player.player_y) >> 5u][(unsigned int)(mlx->player.player_x + 10 * sin(mlx->player.player_angle)) >> 5u]) == '1')
			mlx->player.player_y += 0;
		else
			mlx->player.player_x += 10 * sin(mlx->player.player_angle);
	}
	if (keycode == 2) //d
	{
		if ((mlx->map.worldMap[(unsigned int)(mlx->player.player_y + 10 * cos(mlx->player.player_angle)) >> 5u][(unsigned int)(mlx->player.player_x) >> 5u]) == '1')
			mlx->player.player_y += 0;
		else
			mlx->player.player_y += 10 * cos(mlx->player.player_angle);
		if ((mlx->map.worldMap[(unsigned int)(mlx->player.player_y) >> 5u][(unsigned int)(mlx->player.player_x - 10 * sin(mlx->player.player_angle)) >> 5u]) == '1')
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
			printf("%c", **mlx->map.worldMap);
			if (mlx->map.worldMap[y >> 4u][x >> 4u] == 49)
				my_mlx_pixel_put(mlx, (int)x, (int)y, mlx->color.BLACK);
			else
				my_mlx_pixel_put(mlx, (int)x, (int)y, mlx->color.WHITE);
			y++;
		}
		y = 0;
		x++;
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
   while (tmp_x < x + 5)
   {
       while (tmp_y < y + 5)
       {
           my_mlx_pixel_put(mlx, (int)tmp_x, (int)tmp_y, mlx->color.RED);
           tmp_y++;
       }
       tmp_y = y - 4;
       tmp_x++;
   }
}

 void    trace(t_mlx *mlx, double vector, int x)
 {
 	int tx;
 	double angle = mlx->player.player_angle + vector;
 	double projected_slice_height;
 	if (angle > 2*M_PI)
 		angle -= 2*M_PI;
 	if (angle < 0)
 		angle += 2*M_PI;
     double first_point_ax;
     double first_point_ay;
     double first_point_bx;
     double first_point_by;
     double len1;
     double len2;
     double len_line;
 	int up_start;
 	int down_stop;
     double i = 0;
 	int save;
 	int color;
 	int check_1 = 0;
 	int check_2 = 0;
 	int flag1 = 0, flag2 = 0;

     if ((angle > 0 && angle < M_PI)) // 1 and 2
 	{
 		first_point_ay = ((unsigned int)(mlx->player.player_y / 32) << 5u) + 32;
 		flag1 = 1;
 	}
     else if ((angle > M_PI && angle < 2 * M_PI)) // 3 and 4
 	{
 		first_point_ay = ((unsigned int)(mlx->player.player_y / 32) << 5u) - 0.00000001;
 		flag1 = 2;
 	}

     else
         first_point_ay = mlx->player.player_y;

 	if (angle >= 0 && angle <  (M_PI_2)) // 1
 		first_point_ax = mlx->player.player_x + (first_point_ay - mlx->player.player_y) * tan((M_PI_2) - angle);
 	else if (angle > (M_PI_2) && angle <= M_PI) // 2
 		first_point_ax = mlx->player.player_x - (first_point_ay - mlx->player.player_y) * tan(angle - (M_PI_2));
 	else if (angle >= M_PI && angle < 3.0 * M_PI_2) // 3
 		first_point_ax = mlx->player.player_x - (mlx->player.player_y - first_point_ay) * tan(3.0 * M_PI_2 - angle);
 	else if (angle > 3.0 * M_PI_2 && angle <= 2 * M_PI) // 4
 		first_point_ax = mlx->player.player_x + (mlx->player.player_y - first_point_ay) * tan(angle - 3.0 * M_PI_2);
 	else
 		first_point_ax = mlx->player.player_x;

 	while (first_point_ax > 0 && first_point_ay > 0 && first_point_ax < (unsigned int)mapWidth << 5u && first_point_ay < (unsigned int)mapHeight << 5u && mlx->map.worldMap[(unsigned int)first_point_ay >> 5u][(unsigned int)first_point_ax >> 5u] != '1')
 	{
 		if (angle > 0 && angle <= (M_PI_2))
 		{
 			first_point_ax += 32 * tan((M_PI_2) - angle);
 			first_point_ay += 32;
 		}
 		else if (angle > (M_PI_2) && angle < M_PI)
 		{
 			first_point_ax -= 32 * tan(angle - (M_PI_2));
 			first_point_ay += 32;
 		}
 		else if (angle > M_PI && angle <= 3.0 * M_PI_2)
 		{
 			first_point_ax -= 32 * tan(3.0 * M_PI_2 - angle);
 			first_point_ay -= 32;
 		}
 		else if (angle > 3.0 * M_PI_2 && angle < 2 * M_PI)
 		{
 			first_point_ax += 32 * tan(angle - 3.0 * M_PI_2);
 			first_point_ay -= 32;
 		}
 		else
 			break;
 	}
 	/*================================================================================================================================================================================*/
 	if ((angle >= 0 && angle < (M_PI_2)) || (angle > 3.0 * M_PI_2 && angle <= 2 * M_PI)) // 1 and 4
 	{
 		first_point_bx = ((unsigned int)(mlx->player.player_x / 32) << 5u) + 32;
 		flag2 = 1;
 	}
 	else if ((angle > (M_PI_2) && angle <= M_PI) || (angle > M_PI && angle < 3.0 * M_PI_2)) // 2 and 3
 	{
 		first_point_bx = ((unsigned int)(mlx->player.player_x / 32) << 5u) - 0.00000001;
 		flag2 = 2;
 	}
 	else
 		first_point_bx = mlx->player.player_x;

 	if (angle >= 0 && angle < (M_PI_2)) // 1
 		first_point_by = mlx->player.player_y + (first_point_bx - mlx->player.player_x) * tan(angle);
 	else if (angle > (M_PI_2) && angle <= M_PI) // 2
 		first_point_by = mlx->player.player_y + (mlx->player.player_x - first_point_bx) * tan(M_PI - angle);
 	else if (angle > M_PI && angle < 3.0 * M_PI_2) // 3
 		first_point_by = mlx->player.player_y - (mlx->player.player_x - first_point_bx) * tan(angle - M_PI);
 	else if (angle > 3.0 * M_PI_2 && angle <= 2 * M_PI) // 4
 		first_point_by = mlx->player.player_y - (first_point_bx - mlx->player.player_x) * tan(2 * M_PI - angle);
 	else
 		first_point_by = mlx->player.player_y;
 	while (first_point_bx > 0 && first_point_by > 0 && first_point_bx < (unsigned int)mapWidth << 5u && first_point_by < (unsigned int)mapHeight << 5u && mlx->map.worldMap[(unsigned int)first_point_by >> 5u][(unsigned int)first_point_bx >> 5u] != '1')
 	{
 		if (angle >= 0 && angle < (M_PI_2))
 		{
 			first_point_bx += 32;
 			first_point_by += 32 * tan(angle);
 		}
 		else if (angle > (M_PI_2) && angle <= M_PI)
 		{
 			first_point_bx -= 32;
 			first_point_by += 32 * tan(M_PI - angle);
 		}
 		else if (angle > M_PI && angle < 3.0 * M_PI_2)
 		{
 			first_point_bx -= 32;
 			first_point_by -= 32 * tan(angle - M_PI);
 		}
 		else if (angle > (M_PI_2) * 3 && angle <= 2 * M_PI)
 		{
 			first_point_bx += 32;
 			first_point_by -= 32 * tan(2 * M_PI - angle);
 		}
 		else
 			break;
 	}
 	if (first_point_ax == mlx->player.player_x && first_point_ay == mlx->player.player_y)
 		len1 = INFINITY;
 	else
 		len1 = sqrt(pow((mlx->player.player_x - first_point_ax), 2.0) + pow((mlx->player.player_y - first_point_ay), 2.0));
 	if (first_point_bx == mlx->player.player_x && first_point_by == mlx->player.player_y)
 		len2 = INFINITY;
 	else
 		len2 = sqrt(pow((mlx->player.player_x - first_point_bx), 2.0) + pow((mlx->player.player_y - first_point_by), 2.0));
 	if (len1 > len2)
 	{
 		len_line = len2;
 		tx = (int)first_point_by * 2;
 		check_2 = flag2;
 	}
 	else
 	{
 		len_line = len1;
 		tx = (int)first_point_ax * 2;
 		check_1 = flag1;
 	}
 	if (len_line != INFINITY)
 	{
 		len_line = len_line * cos(mlx->player.player_angle - angle);
 		double len_to_viewport = (((unsigned int)WIDTH >> 1u) / tan(M_PI / 6.0));
 		projected_slice_height = (len_to_viewport / (64 * len_line)) * HEIGHT / 2;
 		up_start = (int)(((unsigned int)HEIGHT >> 1u) - projected_slice_height) ;
 		int h_texture = 64;
 		double h_koef = h_texture / (projected_slice_height * 2);
 		int h_k;
 		save = up_start;
 		if (up_start <= 0)
 			up_start = 0;
 		down_stop = (int)(((unsigned int )HEIGHT >> 1u) + projected_slice_height);
 		if (down_stop >= HEIGHT)
 			down_stop = HEIGHT - 1;
 		char *dst;
 		int k = 0;
 		while (k < up_start)
 		{
 			dst = mlx->mlx_addr + (abs(k) * mlx->mlx_line_length + abs(x) * ((unsigned int)mlx->mlx_bits_per_pixel >> 3u));
 				*(unsigned int*)dst = 0x0087CEEB;
 			k++;
 		}
 		while (up_start < down_stop)
 		{
 			h_k = (int)((up_start - save) * h_koef);
 			if (check_1 == 1)
 				color = mlx->texture.t1.mlx_addr[h_k * mlx->texture.t1.height + (tx % mlx->texture.t1.weight)];
 			else if (check_1 == 2)
 				color = mlx->texture.t2.mlx_addr[h_k * mlx->texture.t2.height + (tx % mlx->texture.t2.weight)];
 			else if (check_2 == 1)
 				color = mlx->texture.t3.mlx_addr[h_k * mlx->texture.t3.height + (tx % mlx->texture.t3.weight)];
 			else
 				color = mlx->texture.t4.mlx_addr[h_k * mlx->texture.t4.height + (tx % mlx->texture.t4.weight)];
 			my_mlx_pixel_put(mlx, x, up_start, color);
 			up_start++;
 		}
 		k = down_stop;
 		while (k < HEIGHT - 1)
 		{
 			dst = mlx->mlx_addr + (abs(k) * mlx->mlx_line_length + abs(x) * ((unsigned int)mlx->mlx_bits_per_pixel >> 3u));
 				*(unsigned int*)dst = 0x003CB371;
 			k++;
 		}
 /*		while (i <= len_line / 8)
 		{
 			my_mlx_pixel_put(mlx, (int)(mlx->player.player_x + i * cos(angle)), (int)(mlx->player.player_y + i * sin(angle)), color);
 			i++;
 		}*/
 	}
 }

//int close(t_mlx *mlx)
//{
//	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
//	exit(0);
//}

int         main()
{

	t_mlx   mlx;
	double vector = - M_PI / 6;
	double step = M_PI / (3 * WIDTH);
	init_color(&mlx.color);
	init_player(&mlx.player);
	int x = 0;
    mlx.mlx = mlx_init();
	ft_parce("map1.cub", &mlx);
    if(!(mlx.mlx_win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "cub3d")))
		exit(0);
	if(!(mlx.mlx_img = mlx_new_image(mlx.mlx, WIDTH, HEIGHT)))
		exit(0);
	mlx.texture.t1.mlx_img = mlx_xpm_file_to_image(mlx.mlx, "texture_xpm/WALL32.xpm", &mlx.texture.t1.weight, &mlx.texture.t1.height);
	mlx.texture.t2.mlx_img = mlx_xpm_file_to_image(mlx.mlx, "texture_xpm/WALL77.xpm", &mlx.texture.t2.weight, &mlx.texture.t2.height);
	mlx.texture.t3.mlx_img = mlx_xpm_file_to_image(mlx.mlx, "texture_xpm/WALL82.xpm", &mlx.texture.t3.weight, &mlx.texture.t3.height);
	mlx.texture.t4.mlx_img = mlx_xpm_file_to_image(mlx.mlx, "texture_xpm/WALL1.xpm", &mlx.texture.t4.weight, &mlx.texture.t4.height);
	if (!(mlx.mlx_addr = mlx_get_data_addr(mlx.mlx_img, &mlx.mlx_bits_per_pixel, &mlx.mlx_line_length, &mlx.mlx_endian)))
		exit(0);
	mlx.texture.t1.mlx_addr = (int *)mlx_get_data_addr(mlx.texture.t1.mlx_img, &mlx.texture.t1.mlx_bits_per_pixel, &mlx.texture.t1.mlx_line_length, &mlx.texture.t1.mlx_endian);
	mlx.texture.t2.mlx_addr = (int *)mlx_get_data_addr(mlx.texture.t2.mlx_img, &mlx.texture.t2.mlx_bits_per_pixel, &mlx.texture.t2.mlx_line_length, &mlx.texture.t2.mlx_endian);
	mlx.texture.t3.mlx_addr = (int *)mlx_get_data_addr(mlx.texture.t3.mlx_img, &mlx.texture.t3.mlx_bits_per_pixel, &mlx.texture.t3.mlx_line_length, &mlx.texture.t3.mlx_endian);
	mlx.texture.t4.mlx_addr = (int *)mlx_get_data_addr(mlx.texture.t4.mlx_img, &mlx.texture.t4.mlx_bits_per_pixel, &mlx.texture.t4.mlx_line_length, &mlx.texture.t4.mlx_endian);
	 while (vector < M_PI / 6)
	 {
	 	trace(&mlx, vector, (int)x);
	 	x += 1;
	 	vector += step;
	 }
//	drawMap(&mlx);
//	drawPlayer(&mlx, mlx.player.player_x / 4, mlx.player.player_y / 4);
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.mlx_img, 0, 0);
	mlx_hook(mlx.mlx_win, 2, 0L, key_press, &mlx);
//	mlx_hook(mlx.mlx_win, 17, 0L, close, &mlx);
	mlx_loop(mlx.mlx);
    return (0);
}
