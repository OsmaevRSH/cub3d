/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_map_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheresi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 20:52:37 by ltheresi          #+#    #+#             */
/*   Updated: 2020/08/06 20:52:39 by ltheresi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		ft_get_textures(char *str_1, const char *str_2, t_mlx *mlx, int *flag, char **mlx_str)
{
	int fd;
	if ((fd = open(str_1, O_RDONLY)) && ft_check_file_extension(str_1, "xpm") && str_2 == NULL)
	{
		*flag = 1;
		close(fd);
		*mlx_str = ft_strdup(str_1);
	}
	else
	{
		printf("%s", "texture error");
		exit(0);
	}
}

void		ft_get_color(const char *str_1, const char *str_2, int *flag, t_color_f_and_r *data)
{
	char **color;
	if (str_1 && str_2 == NULL)
	{
		*flag = 1;
		color = ft_split(str_1, ',');
		if (color[3] == NULL)
		{
			if (ft_isdigit_from_string(color[0]) && ft_atoi(color[0]) >= 0 && ft_atoi(color[0]) <= 255
			&& ft_isdigit_from_string(color[1]) && ft_atoi(color[1]) >= 0 && ft_atoi(color[1]) <= 255
			&& ft_isdigit_from_string(color[2]) && ft_atoi(color[2]) >= 0 && ft_atoi(color[2]) <= 255)
			{
				(*data).r = ft_atoi(color[0]);
				(*data).g = ft_atoi(color[1]);
				(*data).b = ft_atoi(color[2]);
			}
			else
			{
				printf("%s", "invalid color");
				exit(0);
			}
		}
	}
	else
	{
		printf("%s", "invalid color");
		exit(0);
	}
}

void		ft_get_resolution_size(char *str_1, char *str_2, const char *str_3, int *flag, t_screen_size *data)
{
	if (ft_isdigit_from_string(str_1) && ft_isdigit_from_string(str_2) && str_3 == NULL)
	{
		*flag = 1;
		(*data).width = ft_atoi(str_1);
		(*data).height = ft_atoi(str_2);
	}
	else
	{
		printf("%s", "1");
		exit(0);
	}
}

void		ft_get_map(t_check flag, char *line, int fd, t_mlx *mlx)
{
	if (flag.F && flag.S && flag.EA && flag.WE && flag.SO && flag.NO && flag.R && flag.C)
	{
		if (!(line = ft_parce_map(fd, line, mlx)))
		{
			printf("%s", "mapError");
			exit(0);
		}
		mlx->map.worldMap = ft_split(line, '\n');
		check_map(mlx->map.worldMap, mlx);
		return;
	}
	else
	{
		printf("%s", "mapError");
		exit(0);
	}
}

void		ft_parce(char *file_name, t_mlx *mlx)
{
	int fd;
	char *line;
	char **split_str;
	t_check flag;


	fd = open(file_name, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		split_str = ft_split(line, ' ');
		if (split_str[0] == NULL)
			continue ;
		else if (!ft_strncmp(split_str[0], "R", ft_strlen(split_str[0])) && flag.R == 0)
			ft_get_resolution_size(split_str[1], split_str[2], split_str[3], &flag.R, &mlx->map.R);
		else if (!ft_strncmp(split_str[0], "NO", ft_strlen(split_str[0])) && flag.NO == 0)
			ft_get_textures(split_str[1], split_str[2], mlx, &flag.NO, &mlx->map.NO);
		else if (!ft_strncmp(split_str[0], "SO", ft_strlen(split_str[0])) && flag.SO == 0)
			ft_get_textures(split_str[1], split_str[2], mlx, &flag.SO, &mlx->map.SO);
		else if (!ft_strncmp(split_str[0], "WE", ft_strlen(split_str[0])) && flag.WE == 0)
			ft_get_textures(split_str[1], split_str[2], mlx, &flag.WE, &mlx->map.WE);
		else if (!ft_strncmp(split_str[0], "EA", ft_strlen(split_str[0])) && flag.EA == 0)
			ft_get_textures(split_str[1], split_str[2], mlx, &flag.EA, &mlx->map.EA);
		else if (!ft_strncmp(split_str[0], "S", ft_strlen(split_str[0])) && flag.S == 0)
			ft_get_textures(split_str[1], split_str[2], mlx, &flag.S, &mlx->map.S);
		else if (!ft_strncmp(split_str[0], "F", ft_strlen(split_str[0])) && flag.F == 0)
			ft_get_color(split_str[1], split_str[2], &flag.F, &mlx->map.F);
		else if (!ft_strncmp(split_str[0], "C", ft_strlen(split_str[0])) && flag.C == 0)
			ft_get_color(split_str[1], split_str[2], &flag.C, &mlx->map.C);
		else
			ft_get_map(flag, line, fd, mlx);
	}
}

int check_map(char **map, t_mlx *mlx)
{
	int x;
	int y;

	x = mlx->player.rectangle_x;
	y = mlx->player.rectangle_y;
	check(map, x, y);
	return (1);
}

int check(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == '2' || map[y][x] == '.')
		return (1);
	if (map[y + 1][x] == ' ' || map[y][x + 1] == ' ' || map[y - 1][x] == ' ' || map[y][x - 1] == ' ')
	{
		printf("%s", "error map don't close");
		exit(0);
	}
	map[y][x] = '.';
	check(map, x - 1, y);
	check(map, x + 1, y);
	check(map, x, y - 1);
	check(map, x, y + 1);
	return (1);
}

void		check_count_player_in_map(const char *str, t_mlx *mlx)
{
	static int count;
	int i;
	static size_t sprite_id;

	i = 0;
	mlx->count_lines_in_map++;
	while (str[i])
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != 'N' && str[i] != 'S' && str[i] != 'W' && str[i] != 'E' && str[i] != ' ')
		{
			printf("%s", "map error1");
			exit(0);
		}
		if (str[i] == '2')
		{
			ft_push_back_new_sprite((i + 1) * 64 + 32, mlx->count_lines_in_map * 64 + 32, sprite_id, &mlx->head_for_sprite_list);
			sprite_id++;
		}
		if (str[i] == 'N' || str[i] == 'S' || str[i] == 'W' || str[i] == 'E')
		{
			count++;
			if (count == 2)
			{
				printf("%s", "map error2");
				exit(0);
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
		i++;
	}
}

char			*ft_parce_map(int fd, char *line, t_mlx *mlx)
{
	t_map_len	*str_in_map = NULL;
	t_map_len	*tmp;
	char		*tmp_str;
	char		*str;

	check_count_player_in_map(line, mlx);
	ft_lst_map_add(ft_strlen(line), line, &str_in_map);
	while (get_next_line(fd, &line))
	{
		check_count_player_in_map(line, mlx);
		ft_lst_map_add(ft_strlen(line), line, &str_in_map);
	}
	check_count_player_in_map(line, mlx);
	ft_lst_map_add(ft_strlen(line), line, &str_in_map);
	mlx->count_elem_in_line_map = ft_search_max_len_in_lst(&str_in_map);
	if (!(line = (char *)malloc(mlx->count_elem_in_line_map + 4)))
		return (0);
	ft_memset(line, ' ', mlx->count_elem_in_line_map + 2);
	line[mlx->count_elem_in_line_map + 2] = '\n';
	line[mlx->count_elem_in_line_map + 3] = '\0';
	tmp = str_in_map;
	while (tmp)
	{
		if (!(str = (char *)malloc(mlx->count_elem_in_line_map + 4)))
			return (0);
		ft_memset(str, ' ', mlx->count_elem_in_line_map + 2);
		ft_memcpy(str + 1, tmp->str, ft_strlen(tmp->str));
		str[mlx->count_elem_in_line_map + 2] = '\n';
		str[mlx->count_elem_in_line_map + 3] = '\0';
		tmp_str = line;
		line = ft_strjoin(line, str);
		free(str);
		free(tmp_str);
		tmp = tmp->next;
	}
	if (!(str = (char *)malloc(mlx->count_elem_in_line_map + 4)))
		return (0);
	ft_memset(str, ' ', mlx->count_elem_in_line_map + 2);
	str[mlx->count_elem_in_line_map + 2] = '\n';
	str[mlx->count_elem_in_line_map + 3] = '\0';
	tmp_str = line;
	line = ft_strjoin(line, str);
	free(tmp_str);
	return (line);
}


