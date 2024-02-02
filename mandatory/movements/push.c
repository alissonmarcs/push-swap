#include <push_swap.h>

static	void	push(t_node **source, t_node **dest)
{
	t_node	*head_dest;

	head_dest = *source;
	*source = (*source)->next;
	head_dest->next = *dest;
	*dest = head_dest;
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	push(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
}
