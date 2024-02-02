#include <push_swap.h>

static	int	check_duplicates(t_node *stack_a, long number)
{
	short	ocorrences;

	ocorrences = 0;
	while (stack_a)
	{
		if (stack_a->number == number)
			ocorrences++;
		if (ocorrences > 1)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

void	check_numbers(t_node **stack_a)
{
	t_node	*current;

	current = *stack_a;
	while (current)
	{
		if ((current->number < INT_MIN || current->number > INT_MAX) ||
			check_duplicates(*stack_a, current->number))
		{
			free_list(stack_a);
			error();
		}
		current = current->next;
	}
	if (is_sort(*stack_a))
	{
		free_list(stack_a);
		exit(EXIT_SUCCESS);
	}
}

void	fill_stack_a(t_node **head, char *argv[])
{
	t_node	*current_node;
	char	**split;
	int		i;
	int		j;

	i = 0;
	while (argv[++i])
	{
		split = ft_split(argv[i], ' ');
		j = -1;
		while (split[++j])
		{
			current_node = create_node(ft_atol(split[j]));
			link_node(head, current_node);
		}
		ft_free_split(split);
	}
}

void	move_all_but_three(t_node **head_stack_a, t_node **head_stack_b)
{
	int	size_stack_a;
	int	moved;
	int	index;

	index = 0;
	moved = 0;
	size_stack_a = get_list_size(*head_stack_a);
	while (size_stack_a > 6 && moved < size_stack_a && index < size_stack_a)
	{
		if ((*head_stack_a)->index <= size_stack_a / 2)
		{
			moved++;
			pb(head_stack_a, head_stack_b);
		}
		else
			ra(head_stack_a);
		index++;
	}
	while (moved + 3 < size_stack_a)
	{
		pb(head_stack_a, head_stack_b);
		moved++;
	}
}
