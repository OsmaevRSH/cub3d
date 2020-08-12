/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parce_map_file_4.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheresi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:59:01 by ltheresi          #+#    #+#             */
/*   Updated: 2020/08/11 13:59:04 by ltheresi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		ft_get_all_param_without_map_2(t_mlx *mlx,
			char **split_str, t_check *flag, char *line)
{
	if (!ft_strncmp(split_str[0], "S", ft_strlen(split_str[0]))
	&& !ft_strncmp(split_str[0], "S", 1))
		mlx->check = ft_gettex(mlx, &flag->s,
		&mlx->map.s) == 0 ? 0 : 1;
	else if (!ft_strncmp(split_str[0], "SS", ft_strlen(split_str[0]))
	&& !ft_strncmp(split_str[0], "SS", 2))
		mlx->check = ft_gettex(mlx, &flag->ss,
		&mlx->map.ss) == 0 ? 0 : 1;
	else if (!ft_strncmp(split_str[0], "F", ft_strlen(split_str[0]))
	&& !ft_strncmp(split_str[0], "F", 1))
		mlx->check = ft_get_color(mlx, &flag->f,
		&mlx->map.f) == 0 ? 0 : 1;
	else if (!ft_strncmp(split_str[0], "C", ft_strlen(split_str[0]))
	&& !ft_strncmp(split_str[0], "C", 1))
		mlx->check = ft_get_color(mlx, &flag->c,
		&mlx->map.c) == 0 ? 0 : 1;
	else
		ft_get_map(*flag, line, mlx->fd, mlx);
}

void		ft_get_all_param_without_map(t_mlx *mlx,
			char **split_str, t_check *flag, char *line)
{
	if (!ft_strncmp(split_str[0], "R", ft_strlen(split_str[0])))
		mlx->check = ft_get_resolution_size(mlx,
		split_str[3], &flag->r, &mlx->map.r) == 0 ? 0 : 1;
	else if (!ft_strncmp(split_str[0], "NO", ft_strlen(split_str[0]))
	&& !ft_strncmp(split_str[0], "NO", 2))
		mlx->check = ft_gettex(mlx, &flag->no,
		&mlx->map.no) == 0 ? 0 : 1;
	else if (!ft_strncmp(split_str[0], "SO", ft_strlen(split_str[0]))
	&& !ft_strncmp(split_str[0], "SO", 2))
		mlx->check = ft_gettex(mlx, &flag->so,
		&mlx->map.so) == 0 ? 0 : 1;
	else if (!ft_strncmp(split_str[0], "WE", ft_strlen(split_str[0]))
	&& !ft_strncmp(split_str[0], "WE", 2))
		mlx->check = ft_gettex(mlx, &flag->we,
		&mlx->map.we) == 0 ? 0 : 1;
	else if (!ft_strncmp(split_str[0], "EA", ft_strlen(split_str[0]))
	&& !ft_strncmp(split_str[0], "EA", 2))
		mlx->check = ft_gettex(mlx, &flag->ea,
		&mlx->map.ea) == 0 ? 0 : 1;
	else
		ft_get_all_param_without_map_2(mlx,
		split_str, flag, line);
}
