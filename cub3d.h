#ifndef CUB3D_H
#define CUB3D_H

#include "mlx/mlx.h"
# include <stdlib.h>
# include "math.h"
# include "libft/libft.h"
# include "fcntl.h"
# include "stdio.h"
# define WIDTH 1920
# define HEIGHT 1080
# define mapWidth 39
# define mapHeight 16

typedef struct	s_screen_size
{
	int width;
	int height;
}				t_screen_size;

typedef struct	s_color_floor_and_roof
{
	int r;
	int g;
	int b;
}				t_color_f_and_r;

typedef struct	parce_map_file
{
	t_screen_size R;
	char *NO;
	char *SO;
	char *WE;
	char *EA;
	char *S;
	t_color_f_and_r F;
	t_color_f_and_r C;
	char **worldMap;

}				t_parce;

typedef struct	s_sprite
{
	double x;
	double y;
	size_t tex_id;
}				t_sprite;

typedef struct s_texture
{
	void		*mlx_img;
	int			*mlx_addr;
	int			mlx_bits_per_pixel;
	int			mlx_line_length;
	int			mlx_endian;
	int 		weight;
	int			height;
}				t_texture;

typedef struct s_save_text
{
	t_texture t1;
	t_texture t2;
	t_texture t3;
	t_texture t4;
}			t_save_text;



typedef struct  s_player //player position
{
	double		player_x;
	double		player_y;
	double		player_angle;
	int 		player_rectangle_x;
	int 		player_rectangle_y;
}               t_player;

typedef struct  s_color
{
	int			RED;
	int			GREEN;
	int			BLUE;
	int         WHITE;
	int 		BLACK;
}               t_color;

typedef struct  s_mlx
{
	void		*mlx;
	void		*mlx_win;
	void		*mlx_img;
	char		*mlx_addr;
	int			mlx_bits_per_pixel;
	int			mlx_line_length;
	int			mlx_endian;
	t_player	player;
	t_color		color;
	t_save_text texture;
	t_parce 	map;
	t_sprite	sprite;
}               t_mlx;

typedef struct	s_check
{
	int R;
	int NO;
	int SO;
	int WE;
	int EA;
	int S;
	int F;
	int C;
}				t_check;

void    	drawPlayer(t_mlx *mlx, double x, double y);
void		drawMap(t_mlx *mlx);
void    	trace(t_mlx *mlx, double vector, int x);
void		ft_parce(char *file_name, t_mlx *mlx);
char		*ft_parce_map(int fd, char *line, t_mlx *mlx);
int			check_map(char **map, t_mlx *mlx);
void 		draw_Sprite(t_mlx *mlx);
#endif
