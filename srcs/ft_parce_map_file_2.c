/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parce_map_file_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheresi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 20:44:40 by ltheresi          #+#    #+#             */
/*   Updated: 2020/08/10 20:44:42 by ltheresi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			ft_gettex(t_mlx *mlx, int *flag, char **mlx_str)
{
	int		fd;

	fd = open(mlx->str_1, O_RDONLY);
	if (fd != -1 &&
		ft_check_file_extension(mlx->str_1, "xpm") && mlx->str_2 == NULL)
	{
		*flag = 1;
		close(fd);
		*mlx_str = ft_strdup(mlx->str_1);
		return (0);
	}
	else
	{
		if (fd != -1)
		{
			ft_putstr_fd("Error:\nInvalid texture\n", 1);
			return (1);
		}
		perror("Texture error");
		return (1);
	}
}

int			ft_if_for_get_color(char **color, t_color_f_and_r *data)
{
	if (color[3] == NULL)
	{
		if (ft_isdigit_from_string(color[0]) && ft_atoi(color[0])
			>= 0 && ft_atoi(color[0]) <= 255
			&& ft_isdigit_from_string(color[1]) && ft_atoi(color[1])
			>= 0 && ft_atoi(color[1]) <= 255
			&& ft_isdigit_from_string(color[2]) && ft_atoi(color[2])
			>= 0 && ft_atoi(color[2]) <= 255)
		{
			(*data).r = ft_atoi(color[0]);
			(*data).g = ft_atoi(color[1]);
			(*data).b = ft_atoi(color[2]);
		}
		else
		{
			ft_putstr_fd("Error:\nInvalid color format\n", 1);
			return (1);
		}
	}
	return (0);
}

int			ft_get_color(t_mlx *mlx, int *flag, t_color_f_and_r *data)
{
	char	**color;
	int		i;

	i = 0;
	if (mlx->str_1 && mlx->str_2 == NULL)
	{
		*flag = 1;
		color = ft_split(mlx->str_1, ',');
		if (ft_if_for_get_color(color, data))
			return (1);
		while (color[i] != NULL)
			free(color[i++]);
		free(color);
	}
	else
	{
		ft_putstr_fd("Error:\nInvalid color format\n", 1);
		return (1);
	}
	return (0);
}

int			ft_get_resolution_size(t_mlx *mlx,
			const char *str_3, int *flag, t_screen_size *data)
{
	int w;
	int h;

	mlx_get_screen_size(mlx->mlx, &w, &h);
	if (ft_isdigit_from_string(mlx->str_1) &&
		ft_isdigit_from_string(mlx->str_2) && str_3 == NULL)
	{
		*flag = 1;
		(*data).width = ft_atoi(mlx->str_1);
		if ((*data).height > h)
			(*data).height = h;
		if ((*data).height < 200)
			(*data).height = 200;
		(*data).height = ft_atoi(mlx->str_2);
		if ((*data).width > w)
			(*data).width = w;
		if ((*data).width < 320)
			(*data).width = 320;
		return (0);
	}
	else
	{
		ft_putstr_fd("Error:\nInvali format resolution\n", 1);
		return (1);
	}
}

void		ft_get_map(t_check flag, char *line, int fd, t_mlx *mlx)
{
	if (flag.f && flag.s && flag.ea &&
		flag.we && flag.so && flag.no && flag.r && flag.c)
	{
		if (!(line = ft_parce_map(fd, line, mlx)))
		{
			ft_putstr_fd("Error:\nMap incorrect", 1);
			ft_free_mlx(mlx, 1);
		}
		mlx->map.world_map = ft_split(line, '\n');
		free(line);
		check_map(mlx->map.world_map, mlx);
	}
	else
	{
		ft_putstr_fd("Error:\nInvalid map file\n", 1);
		ft_free_mlx(mlx, 1);
	}
}
