/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parce_map_file_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheresi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 12:42:48 by ltheresi          #+#    #+#             */
/*   Updated: 2020/08/11 12:42:50 by ltheresi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			check_map(char **map, t_mlx *mlx)
{
	int		x;
	int		y;

	x = mlx->player.rectangle_x;
	y = mlx->player.rectangle_y;
	if (check(map, x, y) == 1)
		ft_free_mlx(mlx, 1);
}

int				check(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == '2'
	|| map[y][x] == '.' || map[y][x] == '3')
		return (0);
	if (map[y + 1][x] == ' ' || map[y][x + 1] == ' '
	|| map[y - 1][x] == ' ' || map[y][x - 1] == ' ')
	{
		ft_putstr_fd("Error:\nMap don`t close\n", 1);
		return (1);
	}
	map[y][x] = '.';
	check(map, x - 1, y);
	check(map, x + 1, y);
	check(map, x, y - 1);
	check(map, x, y + 1);
	return (0);
}

void			ft_search_player(t_mlx *mlx, const char *str, int *count, int i)
{
	if (str[i] == 'N' || str[i] == 'S' || str[i] == 'W' || str[i] == 'E')
	{
		(*count)++;
		if ((*count) == 2)
		{
			ft_putstr_fd("Error:\nInvalid number of players\n", 1);
			exit(1);
		}
		mlx->player.x = (i + 1) * 64 + 32;
		mlx->player.rectangle_x = i + 1;
		mlx->player.y = mlx->count_lines_in_map * 64 + 32;
		mlx->player.rectangle_y = mlx->count_lines_in_map;
		if (str[i] == 'N')
			mlx->player.angle = 3 * M_PI_2;
		else if (str[i] == 'S')
			mlx->player.angle = M_PI_2;
		else if (str[i] == 'W')
			mlx->player.angle = M_PI;
		else
			mlx->player.angle = 0;
	}
}

void			ft_check_sprite(const char *str, t_mlx *mlx, int i)
{
	if (str[i] == '2' || str[i] == '3')
	{
		if (str[i] == '2')
			ft_push_back_new_sprite((i + 1) * 64 + 32,
									mlx->count_lines_in_map * 64 + 32,
									&mlx->head_for_sprite_list, 0);
		else
			ft_push_back_new_sprite((i + 1) * 64 + 32,
									mlx->count_lines_in_map * 64 + 32,
									&mlx->head_for_sprite_list, 1);
	}
}

void			check_count_player_in_map(const char *str, t_mlx *mlx)
{
	static int	count;
	int			i;

	i = 0;
	mlx->count_lines_in_map++;
	while (str[i])
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != '2' &&
		str[i] != 'N' && str[i] != 'S' && str[i] != 'W' &&
		str[i] != 'E' && str[i] != ' ' && str[i] != '3')
		{
			ft_putstr_fd("Error:\nInvalid symbol in map\n", 1);
			ft_free_mlx(mlx, 1);
		}
		ft_check_sprite(str, mlx, i);
		ft_search_player(mlx, str, &count, i);
		i++;
	}
}
