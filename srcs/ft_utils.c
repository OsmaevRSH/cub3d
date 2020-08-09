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

#include "../includes/ft_trace.h"

void				my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char			*dst;

	dst = mlx->mlx_addr + (abs(y) * mlx->mlx_line_length + abs(x) *
					((unsigned int)mlx->mlx_bits_per_pixel >> 3u));
	*(unsigned int*)dst = color;
}

void				ft_draw_map(t_mlx *mlx)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	map_x;
	unsigned int	map_y;

	x = 0;
	y = 0;
	map_x = mlx->count_elem_in_line_map + 2;
	map_y = mlx->count_lines_in_map + 2;
	while (x < map_x << 3u)
	{
		while (y < map_y << 3u)
		{
			if (mlx->map.worldMap[y >> 3u][x >> 3u] == '1')
				my_mlx_pixel_put(mlx, (int)x, (int)y, 0x0000FF00);
			else if (mlx->map.worldMap[y >> 3u][x >> 3u] == '2')
				my_mlx_pixel_put(mlx, (int)x, (int)y, 0x00000000);
			else
				my_mlx_pixel_put(mlx, (int)x, (int)y, 0x000000FF);
			y++;
		}
		y = 0;
		x++;
	}
}

void				ft_draw_sprite(t_mlx *mlx, double x, double y)
{
	int				len_line;
	double			i;
	double			tmp_x;
	double			tmp_y;

	len_line = 16;
	i = 0;
	tmp_x = x - 4;
	tmp_y = y - 4;
	while (i <= len_line)
	{
		my_mlx_pixel_put(mlx, (int)(x + i * cos(mlx->player.angle)),
				(int)(y + i * sin(mlx->player.angle)), mlx->color.RED);
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

int					ft_get_color_from_rgb(int r, int g, int b)
{
	int				color;

	color = r << 16 | g << 8 | b;
	return (color);
}

void				ft_search_rectangle(t_mlx *mlx, t_trace *trace, int flag)
{
	if (flag)
	{
		while (trace->first_point_ax > 0 && trace->first_point_ay > 0 &&
		trace->first_point_ax < (unsigned int)mlx->count_elem_in_line_map << 6u
		&& trace->first_point_ay < (unsigned int)mlx->count_lines_in_map << 6u
		&& mlx->map.worldMap[(unsigned int)trace->first_point_ay >> 6u]
		[(unsigned int)trace->first_point_ax >> 6u] != '1')
		{
			if (!search_wall_for_point_a(trace))
				break ;
		}
	}
	else
	{
		while (trace->first_point_bx > 0 && trace->first_point_by > 0 &&
		trace->first_point_bx < (unsigned int)mlx->count_elem_in_line_map << 6u
		&& trace->first_point_by < (unsigned int)mlx->count_lines_in_map << 6u
		&& mlx->map.worldMap[(unsigned int)trace->first_point_by >> 6u]
		[(unsigned int)trace->first_point_bx >> 6u] != '1')
		{
			if (!search_wall_for_point_b(trace))
				break ;
		}
	}
}
