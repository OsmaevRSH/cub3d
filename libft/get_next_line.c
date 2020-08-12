/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheresi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 23:16:29 by ltheresi          #+#    #+#             */
/*   Updated: 2020/07/06 19:38:56 by ltheresi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						get_next_line(int fd, char **line)
{
	static t_gnl_list	*gnl;
	t_gnl_list			*tmp;
	int					output;

	if (fd < 0 || fd > OPEN_MAX_LIMIT || !line || BUFFER_SIZE < 1 ||
	read(fd, NULL, 0) == -1)
		return (-1);
	*line = NULL;
	if (!gnl)
		if (!(gnl = ft_create_gnl(fd)))
			return (-1);
	tmp = gnl;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			if (!(tmp->next = ft_create_gnl(fd)))
				return (-1);
		tmp = tmp->next;
	}
	output = ft_get_line_gnl(fd, &(tmp->buffer), line);
	if (output < 0)
		free(*line);
	if (output <= 0)
		ft_del_elem_gnl(&gnl, tmp);
	return (output);
}

void					help_function_gnl(char **check_n, char **buffer,
						char **line, int *check_error)
{
	if ((*check_n = ft_strchr_and_create_gnl(*buffer, 0)))
	{
		*((*check_n)++) = '\0';
		if (!(*line = ft_strdup_gnl(buffer, 0)))
		{
			*check_error = 1;
			return ;
		}
		if (!(*check_n = ft_strdup_gnl(check_n, 0)))
		{
			*check_error = 1;
			return ;
		}
		ft_strclear_and_strlen_gnl(buffer, 0, NULL, 1);
		*buffer = *check_n;
	}
	else
	{
		if (!(*line = ft_strdup_gnl(buffer, 1)))
		{
			*check_error = 1;
			return ;
		}
	}
}

char					*ft_recover_buffer_gnl(char **line, char **buffer,
						int *check_error)
{
	char				*tmp;
	char				*check_n;

	check_n = NULL;
	tmp = *line;
	if (*buffer)
	{
		help_function_gnl(&check_n, buffer, line, check_error);
		if (*check_error == 1)
			return (0);
	}
	else
	{
		if (!(*line = ft_strchr_and_create_gnl(tmp, 1)))
		{
			*check_error = 1;
			return (0);
		}
	}
	ft_strclear_and_strlen_gnl(&tmp, 0, NULL, 1);
	return (check_n);
}

int						ft_get_line_gnl(int fd, char **buffer, char **line)
{
	char				get_from_read[BUFFER_SIZE + 1];
	char				*check_n;
	ssize_t				count_read;
	int					check_error;

	check_error = 0;
	check_n = ft_recover_buffer_gnl(line, buffer, &check_error);
	if (check_error == 1)
		return (-1);
	while (!check_n && (count_read = read(fd, get_from_read, BUFFER_SIZE)))
	{
		if (count_read == -1)
			return (-1);
		get_from_read[count_read] = '\0';
		if ((check_n = ft_strchr_and_create_gnl(get_from_read, 0)))
		{
			*check_n++ = '\0';
			if (!(*buffer = ft_strdup_gnl(&check_n, 0)))
				return (-1);
		}
		if (!(*line = ft_strjoin_gnl(*line, get_from_read)))
			return (-1);
	}
	return (check_n || ft_strclear_and_strlen_gnl(NULL, 0, *buffer, 0) ? 1 : 0);
}

t_gnl_list				*ft_create_gnl(int fd)
{
	t_gnl_list			*new;

	if (!(new = (t_gnl_list *)malloc(sizeof(t_gnl_list))))
		return (0);
	new->fd = fd;
	new->buffer = NULL;
	new->next = NULL;
	return (new);
}
