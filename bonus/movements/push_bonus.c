/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:43:18 by almarcos          #+#    #+#             */
/*   Updated: 2024/02/15 17:15:40 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker_bonus.h>

static	void	push(t_node **source, t_node **dest)
{
	t_node	*head_dest;

	head_dest = *source;
	*source = (*source)->next;
	head_dest->next = *dest;
	*dest = head_dest;
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	push(stack_b, stack_a);
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	push(stack_a, stack_b);
}
