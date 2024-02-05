/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:43:23 by almarcos          #+#    #+#             */
/*   Updated: 2024/02/02 16:43:24 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	rra(t_node **stack_a)
{
	reverse_rotate(stack_a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_node **stack_b)
{
	reverse_rotate(stack_b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putstr_fd("rrr\n", 1);
}
