#include "push_swap.h"

static	t_node	*find_cheapest(t_node *stack_b);
static	void	move_stack_a(t_node **stack_a, t_node *to_move);
static	void	move_stack_b(t_node **stack_b, t_node *to_move);
static	void	move_both_stacks(t_node **stack_a, t_node **stack_b, t_node *to_move);

void	perform_movements(t_node **stack_a, t_node **stack_b)
{
	t_node	*to_move;

	to_move = find_cheapest(*stack_b);
	move_both_stacks(stack_a, stack_b, to_move);
	move_stack_a(stack_a, to_move);
	move_stack_b(stack_b, to_move);
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

static	void	move_stack_a(t_node **stack_a, t_node *to_move)
{
	if (to_move->cost_a > 0)
		while (to_move->cost_a > 0)
		{
			to_move->cost_a--;
			ra(stack_a);
		}
	else if (to_move->cost_a < 0)
		while (to_move->cost_a < 0)
		{
			to_move->cost_a++;
			rra(stack_a);
		}
}

static	void	move_stack_b(t_node **stack_b, t_node *to_move)
{
	if (to_move->cost_b > 0)
		while (to_move->cost_b > 0)
		{
			to_move->cost_b--;
			rb(stack_b);
		}
	else if (to_move->cost_b < 0)
		while (to_move->cost_b < 0)
		{
			to_move->cost_b++;
			rrb(stack_b);
		}
}

static	void	move_both_stacks(t_node **stack_a, t_node **stack_b, t_node *to_move)
{
	if (to_move->cost_a < 0 && to_move->cost_b < 0)
		while (to_move->cost_a && to_move->cost_b)
		{
			to_move->cost_a++;
			to_move->cost_b++;
			rrr(stack_a, stack_b);
		}
	if (to_move->cost_a > 0 && to_move->cost_b > 0)
		while (to_move->cost_a && to_move->cost_b)
		{
			to_move->cost_a--;
			to_move->cost_b--;
			rr(stack_a, stack_b);
		}
}
