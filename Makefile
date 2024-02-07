NAME = push_swap
BONUS = checker
LIBFT = ./libft/libft.a
CFLAGS = -Wall -Werror -Wextra -g3 -O0

OBJECTS_FOLDER = ./obj/
HEADERS = ./includes/

MANDATORY_SOURCES = main.c linked_lists.c check_args.c initializations.c \
	swap.c push.c reverse_rotate.c rotate.c set_node_indexes.c utils.c \
	set_target_position.c set_costs.c sort.c perform_movements.c
MANDATORY_OBJECTS = $(addprefix $(OBJECTS_FOLDER),$(MANDATORY_SOURCES:.c=.o))

BONUS_SOURCES = main_bonus.c push_bonus.c reverse_rotate_bonus.c rotate_bonus.c \
	swap_bonus.c linked_lists_bonus.c check_args_bonus.c utils_bonus.c
BONUS_OBJECTS = $(addprefix $(OBJECTS_FOLDER),$(BONUS_SOURCES:.c=.o))

all: $(OBJECTS_FOLDER) libft $(NAME)

$(OBJECTS_FOLDER):
	mkdir $(OBJECTS_FOLDER)

libft:
	@make -s -C ./libft/

$(NAME): $(MANDATORY_OBJECTS) $(HEADERS)push_swap.h
	cc $(CFLAGS) $(MANDATORY_OBJECTS) $(LIBFT) -o $(NAME)

$(OBJECTS_FOLDER)%.o: ./mandatory/%.c $(HEADERS)push_swap.h
	cc $(CFLAGS) -c $< -o $@ -I $(HEADERS)

$(OBJECTS_FOLDER)%.o: mandatory/movements/%.c $(HEADERS)push_swap.h
	cc $(CFLAGS) -c $< -o $@ -I $(HEADERS)

$(OBJECTS_FOLDER)%.o: mandatory/algorithm/%.c $(HEADERS)push_swap.h
	cc $(CFLAGS) -c $< -o $@ -I $(HEADERS)

$(OBJECTS_FOLDER)%.o: mandatory/init/%.c $(HEADERS)push_swap.h
	cc $(CFLAGS) -c $< -o $@ -I $(HEADERS)

bonus: $(OBJECTS_FOLDER) libft $(BONUS)

$(BONUS): $(BONUS_OBJECTS) $(HEADERS)checker_bonus.h
	cc $(CFLAGS) $(BONUS_OBJECTS) $(LIBFT) -o $(BONUS)

$(OBJECTS_FOLDER)%.o: bonus/%.c $(HEADERS)checker_bonus.h
	cc $(CFLAGS) -c $< -o $@ -I $(HEADERS)

$(OBJECTS_FOLDER)%.o: bonus/movements/%.c $(HEADERS)checker_bonus.h
	cc $(CFLAGS) -c $< -o $@ -I $(HEADERS)

$(OBJECTS_FOLDER)%.o: bonus/validations/%.c $(HEADERS)checker_bonus.h
	cc $(CFLAGS) -c $< -o $@ -I $(HEADERS)

clean:
	rm -rf $(OBJECTS_FOLDER)

fclean: clean
	rm -rf $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re libft bonus
