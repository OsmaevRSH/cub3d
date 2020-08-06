#include "ft_trace.h"

void	ft_init_tracer_struct(t_trace *trace)
{
	trace->projected_slice_height = 0;
	trace->first_point_ax = 0;
	trace->first_point_ay = 0;
	trace->first_point_bx = 0;
	trace->first_point_by = 0;
	trace->len1 = 0;
	trace->len2 = 0;
	trace->len_line = 0;
	trace->i = 0;
	trace->angle = 0;
	trace->len_to_viewport = 0;
	trace->h_koef = 0;
	trace->up_start = 0;
	trace->h_texture = 0;
	trace->down_stop = 0;
	trace->save = 0;
	trace->color = 0;
	trace->check_1 = 0;
	trace->check_2 = 0;
	trace->flag1 = 0;
	trace->flag2 = 0;
	trace->tx = 0;
	trace->h_k = 0;
	trace->k = 0;
	trace->dst = 0;
}

void	ft_init_draw_sprite_struct(t_draw_sprite *sprite)
{
	sprite->i = 0;
	sprite->j = 0;
	sprite->h_k = 0;
	sprite->w_k = 0;
	sprite->check_x = 0;
	sprite->check_y = 0;
	sprite->color = 0;
	sprite->x_offset = 0;
	sprite->y_offset = 0;
	sprite->sprite_screen_size = 0;
	sprite->save = 0;
	sprite->step_for_angle = 0;
	sprite->sprite_dir = 0;
	sprite->angel = 0;
	sprite->sprite_dist = 0;
	sprite->h_koef = 0;
}