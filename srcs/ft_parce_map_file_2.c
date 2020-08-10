///* ************************************************************************** */
///*                                                                            */
///*                                                        :::      ::::::::   */
///*   ft_parce_map_file_2.c                              :+:      :+:    :+:   */
///*                                                    +:+ +:+         +:+     */
///*   By: ltheresi <marvin@42.fr>                    +#+  +:+       +#+        */
///*                                                +#+#+#+#+#+   +#+           */
///*   Created: 2020/08/10 20:44:40 by ltheresi          #+#    #+#             */
///*   Updated: 2020/08/10 20:44:42 by ltheresi         ###   ########.fr       */
///*                                                                            */
///* ************************************************************************** */
//
//#include "../includes/cub3d.h"
//
//int			ft_get_textures(char *str_1, const char *str_2,
//			int *flag, char **mlx_str)
//{
//	int		fd;
//
//	fd = open(str_1, O_RDONLY);
//	if (fd != -1 &&
//		ft_check_file_extension(str_1, "xpm") && str_2 == NULL)
//	{
//		*flag = 1;
//		close(fd);
//		*mlx_str = ft_strdup(str_1);
//		return (0);
//	}
//	else
//	{
//		if (fd != -1)
//		{
//			ft_putstr_fd("Error:\nInvalid texture\n", 1);
//			return (1);
//		}
//		perror("Texture error");
//		return (1);
//	}
//}
//
//int			ft_if_for_get_color(char **color, t_color_f_and_r *data)
//{
//	if (color[3] == NULL)
//	{
//		if (ft_isdigit_from_string(color[0]) && ft_atoi(color[0])
//			>= 0 && ft_atoi(color[0]) <= 255
//			&& ft_isdigit_from_string(color[1]) && ft_atoi(color[1])
//			>= 0 && ft_atoi(color[1]) <= 255
//			&& ft_isdigit_from_string(color[2]) && ft_atoi(color[2])
//			>= 0 && ft_atoi(color[2]) <= 255)
//		{
//			(*data).r = ft_atoi(color[0]);
//			(*data).g = ft_atoi(color[1]);
//			(*data).b = ft_atoi(color[2]);
//		}
//		else
//		{
//			ft_putstr_fd("Error:\nInvalid color format\n", 1);
//			return (1);
//		}
//	}
//	return (0);
//}
//
//int			ft_get_color(const char *str_1,
//			const char *str_2, int *flag, t_color_f_and_r *data)
//{
//	char	**color;
//	int		i;
//
//	i = 0;
//	if (str_1 && str_2 == NULL)
//	{
//		*flag = 1;
//		color = ft_split(str_1, ',');
//		if (ft_if_for_get_color(color, data))
//			return (1);
//		while (color[i] != NULL)
//			free(color[i++]);
//		free(color);
//	}
//	else
//	{
//		ft_putstr_fd("Error:\nInvalid color format\n", 1);
//		return (1);
//	}
//	return (0);
//}
//
//int			ft_get_resolution_size(char *str_1, char *str_2,
//			const char *str_3, t_screen_size *data)
//{
//	if (ft_isdigit_from_string(str_1) &&
//	ft_isdigit_from_string(str_2) && str_3 == NULL)
//	{
//		data->flag = 1;
//		(*data).width = ft_atoi(str_1);
//		(*data).height = ft_atoi(str_2);
//		return (0);
//	}
//	else
//	{
//		ft_putstr_fd("Error:\nInvali format resolution\n", 1);
//		return (1);
//	}
//}
//
//void		ft_get_map(t_check flag, char *line, int fd, t_mlx *mlx)
//{
//	if (flag.F && flag.S && flag.EA &&
//	flag.WE && flag.SO && flag.NO && mlx->map.R.flag && flag.C)
//	{
//		if (!(line = ft_parce_map(fd, line, mlx)))
//		{
//			ft_putstr_fd("Error:\nMap incorrect", 1);
//			ft_free_mlx(mlx);
//			exit(1);
//		}
//		mlx->map.worldMap = ft_split(line, '\n');
////		free(line);
//		check_map(mlx->map.worldMap, mlx);
//	}
//	else
//	{
//		ft_putstr_fd("Error:\nInvalid map file\n", 1);
//		{
//			ft_free_mlx(mlx);
//			exit(1);
//		}
//	}
//}
