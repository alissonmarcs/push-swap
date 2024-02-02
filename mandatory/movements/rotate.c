#include <push_swap.h>

static	void	rotate(t_node **head)
{
	t_node	*update_head;
	t_node	*new_tail;
	t_node	*current_tail;

	current_tail = get_last_node(head);
	new_tail = *head;
	update_head = (*head)->next;
	*head = update_head;
	current_tail->next = new_tail;
	new_tail->next = NULL;
}

void	ra(t_node **stack_a)
{
	rotate(stack_a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_node **stack_b)
{
	rotate(stack_b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr_fd("rr\n", 1);
}
