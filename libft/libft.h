/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:29:06 by mvidal-a          #+#    #+#             */
/*   Updated: 2022/12/02 20:27:04 by mvidal-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdint.h>
# include <sys/types.h>

# define ERROR	-1

# define TRUE	1
# define FALSE	0

# define SUCCESS	1
# define FAILURE	0

# define NOT_FOUND	-1

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef	uint8_t	t_byte;
typedef	uint8_t	t_bool;

/*
**	part 1
*/

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
char			*ft_strnstr(const char *haystack,
		const char *needle, size_t len);
int				ft_atoi(const char *str);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(const char *s1);

/*
**	part 2
*/

char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
t_bool			ft_putchar_fd(char c, int fd);
t_bool			ft_putstr_fd(const char *s, int fd);
t_bool			ft_putendl_fd(const char *s, int fd);
t_bool			ft_putnbr_fd(int n, int fd);

/*
**	bonus (chained list management)
*/

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **alst, t_list *new);
size_t			ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
		void (*del)(void *));

/*
**	custom functions
*/

int				get_next_line(int fd, char **line);
ssize_t			ft_index(char *haystack, char needle);
void			ft_swap(void **a, void **b);

int				ft_isspace(int c);
char*			skip_spaces(char* str);
char*			skip_int(char* str);
char*			skip_float(char* str);
int				blank_str(char *line);
int				ft_isset(char c, char *set);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_isnumber(const char* str);
long			ft_atol(const char* str);
int8_t			ft_atoi_sign(const char* str, int* nb);
double			ft_atof(const char* str);
t_bool			ft_isint(char* str);

char			*strjoin_free(char *s1, char const *s2);

void			*ft_lstshift(t_list **lst);

size_t			ft_varnamelen(char *str);
char			*get_var_value(char **vars, char *name, size_t name_len);
ssize_t			get_var_pos(char **vars, char *name, size_t name_len);

int				ft_printarray_fd(char **array, int fd);
size_t			ft_arraylen(char **array);
void			free_str_array(char **array);
char			**dup_str_array(char **array);
char			**push_str_to_array(char **array, char *str);
char			**rm_str_from_array(char **array, size_t str_pos);
void			sort_str_array(char **array);

int				*push_int_to_array(int *array, size_t array_size, int nb);

int				ft_set_index(char c, char *set);

double			ft_pow(double nb, int power);
int				ft_sqrt(int nb);
long			ft_sqrt_long(long nb);
double			ft_sqrt_double(double nb);

#endif
