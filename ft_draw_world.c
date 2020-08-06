#include "ft_trace.h"

void 	ft_check_len_to_wall(t_trace *trace, t_mlx *mlx)
{
	if (trace->first_point_ax == mlx->player.player_x && trace->first_point_ay == mlx->player.player_y)
		trace->len1 = INFINITY;
	else
		trace->len1 = sqrt(pow((mlx->player.player_x - trace->first_point_ax), 2.0) + pow((mlx->player.player_y - trace->first_point_ay), 2.0));
	if (trace->first_point_bx == mlx->player.player_x && trace->first_point_by == mlx->player.player_y)
		trace->len2 = INFINITY;
	else
		trace->len2 = sqrt(pow((mlx->player.player_x - trace->first_point_bx), 2.0) + pow((mlx->player.player_y - trace->first_point_by), 2.0));
	if (trace->len1 > trace->len2)
	{
		trace->len_line = trace->len2;
		trace->tx = (int)trace->first_point_by * 2;
		trace->check_2 = trace->flag2;
	}
	else
	{
		trace->len_line = trace->len1;
		trace->tx = (int)trace->first_point_ax * 2;
		trace->check_1 = trace->flag1;
	}
}

void 	ft_get_wall_size(t_trace *trace, t_mlx *mlx, int x)
{
	mlx->texture.arr_len_trace[x] = trace->len_line;
	trace->len_line = trace->len_line * cos(mlx->player.player_angle - trace->angle);
	trace->len_to_viewport = (((unsigned int)mlx->map.R.width >> 1u) / tan(M_PI / 6.0));
	trace->projected_slice_height = (trace->len_to_viewport / (64 * trace->len_line)) * mlx->map.R.height;
	trace->up_start = (int)(((unsigned int)mlx->map.R.height >> 1u) - trace->projected_slice_height) ;
	trace->h_texture = 64;
	trace->h_koef = trace->h_texture / (trace->projected_slice_height * 2);
	trace->save = trace->up_start;
	if (trace->up_start <= 0)
		trace->up_start = 0;
	trace->down_stop = (int)(((unsigned int )mlx->map.R.height >> 1u) + trace->projected_slice_height);
	if (trace->down_stop >= mlx->map.R.height)
		trace->down_stop = mlx->map.R.height - 1;
}

void 	ft_draw_roof(t_trace *trace, t_mlx *mlx, int x)
{
	trace->k = 0;
	while (trace->k < trace->up_start)
	{
		trace->dst = mlx->mlx_addr + (abs(trace->k) * mlx->mlx_line_length + abs(x) * ((unsigned int)mlx->mlx_bits_per_pixel >> 3u));
		*(unsigned int*)trace->dst = 0x0087CEEB;
		trace->k++;
	}
}

void 	ft_draw_wall(t_trace *trace, t_mlx *mlx, int x)
{
	while (trace->up_start < trace->down_stop)
	{
		trace->h_k = (int)((trace->up_start - trace->save) * trace->h_koef);
		if (trace->check_1 == 1)
			trace->color = mlx->texture.t1.mlx_addr[trace->h_k * mlx->texture.t1.height + (abs(trace->tx - WIDTH) % mlx->texture.t1.weight)];
		else if (trace->check_1 == 2)
			trace->color = mlx->texture.t2.mlx_addr[trace->h_k * mlx->texture.t2.height + (abs(trace->tx - WIDTH) % mlx->texture.t2.weight)];
		else if (trace->check_2 == 1)
			trace->color = mlx->texture.t3.mlx_addr[trace->h_k * mlx->texture.t3.height + (abs(trace->tx - WIDTH) % mlx->texture.t3.weight)];
		else
			trace->color = mlx->texture.t4.mlx_addr[trace->h_k * mlx->texture.t4.height + (abs(trace->tx - WIDTH) % mlx->texture.t4.weight)];
		my_mlx_pixel_put(mlx, x, trace->up_start, trace->color);
		trace->up_start++;
	}
}

void	ft_draw_floor(t_trace *trace, t_mlx *mlx, int x)
{
	trace->k = trace->down_stop;
	while (trace->k < HEIGHT - 1)
	{
		trace->dst = mlx->mlx_addr + (abs(trace->k) * mlx->mlx_line_length + abs(x) * ((unsigned int)mlx->mlx_bits_per_pixel >> 3u));
		*(unsigned int*)trace->dst = 0x003CB371;
		trace->k++;
	}
}