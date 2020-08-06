/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheresi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 20:52:27 by ltheresi          #+#    #+#             */
/*   Updated: 2020/08/06 20:52:30 by ltheresi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

int		ft_get_color_from_rgb(int r, int g, int b)
{
	int color;

	color = r << 16 | g << 8 | b;
	return (color);
}
