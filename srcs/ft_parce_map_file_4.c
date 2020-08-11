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
	if (!ft_strncmp(split_str[0], "S",
	ft_strlen(split_str[0])) && flag->S == 0)
		mlx->check = ft_gettex(mlx, &flag->S,
		&mlx->map.S) == 0 ? 0 : 1;
	else if (!ft_strncmp(split_str[0], "SS",
	ft_strlen(split_str[0])) && flag->SS == 0)
		mlx->check = ft_gettex(mlx, &flag->SS,
		&mlx->map.SS) == 0 ? 0 : 1;
	else if (!ft_strncmp(split_str[0], "F",
	ft_strlen(split_str[0])) && flag->F == 0)
		mlx->check = ft_get_color(mlx, &flag->F,
		&mlx->map.F) == 0 ? 0 : 1;
	else if (!ft_strncmp(split_str[0], "C",
	ft_strlen(split_str[0])) && flag->C == 0)
		mlx->check = ft_get_color(mlx, &flag->C,
		&mlx->map.C) == 0 ? 0 : 1;
	else
		ft_get_map(*flag, line, mlx->fd, mlx);
}

void		ft_get_all_param_without_map(t_mlx *mlx,
			char **split_str, t_check *flag, char *line)
{
	if (!ft_strncmp(split_str[0], "R",
	ft_strlen(split_str[0])) && flag->R == 0)
		mlx->check = ft_get_resolution_size(mlx,
		split_str[3], &flag->R, &mlx->map.R) == 0 ? 0 : 1;
	else if (!ft_strncmp(split_str[0], "NO",
	ft_strlen(split_str[0])) && flag->NO == 0)
		mlx->check = ft_gettex(mlx, &flag->NO,
		&mlx->map.NO) == 0 ? 0 : 1;
	else if (!ft_strncmp(split_str[0], "SO",
	ft_strlen(split_str[0])) && flag->SO == 0)
		mlx->check = ft_gettex(mlx, &flag->SO,
		&mlx->map.SO) == 0 ? 0 : 1;
	else if (!ft_strncmp(split_str[0], "WE",
	ft_strlen(split_str[0])) && flag->WE == 0)
		mlx->check = ft_gettex(mlx, &flag->WE,
		&mlx->map.WE) == 0 ? 0 : 1;
	else if (!ft_strncmp(split_str[0], "EA",
	ft_strlen(split_str[0])) && flag->EA == 0)
		mlx->check = ft_gettex(mlx, &flag->EA,
		&mlx->map.EA) == 0 ? 0 : 1;
	else
		ft_get_all_param_without_map_2(mlx,
		split_str, flag, line);
}
