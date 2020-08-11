/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheresi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 20:53:32 by ltheresi          #+#    #+#             */
/*   Updated: 2020/08/06 20:53:34 by ltheresi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include <stdlib.h>
# include "math.h"
# include "../libft/libft.h"
# include "fcntl.h"
# include "stdio.h"
# include "errno.h"
# include "string.h"
# define SPEED	10

typedef struct			s_screen_size
{
	int					width;
	int					height;
	int					flag;
}						t_screen_size;

typedef struct			s_color_floor_and_roof
{
	int					r;
	int					g;
	int					b;
}						t_color_f_and_r;

typedef struct			s_parce_map_file
{
	t_screen_size		r;
	char				*no;
	char				*so;
	char				*we;
	char				*ea;
	char				*s;
	char				*ss;
	t_color_f_and_r		f;
	t_color_f_and_r		c;
	char				**world_map;

}						t_parce;

typedef struct			s_draw_sprite
{
	int					i;
	int					j;
	int					h_k;
	int					w_k;
	int					check_x;
	int					check_y;
	int					color;
	int					x_offset;
	int					y_offset;
	int					spr_sc_size;
	double				save;
	double				st_for_an;
	double				sprite_dir;
	double				angel;
	double				sprite_dist;
	double				h_koef;
}						t_draw_sprite;

typedef struct			s_sprite
{
	double				x;
	double				y;
	size_t				tex_id;
	int					id;
	double				distance;
	struct s_sprite		*next;
}						t_sprite;

typedef struct			s_texture
{
	void				*mlx_img;
	int					*mlx_addr;
	int					mlx_bits_per_pixel;
	int					mlx_line_length;
	int					mlx_endian;
	int					weight;
	int					height;
}						t_texture;

typedef struct			s_save_text
{
	t_texture			t1;
	t_texture			t2;
	t_texture			t3;
	t_texture			t4;
	t_texture			sprite_1;
	t_texture			sprite_2;
	double				*arr_len_trace;
}						t_save_text;

typedef struct			s_map_len
{
	int					len;
	char				*str;
	struct s_map_len	*next;
}						t_map_len;

typedef struct			s_player
{
	double				x;
	double				y;
	double				angle;
	int					rectangle_x;
	int					rectangle_y;
	int					tilt;
}						t_player;

typedef struct			s_mlx
{
	void				*mlx;
	void				*mlx_win;
	void				*mlx_img;
	char				*mlx_addr;
	int					mlx_bits_per_pixel;
	int					mlx_line_length;
	int					mlx_endian;
	int					collect_sprites;
	int					count_lines_in_map;
	int					count_elem_in_line_map;
	int					fd;
	int					check;
	struct s_sprite		*head_for_sprite_list;
	struct s_map_len	*head_for_map_len_list;
	char				*str_1;
	char				*str_2;
	t_player			player;
	t_save_text			texture;
	t_parce				map;
	t_sprite			sprite;
	t_draw_sprite		dr_spr;
}						t_mlx;

typedef struct			s_check
{
	int					r;
	int					no;
	int					so;
	int					we;
	int					ea;
	int					s;
	int					f;
	int					c;
	int					ss;
}						t_check;

typedef struct			s_trace
{
	double				projected_slice_height;
	double				first_point_ax;
	double				first_point_ay;
	double				first_point_bx;
	double				first_point_by;
	double				len1;
	double				len2;
	double				len_line;
	double				i;
	double				angle;
	double				len_to_viewport;
	double				h_koef;
	int					up_start;
	int					h_texture;
	int					down_stop;
	int					save;
	int					color;
	int					check_1;
	int					check_2;
	int					flag1;
	int					flag2;
	int					tx;
	int					h_k;
	int					k;
	char				*dst;
}						t_trace;

void					ft_draw_sprite(t_mlx *mlx, double x, double y);
void					ft_draw_map(t_mlx *mlx);
void					trace(t_mlx *mlx, double vector, int x);
void					ft_parce(char *file_name, t_mlx *mlx);
char					*ft_parce_map(int fd, char *line, t_mlx *mlx);
int						check(char **map, int x, int y);
void					check_map(char **map, t_mlx *mlx);
int						ft_count_sprites(t_sprite *head);
t_sprite				*ft_search_sprite(size_t id, t_sprite *head);
int						save_bmp(t_mlx *mlx);
void					my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
int						ft_draw_sprite_one(t_mlx *mlx);
void					ft_draw_sprite_two(t_mlx *mlx);
void					ft_draw_sprite_three(t_mlx *mlx,
						t_sprite *sprite, int save);
void					ft_push_back_new_sprite(int x, int y,
						t_sprite **head, int text_id);
void					ft_swap_elem_in_list(t_sprite *first,
						t_sprite *second, t_sprite **head);
void					ft_list_sort(t_sprite **sprite);
double					ft_get_distance(t_mlx *mlx, t_sprite *sprite);
void					replace(t_mlx *mlx, double vector,
						double step, int flag);
int						key_press(int keycode, t_mlx *mlx);
void					my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
int						close_window(t_mlx *mlx);
void					ft_init_textures(t_mlx *mlx);
int						ft_get_color_from_rgb(int r, int g, int b);
void					ft_lst_map_add(int len, char *str, t_map_len **head);
int						ft_search_max_len_in_lst(t_map_len **head);
void					ft_delete_sprite_by_rectangle(t_sprite **head,
						int x_rectangle, int y_rectangle);
void					draw_sprite(t_mlx *mlx, t_sprite *sprite);
void					ft_free_mlx(t_mlx *mlx, int flag);
void					ft_check_len_to_wall(t_trace *trace, t_mlx *mlx);
void					ft_get_wall_size(t_trace *trace, t_mlx *mlx, int x);
void					ft_draw_roof(t_trace *trace, t_mlx *mlx, int x);
void					ft_draw_wall(t_trace *trace, t_mlx *mlx, int x);
void					ft_draw_floor(t_trace *trace, t_mlx *mlx, int x);
int						search_wall_for_point_a(t_trace *trace);
int						search_wall_for_point_b(t_trace *trace);
void					ft_search_rectangle(t_mlx *mlx,
						t_trace *trace, int flag);
int						ft_gettex(t_mlx *mlx, int *flag, char **mlx_str);
int						ft_if_for_get_color(char **color,
						t_color_f_and_r *data);
int						ft_get_color(t_mlx *mlx,
						int *flag, t_color_f_and_r *data);
int						ft_get_resolution_size(t_mlx *mlx, const char *str_3,
						int *flag, t_screen_size *data);
void					ft_get_map(t_check flag,
						char *line, int fd, t_mlx *mlx);
void					check_count_player_in_map(const char *str, t_mlx *mlx);
void					ft_get_all_param_without_map(t_mlx *mlx,
						char **split_str, t_check *flag, char *line);
void					ft_key_events(int keycode, t_mlx *mlx);
void					ft_left_right(int keycode, t_mlx *mlx);
void					ft_tilt_up_down(int keycode, t_mlx *mlx);
void					ft_go_left_right(int keycode, t_mlx *mlx);
void					ft_go_forward_back(int keycode, t_mlx *mlx);
#endif
