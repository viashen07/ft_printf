/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgovende <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 17:42:05 by vgovende          #+#    #+#             */
/*   Updated: 2016/06/05 17:43:15 by vgovende         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <wchar.h>
# include <limits.h>
# include <stdint.h>
# include <stdlib.h>
# include "libft.h"
# define RED							"\x1B[31m"
# define GREEN							"\x1B[32m"
# define YELLOW							"\x1B[33m"
# define BLUE							"\x1B[34m"
# define MAGENTA						"\x1B[35m"
# define CYAN							"\x1B[36m"
# define WHITE							"\x1B[37m"
# define NORMAL							"\x1B[0m"
# define EOC							"\033[0m"

# define ERROR							1
# define OKAY							0
# define LARGEST_STAR_ARGUMENT			((unsigned int)INT_MAX)

typedef char			t_bool;

typedef struct			s_format
{
	const char	*str;
	size_t		i;
	size_t		bytes;
}						t_format;

typedef struct			s_flags
{
	t_bool		l_justify;
	t_bool		zeros;
	t_bool		sign;
	t_bool		begin_blank;
	t_bool		hashtag;
}						t_flags;

typedef enum			e_length
{
	DEFAULT_LENGTH,
	HH,
	H,
	L,
	LL,
	J,
	Z
}						t_length;

typedef enum			e_specifier
{
	BINARY,
	S_DECIMAL,
	U_DECIMAL,
	OCTAL,
	HEX_LOWER,
	HEX_UPPER,
	CHAR,
	STRING,
	POINTER,
	INVALID_SPECIFIER
}						t_specifier;

typedef enum			e_color
{
	REDC,
	GREENC,
	YELLOWC,
	BLUEC,
	MAGENTAC,
	CYANC,
	WHITEC,
	NORMALC,
	EOCC,
	INVALID_COLOR
}						t_color;

typedef struct			s_conversion
{
	t_flags				flags;
	unsigned int		width;
	unsigned int		precision;
	t_bool				precision_set;
	t_length			len;
	t_specifier			spec;
	t_color				color;
}						t_conversion;

int						ft_printf(const char *format_string, ...);
void					run_formatter(t_format *format, va_list arguments);
int						ps_conv(t_conversion *conversion
									, va_list arguments
									, t_format *format);
int						ps_flg(t_conversion *conversion, t_format *format);
int						ps_w(t_conversion *conversion
		, va_list arguments
		, t_format *format);
int						ps_prec(t_conversion *conversion
		, va_list arguments
		, t_format *format);
int						ps_len(t_conversion *conversion
		, t_format *format);
int						ps_spec(t_conversion *conversion
		, t_format *format);
int						validate_conv(t_conversion *conversion
		, t_format *format);
int						validate_flags(t_conversion *conversion
		, t_format *format);
void					validate_flags_ignored(t_conversion *conversion
		, t_format *format);
void					print_conversion(t_conversion *conversion
		, va_list arguments
		, t_format *format);
void					print_normal(t_conversion *conversion
		, va_list arguments
		, t_format *format);
void					print_char(t_conversion *conversion, char argument
		, t_format *format);
void					print_wide_chars(t_conversion *conversion
		, wchar_t *string, size_t length
		, size_t *written);
void					print_format_error(t_format *format);
const char				*get_location(t_format *format);
intmax_t				gna(t_length length, va_list arguments);
uintmax_t				guna(t_length length
		, va_list arguments);
char					*is_dec(t_conversion *conversion
		, va_list arguments);
char					*is_str(t_conversion *conversion
		, va_list arguments);
char					*is_ptr(t_conversion *conversion
		, va_list arguments);
char					*is_bin(t_conversion *conv
		, va_list ap);
char					*is_hex(t_conversion *conversion
		, va_list arguments);
char					*is_octal(t_conversion *conversion
		, va_list arguments);
void					total_padding(t_conversion *conversion
		, char **str);
void					precision_pad(t_conversion *conversion
		, char **str);

#endif
