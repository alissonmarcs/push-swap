#include "push_swap.h"

static	void	swap(t_node **head)
{
	t_node	*new_head;
	t_node	*old_head;
	t_node	*third_node;

	old_head = *head;
	new_head = (*head)->next;
	third_node = (*head)->next->next;
	*head = new_head;
	new_head->next = old_head;
	old_head->next = third_node;
}

void	sa(t_node **head_stack_a)
{
	swap(head_stack_a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_node **head_stack_b)
{
	swap(head_stack_b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_node **head_stack_a, t_node **head_stack_b)
{
	sa(head_stack_a);
	sb(head_stack_b);
	ft_putstr_fd("ss\n", 1);
}