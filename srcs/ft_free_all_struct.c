#include "../includes/cub3d.h"

static void		ft_free_map_list(t_map_len **head)
{
	t_map_len *tmp;

	tmp = *head;
	while (*head)
	{
		tmp = tmp->next;
		free((*head)->str);
		free(*head);
		*head = tmp;
	}
}

static void		ft_free_sprite_list(t_sprite **head)
{
	t_sprite *tmp;

	tmp = *head;
	while (*head)
	{
		tmp = tmp->next;
		free(*head);
		*head = tmp;
	}
}

static void		ft_free_texture(t_texture *texture)
{
	free(texture->mlx_addr);
	free(texture->mlx_img);
}

static void 	ft_free_map(t_mlx *mlx)
{
	int i;

	i = 0;
	free(mlx->mlx);
	free(mlx->mlx_win);
	free(mlx->mlx_img);
	free(mlx->mlx_addr);
	free(mlx->map.NO);
	free(mlx->map.SO);
	free(mlx->map.WE);
	free(mlx->map.EA);
	free(mlx->map.S);
	free(mlx->map.SS);
	if (mlx->map.worldMap)
	{
		while (mlx->map.worldMap[i] != NULL)
			free(mlx->map.worldMap[i++]);
		free(mlx->map.worldMap);
	}
}

void		ft_free_mlx(t_mlx *mlx, int flag)
{

	ft_free_map(mlx);
	ft_free_map_list(&mlx->head_for_map_len_list);
	ft_free_sprite_list(&mlx->head_for_sprite_list);
	ft_free_texture(&mlx->texture.t1);
	ft_free_texture(&mlx->texture.t2);
	ft_free_texture(&mlx->texture.t3);
	ft_free_texture(&mlx->texture.t4);
	ft_free_texture(&mlx->texture.sprite_1);
	ft_free_texture(&mlx->texture.sprite_2);
	free(mlx->texture.arr_len_trace);
	if (flag == 1)
		exit(1);
	else
		exit(0);
}

