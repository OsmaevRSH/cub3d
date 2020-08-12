/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheresi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 23:16:25 by ltheresi          #+#    #+#             */
/*   Updated: 2020/07/06 19:33:55 by ltheresi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strchr_and_create_gnl(char *s, int flag)
{
	char			*tmp_s;

	if (!flag)
	{
		tmp_s = (char *)s;
		while (*tmp_s)
		{
			if (*tmp_s == '\n')
				return (tmp_s);
			tmp_s++;
		}
		return (0);
	}
	else
	{
		if (!(tmp_s = (char *)malloc(sizeof(char) * 1)))
			return (0);
		*tmp_s = '\0';
		return (tmp_s);
	}
}

char				*ft_strjoin_gnl(char *s1, char *s2)
{
	char			*str;
	char			*tmp_str;
	char			*tmp_s1;

	tmp_s1 = s1;
	if (!s1 || !s2)
		return (0);
	if (!(str = (char *)malloc(sizeof(char) * \
	(ft_strclear_and_strlen_gnl(NULL, 0, s1, 0) +
			ft_strclear_and_strlen_gnl(NULL, 0, s2, 0) + 1))))
		return (0);
	tmp_str = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	free(tmp_s1);
	return (tmp_str);
}

char				*ft_strdup_gnl(char **s1, int flag)
{
	char			*new_str;
	size_t			len_str;
	size_t			i;

	len_str = ft_strclear_and_strlen_gnl(NULL, 0, *s1, 0);
	i = 0;
	if (!(new_str = (char *)malloc((len_str + 1) * sizeof(char))))
		return (0);
	while ((*s1)[i])
	{
		new_str[i] = (*s1)[i];
		i++;
	}
	new_str[i] = '\0';
	if (flag)
	{
		free(*s1);
		*s1 = NULL;
	}
	return (new_str);
}

size_t				ft_strclear_and_strlen_gnl(char **str, int n,
					const char *s, int flag)
{
	unsigned char	*tmp_dest;
	size_t			len;

	if (flag)
	{
		tmp_dest = (unsigned char *)*str;
		while (n--)
			*tmp_dest++ = '\0';
		if (*str)
		{
			free(*str);
			*str = NULL;
		}
	}
	else
	{
		len = 0;
		if (!s)
			return (0);
		while (*s++)
			len++;
		return (len);
	}
	return (0);
}

void				ft_del_elem_gnl(t_gnl_list **lst, t_gnl_list *del)
{
	t_gnl_list			*list;

	list = *lst;
	if (list == del)
	{
		if (list->next)
			*lst = list->next;
		else
			*lst = NULL;
		free(list);
	}
	else
	{
		while (list->next != del)
			list = list->next;
		if (del->next)
			list->next = del->next;
		else
			list->next = NULL;
		list = del;
		free(list);
	}
}
