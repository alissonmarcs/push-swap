/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:43:23 by almarcos          #+#    #+#             */
/*   Updated: 2024/02/15 17:15:40 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker_bonus.h>

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

void	rra(t_node **stack_a)
{
	if (!(*stack_a)->next)
		return ;
	reverse_rotate(stack_a);
}

void	rrb(t_node **stack_b)
{
	if (!(*stack_b)->next)
		return ;
	reverse_rotate(stack_b);
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	if (!(*stack_a)->next || !(*stack_b)->next)
		return ;
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
