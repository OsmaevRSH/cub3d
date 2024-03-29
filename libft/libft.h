/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltheresi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 13:20:02 by ltheresi          #+#    #+#             */
/*   Updated: 2020/05/03 16:04:14 by ltheresi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# define OPEN_MAX_LIMIT 10240
# define BUFFER_SIZE 32

typedef struct				s_list
{
	void					*content;
	struct s_list			*next;
}							t_list;

typedef struct				s_gnl_buff_list
{
	char					*buffer;
	int						fd;
	struct s_gnl_buff_list	*next;
}							t_gnl_list;

void						*ft_memset (void *b, int c, size_t len);
void						ft_bzero(void *s, size_t n);
void						*ft_memcpy(void *dst, const void *src, size_t n);
void						*ft_memccpy (void *dst,
							const void *src, int c, size_t n);
void						*ft_memmove(void *dst, const void *src, size_t len);
void						*ft_memchr(const void *s, int c, size_t n);
int							ft_memcmp(const void *s1, const void *s2, size_t n);
size_t						ft_strlen(const char *s);
size_t						ft_strlcpy(char *dst,
							const char *src, size_t dstsize);
size_t						ft_strlcat(char *dst,
							const char *src, size_t dstsize);
char						*ft_strchr(const char *s, int c);
char						*ft_strrchr(const char *s, int c);
char						*ft_strnstr(const char *haystack,
							const char *needle, size_t len);
int							ft_strncmp(const char *s1,
							const char *s2, size_t n);
int							ft_atoi(const char *str);
int							ft_isalpha(int c);
int							ft_isdigit(int c);
int							ft_isalnum(int c);
int							ft_isascii(int c);
int							ft_isprint(int c);
int							ft_toupper(int c);
int							ft_tolower(int c);
void						*ft_calloc(size_t count, size_t size);
char						*ft_strdup(const char *s1);
char						*ft_substr(char const *s,
							unsigned int start, size_t len);
char						*ft_strjoin(char const *s1, char const *s2);
char						*ft_strtrim(char const *s1, char const *set);
char						**ft_split(char const *s, char c);
char						*ft_itoa(int n);
char						*ft_strmapi(char const *s,
							char (*f)(unsigned int, char));
void						ft_putchar_fd(char c, int fd);
void						ft_putstr_fd(char *s, int fd);
void						ft_putendl_fd(char *s, int fd);
void						ft_putnbr_fd(int n, int fd);
t_list						*ft_lstnew(void *content);
void						ft_lstadd_front(t_list **lst, t_list *new);
int							ft_lstsize(t_list *lst);
t_list						*ft_lstlast(t_list *lst);
void						ft_lstadd_back(t_list **lst, t_list *new);
void						ft_lstdelone(t_list *lst, void (*del)(void*));
void						ft_lstclear(t_list **lst, void (*del)(void*));
void						ft_lstiter(t_list *lst, void (*f)(void *));
t_list						*ft_lstmap(t_list *lst, void *(*f)(void *), \
							void (*del)(void *));
int							ft_isdigit_from_string(char *str);
int							ft_check_file_extension(char *str, char *check);
int							get_next_line(int fd, char **line);
t_gnl_list					*ft_create_gnl(int fd);
int							ft_get_line_gnl(int fd, char **buffer, char **line);
char						*ft_strchr_and_create_gnl(char *s, int flag);
char						*ft_strjoin_gnl(char *s1, char *s2);
char						*ft_strdup_gnl(char **s1, int flag);
char						*ft_recover_buffer_gnl(char **line, char **buffer,
							int *check_error);
size_t						ft_strclear_and_strlen_gnl(char **str, int n,
							const char *s, int flag);
void						ft_del_elem_gnl(t_gnl_list **lst, t_gnl_list *del);
#endif
