#include "cub3d.h"

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
		else if (!ft_strncmp(split_str[0], "R", ft_strlen(split_str[0])))
		{
			if (ft_isdigit_from_string(split_str[1]) && ft_isdigit_from_string(split_str[2]) && split_str[3] == NULL && flag.R == 0)
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
		else if (!ft_strncmp(split_str[0], "NO", ft_strlen(split_str[0])))
		{
			if ((fd_for_check_file_extension = open(split_str[1], O_RDONLY)) && ft_check_file_extension(split_str[1], "xpm") && flag.NO == 0)
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
		else if (!ft_strncmp(split_str[0], "SO", 3))
		{
			if ((fd_for_check_file_extension = open(split_str[1], O_RDONLY)) && ft_check_file_extension(split_str[1], "xpm") && split_str[2] == NULL && flag.SO == 0)
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
		else if (!ft_strncmp(split_str[0], "WE", ft_strlen(split_str[0])))
		{
			if ((fd_for_check_file_extension = open(split_str[1], O_RDONLY)) && ft_check_file_extension(split_str[1], "xpm") && split_str[2] == NULL && flag.WE == 0)
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
		else if (!ft_strncmp(split_str[0], "EA", ft_strlen(split_str[0])))
		{
			if ((fd_for_check_file_extension = open(split_str[1], O_RDONLY)) && ft_check_file_extension(split_str[1], "xpm") && split_str[2] == NULL && flag.EA == 0)
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
		else if (!ft_strncmp(split_str[0], "S", ft_strlen(split_str[0])))
		{
			if ((fd_for_check_file_extension = open(split_str[1], O_RDONLY)) && ft_check_file_extension(split_str[1], "xpm") && split_str[2] == NULL && flag.S == 0)
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
		else if (!ft_strncmp(split_str[0], "F", ft_strlen(split_str[0])))
		{
			if (split_str[1] && split_str[2] == NULL && flag.F == 0)
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
		else if (!ft_strncmp(split_str[0], "C", ft_strlen(split_str[0])))
		{
			if (split_str[1] && split_str[2] == NULL && flag.C == 0)
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
				if (!(line = ft_parce_map(fd, line)))
				{
					printf("%s", "9");
					exit(0);
				}
				mlx->map.worldMap = ft_split(line, '\n');
//				if (!check_map(mlx->map.mlx->map.worldMap))
//				{
//					printf("%s", "error");
//					exit(0);
//				}
				return;
			}
			else
			{
				printf("%s", "9");
				exit(0);
			}
		}
	}
}

int		check_map(char **pString)
{
		return 0;
}

char		*ft_parce_map(int fd, char *line)
{
	char *str_map;
	int len_line;
	char *tmp;
	char *str;

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

