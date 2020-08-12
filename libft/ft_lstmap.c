/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheresi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 15:26:56 by ltheresi          #+#    #+#             */
/*   Updated: 2020/05/06 14:02:22 by ltheresi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_collect(t_list *tmp_lst_ptr, t_list *new_lst)
{
	t_list	*tmp_ptr;

	while (tmp_lst_ptr != new_lst)
	{
		tmp_ptr = tmp_lst_ptr;
		tmp_lst_ptr = tmp_lst_ptr->next;
		free(tmp_ptr);
	}
	free(new_lst);
}

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*tmp_lst_ptr;

	if (!lst || !f)
		return (NULL);
	if (!(new_lst = ft_lstnew(f(lst->content))))
		return (NULL);
	tmp_lst_ptr = new_lst;
	lst = lst->next;
	while (lst)
	{
		if (!(new_lst->next = ft_lstnew(f(lst->content))))
		{
			ft_collect(tmp_lst_ptr, new_lst);
			return (NULL);
		}
		new_lst = new_lst->next;
		if (lst->content == NULL)
		{
			if (del)
				del(new_lst->content);
		}
		lst = lst->next;
	}
	return (tmp_lst_ptr);
}
