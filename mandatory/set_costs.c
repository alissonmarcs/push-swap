#include "push_swap.h"

void	set_costs(t_node *stack_a, t_node *stack_b)
{
	int size_a;
	int size_b;

	size_a = get_list_size(stack_a);
	size_b = get_list_size(stack_b);
	while (stack_b)
	{
		if (stack_b->position <= size_b / 2)
			stack_b->cost_b = stack_b->position;
		else
			stack_b->cost_b = (size_b - stack_b->position) * -1;
		if (stack_b->target_position <= size_a / 2)
			stack_b->cost_a = stack_b->target_position;
		else
			stack_b->cost_a = (size_a - stack_b->target_position) * -1;
		stack_b = stack_b->next;
	}
}
