NAME = push_swap
BONUS = checker
LIBFT = ./libft/libft.a
CFLAGS = -Wall -Werror -Wextra -g3 -O0

MANDATORY_SOURCES = main.c linked_lists.c check_args.c initializations.c \
	swap.c push.c reverse_rotate.c rotate.c set_node_indexes.c utils.c \
	set_target_position.c set_costs.c sort.c perform_movements.c
MANDATORY_OBJECTS = $(addprefix ./obj/,$(MANDATORY_SOURCES:.c=.o))

BONUS_SOURCES = main_bonus.c push_bonus.c reverse_rotate_bonus.c rotate_bonus.c \
	swap_bonus.c linked_lists_bonus.c check_args_bonus.c
BONUS_OBJECTS = $(addprefix ./obj/,$(BONUS_SOURCES:.c=.o))

all: ./obj/ libft $(NAME)

./obj/:
	mkdir ./obj/

./obj/%.o: mandatory/movements/%.c ./includes/push_swap.h
	cc $(CFLAGS) -c $< -o $@ -I ./includes/

./obj/%.o: mandatory/algorithm/%.c ./includes/push_swap.h
	cc $(CFLAGS) -c $< -o $@ -I ./includes/

./obj/%.o: mandatory/init/%.c ./includes/push_swap.h
	cc $(CFLAGS) -c $< -o $@ -I ./includes/

./obj/%.o: ./mandatory/%.c ./includes/push_swap.h
	cc $(CFLAGS) -c $< -o $@ -I ./includes/

bonus: libft $(BONUS)

$(BONUS): $(BONUS_OBJECTS) ./includes/checker_bonus.h
	cc $(CFLAGS) $(BONUS_OBJECTS) $(LIBFT) -o $(BONUS)

./obj/%.o: bonus/%.c ./includes/checker_bonus.h
	cc $(CFLAGS) -c $< -o $@ -I ./includes/

./obj/%.o: bonus/movements/%.c ./includes/checker_bonus.h
	cc $(CFLAGS) -c $< -o $@ -I ./includes/

./obj/%.o: bonus/validations/%.c ./includes/checker_bonus.h
	cc $(CFLAGS) -c $< -o $@ -I ./includes/

libft:
	@make -s -C ./libft/

$(NAME): $(MANDATORY_OBJECTS) ./includes/push_swap.h
	cc $(CFLAGS) $(MANDATORY_OBJECTS) $(LIBFT) -o $(NAME)

clean:
	rm -rf ./obj/

fclean: clean
	rm -rf $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re libft bonus
