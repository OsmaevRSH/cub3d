#include "cub3d.h"
#include "stdio.h"

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
	player->player_x = 300;
	player->player_y = 300;
	player->player_angle = (3.0 / 2.0) * PI;
}

void	replace(t_mlx *mlx)
{
	double vector = - PI / 6;
	mlx_destroy_image(mlx->mlx, mlx->mlx_img);
	if(!(mlx->mlx_img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT)))
		exit(0);
	if(!(mlx->mlx_addr = mlx_get_data_addr(mlx->mlx_img, &mlx->mlx_bits_per_pixel, &mlx->mlx_line_length, &mlx->mlx_endian)))
		exit(0);
	drawMap(mlx);
	drawPlayer(mlx, mlx->player.player_x, mlx->player.player_y);
	while (vector < PI / 6)
	{
		trace(mlx, vector);
		vector += 0.01;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, mlx->mlx_img, 0, 0);
}

int  key_press(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 13) //w
    {
        mlx->player.player_y += 10 * sin(mlx->player.player_angle);
        mlx->player.player_x += 10 * cos(mlx->player.player_angle);
    }
	if (keycode == 0) //a
	{
		mlx->player.player_angle -= 0.05;
		if (mlx->player.player_angle < 0)
			mlx->player.player_angle += 2.0 * PI;
	}
	if (keycode == 1) //s
    {
        mlx->player.player_y -= 10 * sin(mlx->player.player_angle);
        mlx->player.player_x -= 10 * cos(mlx->player.player_angle);
    }
	if (keycode == 2) //d
	{
		mlx->player.player_angle += 0.05;
		if (mlx->player.player_angle > 2.0 * PI)
			mlx->player.player_angle -= 2.0 * PI;
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
				my_mlx_pixel_put(mlx, x, y, mlx->color.GREEN);
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

void    trace(t_mlx *mlx, double vector)
{
	double angle = mlx->player.player_angle + vector;
	if (angle > 2*PI)
		angle -= 2*PI;
	if (angle < 0)
		angle += 2*PI;
    double first_point_ax;
    double first_point_ay;
    double first_point_bx;
    double first_point_by;
    double len1;
    double len2;
    double len_line;
    double i = 0;

    if ((angle > 0 && angle < PI)) // 1 and 2
        first_point_ay = (int)(mlx->player.player_y / 32) * 32 + 32;
    else if ((angle > PI && angle < 2 * PI)) // 3 and 4
        first_point_ay = (int)(mlx->player.player_y / 32) * 32 - 1;
    else
        first_point_ay = mlx->player.player_y;

	if (angle >= 0 && angle <  (PI / 2.0)) // 1
		first_point_ax = mlx->player.player_x + (first_point_ay - mlx->player.player_y) * tan((PI / 2.0) - angle);
	else if (angle > (PI / 2.0) && angle <= PI) // 2
		first_point_ax = mlx->player.player_x - (first_point_ay - mlx->player.player_y) * tan(angle - (PI / 2.0));
	else if (angle >= PI && angle < (3.0 / 2.0) * PI) // 3
		first_point_ax = mlx->player.player_x - (mlx->player.player_y - first_point_ay) * tan((3.0 / 2.0) * PI - angle);
	else if (angle > (3.0 / 2.0) * PI && angle <= 2 * PI) // 4
		first_point_ax = mlx->player.player_x + (mlx->player.player_y - first_point_ay) * tan(angle - (3.0 / 2.0) * PI);
	else
		first_point_ax = mlx->player.player_x;

	while (worldMap[(int)first_point_ay / 32][(int)first_point_ax / 32] != 1 && first_point_ax > 0 && first_point_ay > 0 && first_point_ax < WIDTH && first_point_ay < HEIGHT)
	{
		if (angle > 0 && angle <= (PI / 2.0))
		{
			first_point_ax += 32 * tan((PI / 2.0) - angle);
			first_point_ay += 32;
		}
		else if (angle > (PI / 2.0) && angle < PI)
		{
			first_point_ax -= 32 * tan(angle - (PI / 2.0));
			first_point_ay += 32;
		}
		else if (angle > PI && angle <= (3.0 / 2.0) * PI)
		{
			first_point_ax -= 32 * tan((3.0 / 2.0) * PI - angle);
			first_point_ay -= 32;
		}
		else if (angle > (3.0 / 2.0) * PI && angle < 2 * PI)
		{
			first_point_ax += 32 * tan(angle - (3.0 / 2.0) * PI);
			first_point_ay -= 32;
		}
		else
			break;
	}
	/*================================================================================================================================================================================*/
	if ((angle >= 0 && angle < (PI / 2.0)) || (angle > (3.0 / 2.0) * PI && angle <= 2 * PI)) // 1 and 4
		first_point_bx = (int)(mlx->player.player_x / 32) * 32 + 32;
	else if ((angle > (PI / 2.0) && angle <= PI) || (angle > PI && angle < (3.0 / 2.0) * PI)) // 2 and 3
		first_point_bx = (int)(mlx->player.player_x / 32) * 32 - 1;
	else
		first_point_bx = mlx->player.player_x;

	if (angle >= 0 && angle < (PI / 2.0)) // 1
		first_point_by = mlx->player.player_y + (first_point_bx - mlx->player.player_x) * tan(angle);
	else if (angle > (PI / 2.0) && angle <= PI) // 2
		first_point_by = mlx->player.player_y + (mlx->player.player_x - first_point_bx) * tan(PI - angle);
	else if (angle > PI && angle < (3.0 / 2.0) * PI) // 3
		first_point_by = mlx->player.player_y - (mlx->player.player_x - first_point_bx) * tan(angle - PI);
	else if (angle > (3.0 / 2.0) * PI && angle <= 2 * PI) // 4
		first_point_by = mlx->player.player_y - (first_point_bx - mlx->player.player_x) * tan(2 * PI - angle);
	else
		first_point_by = mlx->player.player_y;
	while (worldMap[(int)first_point_by / 32][(int)first_point_bx / 32] != 1 && first_point_bx > 0 && first_point_by > 0 && first_point_bx < WIDTH && first_point_by < HEIGHT)
	{
		printf("%d\n", worldMap[(int)first_point_by / 32][(int)first_point_bx / 32]);
		if (angle >= 0 && angle < (PI / 2.0))
		{
			first_point_bx += 32;
			first_point_by += 32 * tan(angle);
		}
		else if (angle > (PI / 2.0) && angle <= PI)
		{
			first_point_bx -= 32;
			first_point_by += 32 * tan(PI - angle);
		}
		else if (angle > PI && angle < (3.0 / 2.0) * PI)
		{
			first_point_bx -= 32;
			first_point_by -= 32 * tan(angle - PI);
		}
		else if (angle > (PI / 2.0) * 3 && angle <= 2 * PI)
		{
			first_point_bx += 32;
			first_point_by -= 32 * tan(2 * PI - angle);
		}
		else
			break;
	}
	if (first_point_ax == mlx->player.player_x && first_point_ay == mlx->player.player_y)
		len1 = INFINITY;
	else
		len1 = sqrt(fabs(mlx->player.player_x - first_point_ax) * fabs(mlx->player.player_x - first_point_ax) + fabs(mlx->player.player_y - first_point_ay) * fabs(mlx->player.player_y - first_point_ay));
	if (first_point_bx == mlx->player.player_x && first_point_by == mlx->player.player_y)
		len2 = INFINITY;
	else
		len2 = sqrt(fabs(mlx->player.player_x - first_point_bx) * fabs(mlx->player.player_x - first_point_bx) + fabs(mlx->player.player_y - first_point_by) * fabs(mlx->player.player_y - first_point_by));
	len_line = len1 > len2 ? len2 : len1;
	if (len_line != INFINITY)
	{
		while (i <= len_line)
		{
			my_mlx_pixel_put(mlx, (int)(mlx->player.player_x + i * cos(angle)), (int)(mlx->player.player_y + i * sin(angle)), mlx->color.BLACK);
			i++;
		}
	}
}

int         main()
{
	t_mlx   mlx;
	double vector = - PI / 6;

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
	while (vector < PI / 6)
	{
		trace(&mlx, vector);
		vector += 0.01;
	}
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.mlx_img, 0, 0);
	mlx_hook(mlx.mlx_win, 2, 0L, key_press, &mlx);
	mlx_loop(mlx.mlx);
    return (0);
}