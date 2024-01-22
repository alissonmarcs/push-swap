#include "push_swap.h"

static	short	get_largest_index(t_node *head);

short	is_sort(t_node *head)
{
	while (1)
	{
		if (head->next == NULL)
			return (1);
		if (head->next->number > head->number)
			head = head->next;
		else
			return (0);
	}
}

void	sort_3(t_node **head)
{
	short	largest_index;

	if (is_sort(*head))
		return ;
	largest_index = get_largest_index(*head);
	if ((*head)->index == largest_index)
		ra(head);
	if ((*head)->next->index == largest_index)
		rra(head);
	if ((*head)->index > (*head)->next->index)
		sa(head);
}

static	short	get_largest_index(t_node *head)
{
	short	index;

	index = 0;
	while (1)
	{
		if (head->index > index)
			index = head->index;
		if (head->next == NULL)
			return (index);
		head = head->next;
	}
}
