NAME =			libftprintf.a

CC =			gcc
FLAGS = 
INCLUDES =		"includes"

COMPILED =		ft_printf.o \
				get_location.o \
				gna.o \
				guna.o \
				is_bin.o \
				is_oct.o \
				is_ptr.o \
				is_str.o \
				is_hex.o \
				is_dec.o \
				precision_pad.o \
				print_char.o \
				print_conversion.o \
				print_format_error.o \
				print_normal.o \
				print_wide_chars.o \
				ps_conv.o \
				ps_flg.o \
				ps_len.o \
				ps_prec.o \
				ps_spec.o \
				ps_w.o \
				run_formatter.o \
				total_padding.o \
				validate_conversion.o \
				validate_flags_ignored.o \
				validate_flags.o \
				ft_islower.o \
				ft_isupper.o \
				ft_tolower.o \
				ft_toupper.o \
				ft_isdigit.o \
				ft_isalnum.o \
				ft_isascii.o \
				ft_isprint.o \
				ft_isspace.o \
				ft_strlen.o \
				ft_strnlen.o \
				ft_strchr.o \
				ft_strrchr.o \
				ft_strcmp.o \
				ft_strncmp.o \
				ft_strstr.o \
				ft_strnstr.o \
				ft_strcpy.o \
				ft_strncpy.o \
				ft_strdup.o \
				ft_strcat.o \
				ft_strncat.o \
				ft_strlcat.o \
				ft_memcpy.o \
				ft_memccpy.o \
				ft_memmove.o \
				ft_memcmp.o \
				ft_memset.o \
				ft_memchr.o \
				ft_bzero.o \
				ft_atoi.o \
				ft_memalloc.o \
				ft_memdel.o \
				ft_strnew.o \
				ft_strdel.o \
				ft_strclr.o \
				ft_striter.o \
				ft_striteri.o \
				ft_strmap.o \
				ft_strmapi.o \
				ft_strequ.o \
				ft_strnequ.o \
				ft_strsub.o \
				ft_strjoin.o \
				ft_strtrim.o \
				ft_strsplit.o \
				ft_itoa.o \
				ft_putchar.o \
				ft_putstr.o \
				ft_putendl.o \
				ft_putnbr.o \
				ft_putchar_fd.o \
				ft_putstr_fd.o \
				ft_putendl_fd.o \
				ft_putnbr_fd.o \
				ft_abs.o  \
				ft_itoa_large.o \
				ft_itoa_ularge.o \
				ft_basetoa.o \
				ft_strtolower.o \
				ft_putnbr_large_fd.o \
				ft_strlen_wide.o \
				ft_countchars.o \
				ft_putcharn_fd.o \
				ft_putstr_literal_fd.o \
				ft_putstrn_fd.o  \
				ft_atoi_add_digit_u.o \
				ft_atoi_add_digit.o \
				ft_atoi_add_digit_ularge.o \
				ft_putcharn.o \
				ft_abs_large.o \
				ft_count_digits_ularge.o \
				ft_itoa_write.o 

all: $(NAME)

$(NAME): $(COMPILED)
	ar rc $(NAME) $(COMPILED)
	ranlib $(NAME)

$(COMPILED): %.o: %.c
	$(CC) -c $(FLAGS) $< -o $@ -I $(INCLUDES)

clean:
	-/bin/rm -f $(COMPILED)

fclean: clean
	-/bin/rm -f $(NAME)

re: fclean all
