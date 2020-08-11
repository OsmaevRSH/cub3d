/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheresi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 20:38:59 by ltheresi          #+#    #+#             */
/*   Updated: 2020/08/09 20:39:01 by ltheresi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		close_window(t_mlx *mlx)
{
	ft_free_mlx(mlx, 0);
	return (0);
}

void	ft_key_events(int keycode, t_mlx *mlx)
{
	ft_left_right(keycode, mlx);
	ft_go_left_right(keycode, mlx);
	ft_go_forward_back(keycode, mlx);
	ft_tilt_up_down(keycode, mlx);
}
