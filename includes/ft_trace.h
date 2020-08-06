#ifndef FT_TRACE_H
#define FT_TRACE_H

#include "cub3d.h"

typedef struct	s_trace
{
	double		projected_slice_height;
	double		first_point_ax;
	double		first_point_ay;
	double		first_point_bx;
	double		first_point_by;
	double		len1;
	double		len2;
	double		len_line;
	double		i;
	double		angle;
	double		len_to_viewport;
	double		h_koef;
	int			up_start;
	int			h_texture;
	int			down_stop;
	int			save;
	int			color;
	int			check_1;
	int			check_2;
	int			flag1;
	int			flag2;
	int			tx;
	int			h_k;
	int			k;
	char		*dst;
}				t_trace;

void			ft_check_len_to_wall(t_trace *trace, t_mlx *mlx);
void			ft_get_wall_size(t_trace *trace, t_mlx *mlx, int x);
void			ft_draw_roof(t_trace *trace, t_mlx *mlx, int x);
void			ft_draw_wall(t_trace *trace, t_mlx *mlx, int x);
void			ft_draw_floor(t_trace *trace, t_mlx *mlx, int x);
void			ft_init_tracer_struct(t_trace *trace);

#endif
