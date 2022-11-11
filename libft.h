/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:47:51 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/11 09:33:33 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdarg.h>
# include <limits.h>
# include <unistd.h>


typedef const char*		t_str;
typedef unsigned char	t_byte;
typedef unsigned int	t_uint;
typedef size_t*			t_data;
typedef void*			t_any;

typedef struct s_list
{
	t_any			content;
	struct s_list	*next;
}	t_list;

// character manipulation
int		ft_islower(int c);
int		ft_isupper(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_todigit(int c);
int		ft_tochar(int n);
t_str	ft_tostr(int c);

// integer manipulation
size_t	ft_max(size_t a, size_t b);
size_t	ft_min(size_t a, size_t b);

// maths
double	ft_abs(double a);
double	ft_pow(int a, int b);

// string manipulation
int		ft_strncmp(t_str str_a, t_str str_b, size_t n);
int		ft_strcmp(t_str str_a, t_str str_b);
int		ft_atoi(t_str str_int);
char	*ft_strchr(t_str str, int c);
char	*ft_strrchr(t_str str, int c);
char	*ft_strnstr(t_str source, t_str substr, size_t n);
char	*ft_strdup(t_str str_original);
char	*ft_substr(t_str string, t_uint start_index, size_t max_size);
char	*ft_strjoin(t_str str_a, t_str str_b);
char	*ft_strtrim(t_str to_trim, t_str trim_set);
char	*ft_itoa(int n);
char	*ft_strmapi(t_str str, char (*mapping_f)(t_uint, char));
char	**ft_split(t_str to_split, char delimiter);
size_t	ft_strlen(t_str str);
size_t	ft_strlcat(char *dest, t_str src, size_t size);
size_t	ft_strlcpy(char *dest, t_str src, size_t size);
size_t	ft_strnsum(t_str str, size_t n);
size_t	ft_strsum(t_str str);
void	ft_striteri(char *str, void (*f)(t_uint, char *));
void	ft_strpaste(char *dest, t_str source, size_t from);

// memory manipulation
void	ft_bzero(void *mem, size_t n);
void	ft_freeset(void *to_free, size_t n);
void	*ft_memset(void *memory, int byte, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *chr, int to_find, size_t n);
void	*ft_calloc(size_t elem_count, size_t elem_size);
char	*ft_stralloc(size_t n);
int		ft_memcmp(const void *mem_a, const void *mem_b, size_t size);
size_t	*ft_pack(size_t argc, ...);

// system io
void	ft_putchar_fd(char c, int file_desc);
void	ft_putstr_fd(char *str, int file_desc);
void	ft_putendl_fd(char *str, int file_desc);
void	ft_putnbr_fd(int n, int file_desc);

// linked lists
t_list	*ft_lstnew(t_any content);
t_list	*ft_lstlast(t_list *head);
t_list	*ft_lstmap(t_list *head, t_any (*f_map)(t_any), void (*f_free)(t_any));
int		ft_lstsize(t_list *head);
void	ft_lstadd_front(t_list **list, t_list *node);
void	ft_lstiter(t_list *head, void (*f)(t_any));
void	ft_lstadd_back(t_list **head, t_list *node_new);
void	ft_lstdelone(t_list *node, void (*f)(t_any));
void	ft_lstclear(t_list **head, void (*f)(t_any));

#endif
