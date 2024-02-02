/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:42:57 by almarcos          #+#    #+#             */
/*   Updated: 2024/02/02 16:42:58 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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

void	sort_three_elements(t_node **head)
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

void	set_node_positions(t_node *stack)
{
	int	position;

	position = 0;
	while (1)
	{
		stack->position = position;
		position++;
		stack = stack->next;
		if (stack == NULL)
			return ;
	}
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
