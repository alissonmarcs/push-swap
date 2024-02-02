/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_node_indexes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:25:48 by almarcos          #+#    #+#             */
/*   Updated: 2024/02/02 16:25:49 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	set_node_indexes(t_node *head, int stack_size)
{
	t_node	*larger;
	t_node	*head_ref;
	long	current_larger;

	head_ref = head;
	while (stack_size)
	{
		current_larger = INT_MIN;
		larger = NULL;
		while (head)
		{
			if (head->number == INT_MIN)
				*(int *) &head->index = 1;
			if (head->number > current_larger && head->index == 0)
			{
				current_larger = head->number;
				larger = head;
			}
			head = head->next;
		}
		if (larger != NULL)
			*(int *) &larger->index = stack_size;
		head = head_ref;
		stack_size--;
	}
}
