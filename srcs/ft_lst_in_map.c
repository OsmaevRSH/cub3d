#include "../includes/cub3d.h"

static t_map_len	*ft_lst_map_new(int len, char *str)
{
	t_map_len *data;

	if (!(data = (t_map_len *)malloc(sizeof(t_map_len))))
		return (0);
	data->len = len;
	data->str = str;
	data->next = NULL;
	return (data);
}

void	ft_lst_map_add(int len, char *str, t_map_len **head)
{
	t_map_len *tmp;

	tmp = *head;
	if (!*head)
		*head = ft_lst_map_new(len, str);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_lst_map_new(len, str);
	}
}

int		ft_search_max_len_in_lst(t_map_len **head)
{
	t_map_len *tmp;
	int max;

	max = -9999;
	tmp = *head;
	while (tmp)
	{
		if (tmp->len > max)
			max = tmp->len;
		tmp = tmp->next;
	}
	return (max);
}