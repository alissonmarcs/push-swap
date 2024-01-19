NAME = push_swap
LIBFT = ./libft/libft.a
CFLAGS = -Wall -Werror -Wextra -g3 -O0

OBJECTS_FOLDER = ./obj/

MANDATORY_FOLDER = ./mandatory/
MANDATORY_SOURCES = $(addprefix $(OBJECTS_FOLDER), main.c linked_lists.c check_args.c \
	initializations.c swap.c push.c reverse_rotate.c rotate.c)
MANDATORY_OBJECTS = $(subst $(MANDATORY_FOLDER),$(OBJECTS_FOLDER),$(MANDATORY_SOURCES:.c=.o))

all: $(OBJECTS_FOLDER) $(LIBFT) $(NAME)

$(OBJECTS_FOLDER):
	mkdir $(OBJECTS_FOLDER)

$(LIBFT):
	make -C ./libft/

$(NAME): $(MANDATORY_OBJECTS) $(MANDATORY_FOLDER)push_swap.h
	cc $(CFLAGS) $(MANDATORY_OBJECTS) $(LIBFT) -o $(NAME)

$(OBJECTS_FOLDER)%.o: $(MANDATORY_FOLDER)%.c $(MANDATORY_FOLDER)push_swap.h
	cc $(CFLAGS) -c $< -o $@

val:
	valgrind -q --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap

clean:
	rm -rf $(OBJECTS_FOLDER)*

fclean: clean
	rm -rf $(NAME)

re: fclean all


.PHONY: all clean fclean re val
