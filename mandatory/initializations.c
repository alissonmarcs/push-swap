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
