/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherrie <hcherrie@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 01:18:18 by hcherrie          #+#    #+#             */
/*   Updated: 2021/05/10 00:47:57 by broplz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define MIN_INT -2147483648
# define C_MIN_INT "-2147483648"
# define MAX_INT 2147483647
# define MAX_LONG 4294967295

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

size_t				ft_strlen_gnl(char *str);
char				*ft_strjoin_gnl(char *s1, char *s2);
void				*ft_memcpy_gnl(void *dst, void *src, size_t len);
char				*ft_strdup_gnl(char *str);
int					ft_strchr_gnl(char *str, int ch, int flag);
int					get_next_line(int fd, char **line);
void				ft_bzero(void *b, size_t len);
void				*ft_memcpy(void *dst, void *src, size_t len);
void				*ft_memset(void *dst, int c, size_t len);
void				*ft_memccpy(void *dst, void *src, int c, size_t len);
void				*ft_memmove(void *dest, const void *srcs, size_t len);
void				*ft_memchr(const void *s, int c, size_t len);
void				*ft_calloc(size_t num, size_t size);
size_t				ft_strlen(const char *str);
size_t				ft_strlcpy(char *dst, const char *src, size_t len);
size_t				ft_strlcat(char *dst, const char *src, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t len);
int					ft_isalpha(int ch);
int					ft_isalnum(int c);
int					ft_isdigit(int ch);
int					ft_strncmp(const char *s1, const char *s2, size_t len);
int					ft_isascii(int ch);
int					ft_isprint(int ch);
int					ft_toupper(int ch);
int					ft_tolower(int ch);
int					ft_atoi(char **str);
long				ft_atol(char **str);
int					ft_isupper(int ch);
int					ft_islower(int ch);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strchr(const char *str, int ch);
char				*ft_strrchr(const char *str, int ch);
char				*ft_strnstr(const char *str, const char *find, size_t len);
char				*ft_strdup(const char *str);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char ch);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_newstring(size_t len);
void				ft_putchar(char c);
void				ft_putendl(char *s);
void				ft_putnbr(int n);
void				ft_putstr(char *s);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
int					ft_lstsize(t_list *list);
t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *list);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));

#endif
