#include "push_swap.h"

static	t_node	*find_cheapest(t_node *stack_b);
static	void	perform_movements(t_node **stack_a, t_node **stack_b);
static	void	sort_more_than_three(t_node **head_stack_a, t_node **head_stack_b);
static	void	do_moviments(t_node **stack_a, t_node **stack_b, int cost_a, int cost_b);

void			sort(t_node **head_stack_a, t_node **head_stack_b)
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

static	void	perform_movements(t_node **stack_a, t_node **stack_b)
{
	t_node	*to_move;

	to_move = find_cheapest(*stack_b);
	do_moviments(stack_a, stack_b, to_move->cost_a, to_move->cost_b);
}

static	void	do_moviments(t_node **stack_a, t_node **stack_b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		while (++cost_a && ++cost_b)
			rrr(stack_a, stack_b);
	if (cost_a > 0 && cost_b > 0)
		while (--cost_a && --cost_b)
			rr(stack_a, stack_b);
	if (cost_a != 0)
	{
		if (cost_a < 0)
			while (++cost_a)
				rra(stack_a);
		else
		{
			while (--cost_a)
				ra(stack_a);
		}
	}
	if (cost_b != 0)
	{
		if (cost_b < 0)
			while (++cost_b)
				rrb(stack_b);
		else
		{
			while (--cost_b)
				rb(stack_b);
		}
	}
	pa(stack_a, stack_b);
}

static	t_node	*find_cheapest(t_node *stack_b)
{
	t_node	*to_move;
	int		current_cost;
	int		cheapest_cost;

	current_cost = INT_MAX;
	cheapest_cost = INT_MAX;
	while (stack_b)
	{
		current_cost = ft_abs(stack_b->cost_a) + ft_abs(stack_b->cost_b);
		if (current_cost < cheapest_cost)
		{
			cheapest_cost = current_cost;
			to_move = stack_b;
		}
		stack_b = stack_b->next;
	}
	return (to_move);
}
