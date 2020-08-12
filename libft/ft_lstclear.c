/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheresi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 15:06:34 by ltheresi          #+#    #+#             */
/*   Updated: 2020/05/12 00:45:59 by ltheresi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *tmp_ptr;

	while (*lst)
	{
		tmp_ptr = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = tmp_ptr;
	}
	lst = NULL;
}
