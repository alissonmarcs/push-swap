#include <push_swap.h>

static	int	get_target_position(t_node *stack_a, int b_index);

void	set_target_position(t_node *stack_a, t_node *stack_b)
{
	while (stack_b)
	{
		stack_b->target_position = get_target_position(stack_a, stack_b->index);
		stack_b = stack_b->next;
	}
}

static	int	get_target_position(t_node *stack_a, int b_index)
{
	int		target_position;
	int		target_index;
	t_node	*head;

	target_position = -1;
	head = stack_a;
	target_index = INT_MAX;
	while (head)
	{
		if (head->index > b_index && head->index < target_index)
		{
			target_index = head->index;
			target_position = head->position;
		}
		head = head->next;
	}
	if (target_position == -1)
		return (get_smaller_index_position(stack_a));
	return (target_position);
}

int	get_smaller_index_position(t_node *stack_a)
{
	int		smaller_index;
	t_node	*target;

	target = stack_a;
	smaller_index = stack_a->index;
	while (stack_a)
	{
		if (stack_a->index < smaller_index)
		{
			smaller_index = stack_a->index;
			target = stack_a;
		}
		stack_a = stack_a->next;
	}
	return (target->position);
}
