#include "push_swap.h"

void	fill_stack_a(t_node **head, char *argv[])
{
	t_node	*stack_a;
	t_node	*current_node;
	int		i;

	stack_a = NULL;
	i = 0;
	while (argv[++i])
	{
		current_node = create_node(ft_atoi(argv[i]));
		link_node(&stack_a, current_node);
	}
	*head = stack_a;
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
