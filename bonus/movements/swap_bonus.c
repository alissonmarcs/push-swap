/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:43:31 by almarcos          #+#    #+#             */
/*   Updated: 2024/02/15 17:15:40 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker_bonus.h>

static	void	swap(t_node **head)
{
	t_node	*new_head;
	t_node	*old_head;
	t_node	*third_node;

	if (!*head || !(*head)->next)
		return ;
	old_head = *head;
	new_head = (*head)->next;
	third_node = (*head)->next->next;
	*head = new_head;
	new_head->next = old_head;
	old_head->next = third_node;
}

void	sa(t_node **stack_a)
{
	swap(stack_a);
}

void	sb(t_node **stack_b)
{
	swap(stack_b);
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
