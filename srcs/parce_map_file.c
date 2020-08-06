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

void		ft_parce(char *file_name, t_mlx *mlx)
{
	int fd;
	int fd_for_check_file_extension;
	char *line;
	char **split_str;
	char **color;
	t_check flag;

	
	fd = open(file_name, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		split_str = ft_split(line, ' ');
		if (split_str[0] == NULL)
			continue ;
		else if (!ft_strncmp(split_str[0], "R", ft_strlen(split_str[0])) && flag.R == 0)
		{
			if (ft_isdigit_from_string(split_str[1]) && ft_isdigit_from_string(split_str[2]) && split_str[3] == NULL)
			{
				flag.R = 1;
				mlx->map.R.width = ft_atoi(split_str[1]);
				mlx->map.R.height = ft_atoi(split_str[2]);
			}
			else
			{
				printf("%s", "1");
				exit(0);
			}
		}
		else if (!ft_strncmp(split_str[0], "NO", ft_strlen(split_str[0])) && flag.NO == 0)
		{
			if ((fd_for_check_file_extension = open(split_str[1], O_RDONLY)) && ft_check_file_extension(split_str[1], "xpm"))
			{
				flag.NO = 1;
				close(fd_for_check_file_extension);
				mlx->map.NO = ft_strdup(split_str[1]);
			}
			else
			{
				printf("%s", "2");
				exit(0);
			}
		}
		else if (!ft_strncmp(split_str[0], "SO", 3) && flag.SO == 0)
		{
			if ((fd_for_check_file_extension = open(split_str[1], O_RDONLY)) && ft_check_file_extension(split_str[1], "xpm") && split_str[2] == NULL)
			{
				flag.SO = 1;
				close(fd_for_check_file_extension);
				mlx->map.SO = ft_strdup(split_str[1]);
			}
			else
			{
				printf("%s", "3");
				exit(0);
			}
		}
		else if (!ft_strncmp(split_str[0], "WE", ft_strlen(split_str[0])) && flag.WE == 0)
		{
			if ((fd_for_check_file_extension = open(split_str[1], O_RDONLY)) && ft_check_file_extension(split_str[1], "xpm") && split_str[2] == NULL)
			{
				flag.WE = 1;
				close(fd_for_check_file_extension);
				mlx->map.WE = ft_strdup(split_str[1]);
			}
			else
			{
				printf("%s", "4");
				exit(0);
			}
		}
		else if (!ft_strncmp(split_str[0], "EA", ft_strlen(split_str[0])) && flag.EA == 0)
		{
			if ((fd_for_check_file_extension = open(split_str[1], O_RDONLY)) && ft_check_file_extension(split_str[1], "xpm") && split_str[2] == NULL)
			{
				flag.EA = 1;
				close(fd_for_check_file_extension);
				mlx->map.EA = ft_strdup(split_str[1]);
			}
			else
			{
				printf("%s", "5");
				exit(0);
			}
		}
		else if (!ft_strncmp(split_str[0], "S", ft_strlen(split_str[0])) && flag.S == 0)
		{
			if ((fd_for_check_file_extension = open(split_str[1], O_RDONLY)) && ft_check_file_extension(split_str[1], "xpm") && split_str[2] == NULL)
			{
				flag.S = 1;
				close(fd_for_check_file_extension);
				mlx->map.S = ft_strdup(split_str[1]);
			}
			else
			{
				printf("%s", "6");
				exit(0);
			}
		}
		else if (!ft_strncmp(split_str[0], "F", ft_strlen(split_str[0])) && flag.F == 0)
		{
			if (split_str[1] && split_str[2] == NULL)
			{
				flag.F = 1;
				color = ft_split(split_str[1], ',');
				if (color[3] == NULL)
				{
					if (ft_isdigit_from_string(color[0]) && ft_atoi(color[0]) >= 0 && ft_atoi(color[0]) <= 255)
						mlx->map.F.r = ft_atoi(color[0]);
					else
					{
						printf("%s", "7");
						exit(0);
					}
					if (ft_isdigit_from_string(color[1]) && ft_atoi(color[1]) >= 0 && ft_atoi(color[1]) <= 255)
						mlx->map.F.g = ft_atoi(color[1]);
					else
					{
						printf("%s", "7");
						exit(0);
					}
					if (ft_isdigit_from_string(color[2]) && ft_atoi(color[2]) >= 0 && ft_atoi(color[2]) <= 255)
						mlx->map.F.b = ft_atoi(color[2]);
					else
					{
						printf("%s", "7");
						exit(0);
					}
				}
			}
			else
			{
				printf("%s", "7");
				exit(0);
			}
		}
		else if (!ft_strncmp(split_str[0], "C", ft_strlen(split_str[0])) && flag.C == 0)
		{
			if (split_str[1] && split_str[2] == NULL)
			{
				flag.C = 1;
				color = ft_split(split_str[1], ',');
				if (color[3] == NULL)
				{
					if (ft_isdigit_from_string(color[0]) && ft_atoi(color[0]) >= 0 && ft_atoi(color[0]) <= 255)
						mlx->map.C.r = ft_atoi(color[0]);
					else
					{
						printf("%s", "8");
						exit(0);
					}
					if (ft_isdigit_from_string(color[1]) && ft_atoi(color[1]) >= 0 && ft_atoi(color[1]) <= 255)
						mlx->map.C.g = ft_atoi(color[1]);
					else
					{
						printf("%s", "8");
						exit(0);
					}
					if (ft_isdigit_from_string(color[2]) && ft_atoi(color[2]) >= 0 && ft_atoi(color[2]) <= 255)
						mlx->map.C.b = ft_atoi(color[2]);
					else
					{
						printf("%s", "8");
						exit(0);
					}
				}
			}
			else
			{
				printf("%s", "8");
				exit(0);
			}
		}
		else
		{
			if (flag.F && flag.S && flag.EA && flag.WE && flag.SO && flag.NO && flag.R && flag.C)
			{
				if (!(line = ft_parce_map(fd, line, mlx)))
				{
					printf("%s", "9");
					exit(0);
				}
				mlx->map.worldMap = ft_split(line, '\n');
				check_map(mlx->map.worldMap, mlx);
				return;
			}
			else
			{
				printf("%s", "10");
				exit(0);
			}
		}
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
	static int line_number;
	int i;
	static size_t sprite_id;

	i = 0;
	line_number++;
	while (str[i])
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != 'N' && str[i] != 'S' && str[i] != 'W' && str[i] != 'E' && str[i] != ' ')
		{
			printf("%s", "map error1");
			exit(0);
		}
		if (str[i] == '2')
		{
			ft_push_back_new_sprite((i + 1) * 64 + 32, line_number * 64 + 32, sprite_id, &mlx->head_for_sprite_list);
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
			mlx->player.y = line_number * 64 + 32;
			mlx->player.rectangle_y = line_number;
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

char		*ft_parce_map(int fd, char *line, t_mlx *mlx)
{
	char *str_map;
	int len_line;
	char *tmp;
	char *str;

	check_count_player_in_map(line, mlx);
	len_line = ft_strlen(line);
	if (!(str_map = (char *)malloc(sizeof(char) * (len_line + 4))))
		return (0);
	ft_memset(str_map, ' ', len_line + 2);
	str_map[len_line + 2] = '\n';
	str_map[len_line + 3] = '\0';
	tmp = str_map;
	str_map = ft_strjoin(str_map, " ");
	free(tmp);
	tmp = str_map;
	str_map = ft_strjoin(str_map, line);
	free(tmp);
	tmp = str_map;
	str_map = ft_strjoin(str_map, " \n");
	free(tmp);
	while (get_next_line(fd, &line))
	{
		check_count_player_in_map(line, mlx);
		tmp = str_map;
		str_map = ft_strjoin(str_map, " ");
		free(tmp);
		tmp = str_map;
		str_map = ft_strjoin(str_map, line);
		free(tmp);
		tmp = str_map;
		str_map = ft_strjoin(str_map, " \n");
		free(tmp);
	}
	check_count_player_in_map(line, mlx);
	tmp = str_map;
	str_map = ft_strjoin(str_map, " ");
	free(tmp);
	tmp = str_map;
	str_map = ft_strjoin(str_map, line);
	free(tmp);
	tmp = str_map;
	str_map = ft_strjoin(str_map, " \n");
	free(tmp);
	if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(line) + 3))))
		return (0);
	ft_memset(str, ' ', ft_strlen(line) + 2);
	str[ft_strlen(line) + 2] = '\0';
	tmp = str_map;
	str_map = ft_strjoin(str_map, str);
	free(tmp);
	return (str_map);
}

