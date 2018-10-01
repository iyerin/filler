.PHONY: all clean fclean re

NAME = libftprintf.a

HEADER = includes/*.h

VPATH = srcs

vpath % srcs/ft_printf

ORIGINAL_LIST = ft_atoi.c ft_bzero.c  ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
		ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
		ft_memdel.c ft_memmove.c ft_memset.c ft_strcat.c \
		ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c \
		ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c \
		ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c \
		ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c \
		ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_putchar.c ft_putnbr.c ft_putstr.c\
		ft_strtrim.c ft_tolower.c ft_toupper.c  ft_itoa_base.c\
		ft_printf.c parser.c flag_conversion.c length_conversion.c width_precision_conversion.c\
		args.c unicode_1.c unicode_2.c
 
OBJ_LIST = $(ORIGINAL_LIST:.c=.o)

CFLAGS = -Wall -Werror -Wextra -Iincludes

CC = gcc

all: $(NAME)

%.o: %.c $(HEADER)
	@ $(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJ_LIST)
	@ $(AR) rc $(NAME) $(OBJ_LIST)

clean:
	@ $(RM) $(OBJ_LIST)

fclean: clean
	@ $(RM) $(NAME) 

re: fclean all
