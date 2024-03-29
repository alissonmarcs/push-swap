# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alisson <alisson@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/20 10:35:42 by almarcos          #+#    #+#              #
#    Updated: 2023/11/22 10:09:23 by alisson          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAGS = -Wall -Werror -Wextra -g3 -O0
OBJECTS_FOLDER = ./obj/

SOURCES = ft_isalnum.c ft_isalpha.c ft_isascii.c \
	ft_isdigit.c ft_isprint.c ft_memset.c ft_strlen.c \
	ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcat.c \
	ft_strlcpy.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
	ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
	ft_substr.c ft_putchar_fd.c ft_putstr_fd.c ft_strjoin.c\
	ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
	ft_striteri.c ft_putendl_fd.c ft_putnbr_fd.c ft_abs.c \
	ft_hex_to_int.c ft_free_split.c ft_lstnew_bonus.c \
	ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
	ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c ft_atol.c\

GNL_SOURCE = get_next_line.c

FT_PRINTF_SOURCE = ft_printf.c

OBJECTS = $(addprefix $(OBJECTS_FOLDER), $(SOURCES:.c=.o))
GNL_OBJECT = $(addprefix $(OBJECTS_FOLDER), $(GNL_SOURCE:.c=.o))
FT_PRINTF_OBJECT = $(addprefix $(OBJECTS_FOLDER), $(FT_PRINTF_SOURCE:.c=.o))

all: $(OBJECTS_FOLDER) $(NAME)

$(OBJECTS_FOLDER):
	mkdir $(OBJECTS_FOLDER)

$(NAME): $(OBJECTS) $(GNL_OBJECT) $(FT_PRINTF_OBJECT)

$(OBJECTS_FOLDER)%.o: %.c ../includes/libft.h
	cc $(CFLAGS) -c $< -o $@ -I ../includes
	ar rcs $(NAME) $@

clean:
	rm -rf $(OBJECTS_FOLDER)*

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
