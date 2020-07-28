#ifndef CUB3D_H
#define CUB3D_H

#include "mlx/mlx.h"
#include <stdlib.h>
#include "math.h"
# define WIDTH 2560
# define HEIGHT 1440
# define mapWidth 24
# define mapHeight 28

int worldMap[mapWidth][mapHeight]=
		{
				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1},
				{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,1,1,1},
				{1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1},
				{1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1},
				{1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
				{1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,1,1,1,1},
				{1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,1,0,0,0,1},
				{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
		};

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
}               t_mlx;

void    drawPlayer(t_mlx *mlx, double x, double y);
void	drawMap(t_mlx *mlx);
void    trace(t_mlx *mlx, double vector, int x);
void 	drawFlor(t_mlx *mlx);

#endif
