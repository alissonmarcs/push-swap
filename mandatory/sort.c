#include "push_swap.h"

static	void		sort_more_than_three(t_node **head_stack_a, t_node **head_stack_b);

void	sort(t_node **head_stack_a, t_node **head_stack_b)
{
	int	size;

	size = get_list_size(*head_stack_a);
	if (size == 2)
		sa(head_stack_a);
	else if (size == 3)
		sort_three_elements(head_stack_a);
	else
		sort_more_than_three(head_stack_a, head_stack_b);
}

static	void	sort_more_than_three(t_node **head_stack_a, t_node **head_stack_b)
{
	move_all_but_three(head_stack_a, head_stack_b);
	sort_three_elements(head_stack_a);
	while (*head_stack_b)
	{
		set_node_positions(*head_stack_a);
		set_node_positions(*head_stack_b);
		set_target_position(*head_stack_a, *head_stack_b);
		set_costs(*head_stack_a, *head_stack_b);
		perform_movements(head_stack_a, head_stack_b);
	}
}
