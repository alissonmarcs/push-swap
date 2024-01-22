#include "push_swap.h"

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
