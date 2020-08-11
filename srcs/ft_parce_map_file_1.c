/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parce_map_file_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheresi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 14:00:29 by ltheresi          #+#    #+#             */
/*   Updated: 2020/08/11 14:00:32 by ltheresi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			ft_parce_2(t_mlx *mlx, char **line,
				char **split_str, t_check *flag)
{
	int			i;

	while (get_next_line(mlx->fd, line))
	{
		i = 0;
		split_str = ft_split(*line, ' ');
		if (split_str[1])
		{
			mlx->str_1 = split_str[1];
			mlx->str_2 = split_str[2];
		}
		if (split_str[0] == NULL)
		{
			free(split_str);
			free(*line);
			continue;
		}
		ft_get_all_param_without_map(mlx, split_str, flag, *line);
		while (split_str[i] != NULL)
			free(split_str[i++]);
		free(split_str);
		free(*line);
		if (mlx->check == 1)
			ft_free_mlx(mlx, 1);
	}
}

void			ft_parce(char *file_name, t_mlx *mlx)
{
	char		*line;
	char		**split_str;
	t_check		flag;

	split_str = NULL;
	ft_bzero(&flag, sizeof(t_check));
	mlx->fd = open(file_name, O_RDONLY);
	if (mlx->fd == -1)
	{
		perror("Error map file");
		ft_free_mlx(mlx, 1);
	}
	ft_parce_2(mlx, &line, split_str, &flag);
	free(line);
}

void			ft_parce_map_2(t_map_len *tmp, t_mlx *mlx, char **line)
{
	char		*str;
	char		*tmp_str;

	while (tmp)
	{
		if (!(str = (char *)malloc(mlx->count_elem_in_line_map + 4)))
		{
			ft_free_mlx(mlx, 1);
			return ;
		}
		ft_memset(str, ' ', mlx->count_elem_in_line_map + 2);
		ft_memcpy(str + 1, tmp->str, ft_strlen(tmp->str));
		str[mlx->count_elem_in_line_map + 2] = '\n';
		str[mlx->count_elem_in_line_map + 3] = '\0';
		tmp_str = *line;
		*line = ft_strjoin(*line, str);
		free(str);
		free(tmp_str);
		tmp = tmp->next;
	}
}

void			ft_parce_map_3(t_mlx *mlx, char **line)
{
	char		*str;
	char		*tmp_str;

	if (!(str = (char *)malloc(mlx->count_elem_in_line_map + 4)))
	{
		ft_free_mlx(mlx, 1);
		return ;
	}
	ft_memset(str, ' ', mlx->count_elem_in_line_map + 3);
	str[mlx->count_elem_in_line_map + 3] = '\0';
	tmp_str = *line;
	*line = ft_strjoin(*line, str);
	free(tmp_str);
	free(str);
}

char			*ft_parce_map(int fd, char *line, t_mlx *mlx)
{
	t_map_len	*tmp;

	check_count_player_in_map(line, mlx);
	if (!(ft_lst_map_add(ft_strlen(line), line, &mlx->head_for_map_len_list)))
		ft_free_mlx(mlx, 1);
	while (get_next_line(fd, &line))
	{
		check_count_player_in_map(line, mlx);
		if (!(ft_lst_map_add(ft_strlen(line),
		line, &mlx->head_for_map_len_list)))
			ft_free_mlx(mlx, 1);
	}
	check_count_player_in_map(line, mlx);
	if (!(ft_lst_map_add(ft_strlen(line), line, &mlx->head_for_map_len_list)))
		ft_free_mlx(mlx, 1);
	mlx->count_elem_in_line_map =
	ft_search_max_len_in_lst(&mlx->head_for_map_len_list);
	if (!(line = (char *)malloc(mlx->count_elem_in_line_map + 4)))
		ft_free_mlx(mlx, 1);
	ft_memset(line, ' ', mlx->count_elem_in_line_map + 2);
	line[mlx->count_elem_in_line_map + 2] = '\n';
	line[mlx->count_elem_in_line_map + 3] = '\0';
	ft_parce_map_2(mlx->head_for_map_len_list, mlx, &line);
	ft_parce_map_3(mlx, &line);
	return (line);
}
