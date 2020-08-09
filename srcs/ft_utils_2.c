#include "../includes/cub3d.h"

int close_window(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	exit(0);
}

