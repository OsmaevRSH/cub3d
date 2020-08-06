#include "cub3d.h"

void			ft_list_sort(t_sprite **sprite)
{
	int			count_elem_in_list;
	int			count;
	int			flag_if_all_done;
	t_sprite	*tmp;

	count_elem_in_list = ft_count_sprites(*sprite);
	flag_if_all_done = 0;
	while (flag_if_all_done != count_elem_in_list - 1)
	{
		flag_if_all_done = 0;
		count = count_elem_in_list - 1;
		tmp = *sprite;
		while (count--)
		{
			if (tmp->distance < tmp->next->distance)
				ft_swap_elem_in_list(tmp, tmp->next, sprite);
			else
			{
				flag_if_all_done++;
				tmp = tmp->next;
			}
		}
	}
}

double			ft_get_distance(t_mlx *mlx, t_sprite *sprite)
{
	double		sprite_dist;

	sprite_dist = sqrt(pow(mlx->player.x - sprite->x, 2) + pow(mlx->player.y - sprite->y, 2));
	return (sprite_dist);
}
