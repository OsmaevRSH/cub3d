#include "cub3d.h"

static void				ft_set_hex(int value, unsigned char *start)
{
	start[0] = (unsigned char)(value);
	start[1] = (unsigned char)((unsigned int)value >> 8u);
	start[2] = (unsigned char)((unsigned int)value >> 16u);
	start[3] = (unsigned char)((unsigned int)value >> 24u);
}

static int				ft_create_bitmap(int size_bitmap, int fd, t_mlx mlx)
{
	unsigned char		header[54];
	size_t				i;

	i = 0;
	while (i < 54)
		header[i++] = (unsigned char)0;
	header[0] = (unsigned char)'B';
	header[1] = (unsigned char)'M';
	ft_set_hex(size_bitmap, header + 2);
	ft_set_hex(54, header + 10);
	ft_set_hex(40, header + 14);
	ft_set_hex(mlx.map.R.width, header + 18);
	ft_set_hex(mlx.map.R.height, header + 22);
	header[26] = (unsigned char)1;
	header[28] = (unsigned char)24;
	return (write(fd, header, 54));
}

static int				ft_get_bitmap_color(t_mlx *mlx, int x, int y)
{
	char				*color;
	int					rgb;

	color = mlx->mlx_addr + (abs(y - mlx->map.R.height) * mlx->mlx_line_length + abs(x) * ((unsigned int)mlx->mlx_bits_per_pixel >> 3u));
	rgb = *(int *)color;
	return (rgb);
}

static void				ft_create_bitmap_raster_data(t_mlx *mlx, int fd)
{
	int					i;
	int					j;
	int					color;

	i = 0;
	j = 0;
	while (i < mlx->map.R.height)
	{
		while (j < mlx->map.R.width)
		{
			color = ft_get_bitmap_color(mlx, j, i);
			write(fd, &color, 3);
			j++;
		}
		j = 0;
		i++;
	}
}

int						save_bmp(t_mlx *mlx)
{
	int					fd;
	int					bitmap_size;

	fd = open("Screenshot.bmp", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0666);
	bitmap_size = (mlx->map.R.width * mlx->map.R.height * 4) + 54;
	ft_create_bitmap(bitmap_size, fd, *mlx);
	ft_create_bitmap_raster_data(mlx, fd);
	close(fd);
	return (0);
}