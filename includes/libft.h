#ifndef LIBFT_H
# define LIBFT_H

/*
** included for NULL, size_t
*/

# include <stdlib.h>
# include <unistd.h>

/*
** memory
*/
void			ft_atoi_add_digit(const char c, int *number);
void			ft_atoi_add_digit_large(const char c, intmax_t *number);
void			ft_atoi_add_digit_u(const char c, unsigned int *number);
void			ft_atoi_add_digit_ularge(const char c, uintmax_t *number);
char			*ft_basetoa(uintmax_t number, int base);
size_t			ft_countchars(char const *haystack, char needle
										, size_t length);
char			*ft_itoa_large(intmax_t number);
static void		write_digits(char *current, uintmax_t number);
static void		write_chars(char *first, char *now, uintmax_t number);
int				ft_memcmp(const void *original, const void *new, size_t len);
void			*ft_memcpy(void *dest, const void *source, size_t len);
void			*ft_memccpy(void *dest, const void *source, int c, size_t len);
void			*ft_memmove(void *dest, const void *source, size_t len);
void			*ft_memset(void *destinatino, int int_value, size_t len);
void			*ft_memchr(const void *haystack, int needle, size_t len);
void			ft_bzero(void *string, size_t len);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **pointer);
char			*ft_strnew(size_t size);
void			ft_strdel(char **pointer);
void			ft_putnbr_justify_right(int number
											, size_t total
											, char fill);
void			ft_putnbr_large_fd(intmax_t number, int file_descriptor);
void			ft_putcharn(char c, size_t number);
size_t			ft_countchars(char const *haystack, char needle
										, size_t length);

/*
** character
*/
int				ft_islower(int c);
int				ft_isupper(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_isdigit(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);

/*
** string
*/
size_t			ft_strlen(const char *source);
size_t			ft_strnlen(const char *source, size_t max);
char			*ft_strchr(const char *haystack, int needle);
char			*ft_strrchr(const char *haystack, int needle);
int				ft_strcmp(const char *first, const char *second);
int				ft_strequ(const char *first, const char *second);
int				ft_strncmp(const char *first, const char *second, size_t max);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle
							, size_t len);
char			*ft_strcpy(char *dest, const char *source);
char			*ft_strncpy(char *dest, const char *source, size_t max);
char			*ft_strdup(const char *source);
char			*ft_strcat(char *first, const char *second);
char			*ft_strncat(char *first, const char *second, size_t len);
size_t			ft_strlcat(char *first, const char *second, size_t size);
void			ft_strclr(char *string);
void			ft_striter(char *string, void (*func)(char *));
void			ft_striteri(char *string, void (*func)(unsigned int, char *));
char			*ft_strmap(const char *string, char (*func)(char));
char			*ft_strmapi(const char *string
							, char (*func)(unsigned int, char));
int				ft_strequ(char const *first, char const *second);
int				ft_strnequ(char const *first, char const *second, size_t len);
char			*ft_strsub(char const *string, size_t start, size_t len);
char			*ft_strjoin(char const *first, char const *second);
char			*ft_strtrim(char const *string);
char			**ft_strsplit(char const *string, char c);
char			*ft_itoa(int number);
void			ft_putchar(char c);
void			ft_putstr(char const *source);
void			ft_putendl(char const *source);
void			ft_putnbr(int number);

void			ft_putchar_fd(char c, int file_descriptor);
void			ft_putstr_fd(char const *source, int file_descriptor);
void			ft_putendl_fd(char const *source, int file_descriptor);
void			ft_putnbr_fd(int number, int file_descriptor);

/*
** printing
*/
void			ft_putchar(char c);

/*
** other
*/
int				ft_atoi(const char *str);
int				ft_abs(int number);
intmax_t		ft_abs_large(intmax_t number);
void			ft_atoi_add_digit_large(const char c, intmax_t *number);
int				ft_count_digits(int number);
void			ft_atoi_add_digit_u(const char c, unsigned int *number);
void			ft_atoi_add_digit_ularge(const char c, uintmax_t *number);

#endif
