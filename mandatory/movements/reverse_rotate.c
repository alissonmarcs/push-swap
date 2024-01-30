#include <push_swap.h>

static	void	reverse_rotate(t_node **head)
{
	t_node	*new_head;
	t_node	*last_but_one;

	last_but_one = *head;
	while (last_but_one->next->next != NULL)
		last_but_one = last_but_one->next;
	new_head = last_but_one->next;
	new_head->next = *head;
	*head = new_head;
	last_but_one->next = NULL;
}

void	rra(t_node **head_stack_a)
{
	reverse_rotate(head_stack_a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_node **head_stack_b)
{
	reverse_rotate(head_stack_b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_node **head_stack_a, t_node **head_stack_b)
{
	reverse_rotate(head_stack_a);
	reverse_rotate(head_stack_b);
	ft_putstr_fd("rrr\n", 1);
}
