/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheresi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 20:52:16 by ltheresi          #+#    #+#             */
/*   Updated: 2020/08/06 20:52:20 by ltheresi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_trace.h"

static void		search_first_point_a(t_trace *trace, t_mlx *mlx)
{
	if ((trace->angle > 0 && trace->angle < M_PI) && (trace->flag1 = 1))
		trace->first_point_ay = ((unsigned int)(mlx->player.y / 64) << 6u) + 64;
	else if ((trace->angle > M_PI && trace->angle < 2 * M_PI) &&
	(trace->flag1 = 2))
		trace->first_point_ay = ((unsigned int)(mlx->player.y / 64)
				<< 6u) - 0.00000001;
	else
		trace->first_point_ay = mlx->player.y;
	if (trace->angle >= 0 && trace->angle < (M_PI_2))
		trace->first_point_ax = mlx->player.x + (trace->first_point_ay
				- mlx->player.y) * tan((M_PI_2) - trace->angle);
	else if (trace->angle > (M_PI_2) && trace->angle <= M_PI)
		trace->first_point_ax = mlx->player.x - (trace->first_point_ay
				- mlx->player.y) * tan(trace->angle - (M_PI_2));
	else if (trace->angle >= M_PI && trace->angle < 3.0 * M_PI_2)
		trace->first_point_ax = mlx->player.x - (mlx->player.y
				- trace->first_point_ay) * tan(3.0 * M_PI_2 - trace->angle);
	else if (trace->angle > 3.0 * M_PI_2 && trace->angle <= 2 * M_PI)
		trace->first_point_ax = mlx->player.x + (mlx->player.y
				- trace->first_point_ay) * tan(trace->angle - 3.0 * M_PI_2);
	else
		trace->first_point_ax = mlx->player.x;
}

static void		search_first_point_b(t_trace *trace, t_mlx *mlx)
{
	if (((trace->angle >= 0 && trace->angle < (M_PI_2)) || (trace->angle >
	3.0 * M_PI_2 && trace->angle <= 2 * M_PI)) && (trace->flag2 = 1))
		trace->first_point_bx = ((unsigned int)(mlx->player.x / 64) << 6u) + 64;
	else if (((trace->angle > (M_PI_2) && trace->angle <= M_PI) ||
	(trace->angle > M_PI && trace->angle < 3.0 * M_PI_2)) && (trace->flag2 = 2))
		trace->first_point_bx = ((unsigned int)(mlx->player.x / 64)
				<< 6u) - 0.00000001;
	else
		trace->first_point_bx = mlx->player.x;
	if (trace->angle >= 0 && trace->angle < (M_PI_2))
		trace->first_point_by = mlx->player.y + (trace->first_point_bx
				- mlx->player.x) * tan(trace->angle);
	else if (trace->angle > (M_PI_2) && trace->angle <= M_PI)
		trace->first_point_by = mlx->player.y + (mlx->player.x
				- trace->first_point_bx) * tan(M_PI - trace->angle);
	else if (trace->angle > M_PI && trace->angle < 3.0 * M_PI_2)
		trace->first_point_by = mlx->player.y - (mlx->player.x
				- trace->first_point_bx) * tan(trace->angle - M_PI);
	else if (trace->angle > 3.0 * M_PI_2 && trace->angle <= 2 * M_PI)
		trace->first_point_by = mlx->player.y - (trace->first_point_bx
				- mlx->player.x) * tan(2 * M_PI - trace->angle);
	else
		trace->first_point_by = mlx->player.y;
}

int				search_wall_for_point_a(t_trace *trace)
{
	if (trace->angle > 0 && trace->angle <= (M_PI_2))
	{
		trace->first_point_ax += 64 * tan((M_PI_2) - trace->angle);
		trace->first_point_ay += 64;
	}
	else if (trace->angle > (M_PI_2) && trace->angle < M_PI)
	{
		trace->first_point_ax -= 64 * tan(trace->angle - (M_PI_2));
		trace->first_point_ay += 64;
	}
	else if (trace->angle > M_PI && trace->angle <= 3.0 * M_PI_2)
	{
		trace->first_point_ax -= 64 * tan(3.0 * M_PI_2 - trace->angle);
		trace->first_point_ay -= 64;
	}
	else if (trace->angle > 3.0 * M_PI_2 && trace->angle < 2 * M_PI)
	{
		trace->first_point_ax += 64 * tan(trace->angle - 3.0 * M_PI_2);
		trace->first_point_ay -= 64;
	}
	else
		return (0);
	return (1);
}

int				search_wall_for_point_b(t_trace *trace)
{
	if (trace->angle >= 0 && trace->angle < (M_PI_2))
	{
		trace->first_point_bx += 64;
		trace->first_point_by += 64 * tan(trace->angle);
	}
	else if (trace->angle > (M_PI_2) && trace->angle <= M_PI)
	{
		trace->first_point_bx -= 64;
		trace->first_point_by += 64 * tan(M_PI - trace->angle);
	}
	else if (trace->angle > M_PI && trace->angle < 3.0 * M_PI_2)
	{
		trace->first_point_bx -= 64;
		trace->first_point_by -= 64 * tan(trace->angle - M_PI);
	}
	else if (trace->angle > (M_PI_2) * 3 && trace->angle <= 2 * M_PI)
	{
		trace->first_point_bx += 64;
		trace->first_point_by -= 64 * tan(2 * M_PI - trace->angle);
	}
	else
		return (0);
	return (1);
}

void			trace(t_mlx *mlx, double vector, int x)
{
	t_trace		trace;

	ft_bzero(&trace, sizeof(trace));
	trace.angle = mlx->player.angle + vector;
	trace.angle > 2 * M_PI ? trace.angle -= 2 * M_PI : 0;
	trace.angle < 0 ? trace.angle += 2 * M_PI : 0;
	search_first_point_a(&trace, mlx);
	ft_search_rectangle(mlx, &trace, 1);
	search_first_point_b(&trace, mlx);
	ft_search_rectangle(mlx, &trace, 0);
	ft_check_len_to_wall(&trace, mlx);
	if (trace.len_line != INFINITY)
	{
		ft_get_wall_size(&trace, mlx, x);
		ft_draw_roof(&trace, mlx, x);
		ft_draw_wall(&trace, mlx, x);
		ft_draw_floor(&trace, mlx, x);
	}
}
