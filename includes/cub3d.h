#ifndef CUB3D_H
#define CUB3D_H

#include		"../mlx/mlx.h"
# include		<stdlib.h>
# include		"math.h"
# include		"../libft/libft.h"
# include		"fcntl.h"
# include		"stdio.h"
# define WIDTH 1920
# define HEIGHT 1080
# define mapWidth 39
# define mapHeight 16

typedef struct		s_screen_size
{
	int				width;
	int				height;
}					t_screen_size;

typedef struct		s_color_floor_and_roof
{
	int				r;
	int				g;
	int				b;
}					t_color_f_and_r;

typedef struct		parce_map_file
{
	t_screen_size	R;
	char			*NO;
	char			*SO;
	char			*WE;
	char			*EA;
	char			*S;
	t_color_f_and_r	F;
	t_color_f_and_r	C;
	char			**worldMap;

}					t_parce;

typedef struct		s_draw_sprite
{
	int				i;
	int				j;
	int				h_k;
	int				w_k;
	int				check_x;
	int				check_y;
	int				color;
	int				x_offset;
	int				y_offset;
	int				sprite_screen_size;
	double			save;
	double			step_for_angle;
	double			sprite_dir;
	double			angel;
	double			sprite_dist;
	double			h_koef;
}					t_draw_sprite;

typedef struct		s_sprite
{
	double			x;
	double			y;
	size_t			tex_id;
	double			distance;
	struct s_sprite	*next;
}					t_sprite;

typedef struct		s_texture
{
	void			*mlx_img;
	int				*mlx_addr;
	int				mlx_bits_per_pixel;
	int				mlx_line_length;
	int				mlx_endian;
	int 			weight;
	int				height;
}					t_texture;

typedef struct		s_save_text
{
	t_texture		t1;
	t_texture		t2;
	t_texture		t3;
	t_texture		t4;
	t_texture		sprite;
	double			*arr_len_trace;
}					t_save_text;



typedef struct		s_player //player position
{
	double			x;
	double			y;
	double			angle;
	int 			rectangle_x;
	int 			rectangle_y;
}               	t_player;

typedef struct		s_color
{
	int				RED;
	int				GREEN;
	int				BLUE;
	int         	WHITE;
	int 			BLACK;
}               	t_color;

typedef struct		s_mlx
{
	void			*mlx;
	void			*mlx_win;
	void			*mlx_img;
	char			*mlx_addr;
	int				mlx_bits_per_pixel;
	int				mlx_line_length;
	int				mlx_endian;
	struct s_sprite	*head_for_sprite_list;
	t_player		player;
	t_color			color;
	t_save_text 	texture;
	t_parce 		map;
	t_sprite		sprite;
	t_draw_sprite	draw_sprite;
}					t_mlx;

typedef struct		s_check
{
	int				R;
	int				NO;
	int				SO;
	int				WE;
	int				EA;
	int				S;
	int				F;
	int				C;
}					t_check;

void    			drawPlayer(t_mlx *mlx, double x, double y);
void				drawMap(t_mlx *mlx);
void    			trace(t_mlx *mlx, double vector, int x);
void				ft_parce(char *file_name, t_mlx *mlx);
char				*ft_parce_map(int fd, char *line, t_mlx *mlx);
int					check_map(char **map, t_mlx *mlx);
void 				draw_Sprite(t_mlx *mlx);
int					check(char **map, int x, int y);
void				ft_push_back_new_sprite(int x, int y, size_t id, t_sprite **head);
int					ft_count_sprites(t_sprite *head);
t_sprite			*ft_search_sprite(size_t id, t_sprite *head);
int					save_bmp(t_mlx *mlx);
void        		my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
int					ft_draw_sprite_one(t_mlx *mlx);
void				ft_draw_sprite_two(t_mlx *mlx);
void				ft_draw_sprite_three(t_mlx *mlx);
void				ft_init_draw_sprite_struct(t_draw_sprite *sprite);
void				ft_swap_elem_in_list(t_sprite *first, t_sprite *second, t_sprite **head);
void				ft_list_sort(t_sprite **sprite);
double				ft_get_distance(t_mlx *mlx, t_sprite *sprite);
void				replace(t_mlx *mlx);
int					key_press(int keycode, t_mlx *mlx);
void				my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
int					close_window(t_mlx *mlx);
void				ft_init_textures(t_mlx *mlx);
#endif
