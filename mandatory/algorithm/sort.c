/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:26:00 by almarcos          #+#    #+#             */
/*   Updated: 2024/02/02 16:32:02 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static	void		shift(t_node **stack_a);
static	void		sort_more_than_three(t_node **head_stack_a,
						t_node **head_stack_b);

void	sort(t_node **head_stack_a, t_node **head_stack_b)
{
	int	size;

	size = get_list_size(*head_stack_a);
	if (size == 2)
		sa(head_stack_a);
	else if (size == 3)
		sort_three_elements(head_stack_a);
	else
		sort_more_than_three(head_stack_a, head_stack_b);
}

static	void	sort_more_than_three(t_node **head_stack_a,
					t_node **head_stack_b)
{
	move_all_but_three(head_stack_a, head_stack_b);
	sort_three_elements(head_stack_a);
	while (*head_stack_b)
	{
		set_node_positions(*head_stack_a);
		set_node_positions(*head_stack_b);
		set_target_position(*head_stack_a, *head_stack_b);
		set_costs(*head_stack_a, *head_stack_b);
		perform_movements(head_stack_a, head_stack_b);
	}
	set_node_positions(*head_stack_a);
	shift(head_stack_a);
}

static	void	shift(t_node **stack_a)
{
	int	size;
	int	smaller;

	size = get_list_size(*stack_a);
	while (1)
	{
		smaller = get_smaller_index_position(*stack_a);
		if (smaller == 0)
			return ;
		if (smaller <= size / 2)
			ra(stack_a);
		else
			rra(stack_a);
		set_node_positions(*stack_a);
	}
}
