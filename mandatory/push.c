#include "push_swap.h"

static	void	push(t_node **from, t_node **to)
{
	t_node	*new_head;

	new_head = *from;
	*from = (*from)->next;
	new_head->next = *to;
	*to = new_head;
}

void	pa(t_node **head_stack_a, t_node **head_stack_b)
{
	push(head_stack_b, head_stack_a);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_node **head_stack_a, t_node **head_stack_b)
{
	push(head_stack_a, head_stack_b);
	ft_putstr_fd("pb\n", 1);
}
