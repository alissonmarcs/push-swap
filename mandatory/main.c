/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 08:59:51 by almarcos          #+#    #+#             */
/*   Updated: 2024/01/08 09:18:59 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	print_stack(t_node *head);

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	check_args(argc, argv);
	fill_stack_a(&stack_a, argv);
	if (is_sort(stack_a) == 1)
	{
		free_list(&stack_a);
		exit(EXIT_SUCCESS);
	}
	set_node_indexes(stack_a, argv);
	ft_printf("\t\tMovements:\n");
	move_all_but_three(&stack_a, &stack_b);
	set_node_positions(stack_a);
	set_node_positions(stack_b);
	set_target_position(stack_a, stack_b);
	set_costs(stack_a, stack_b);
	ft_printf("\v\v\v\t\tStack a:\n");
	print_stack(stack_a);
	ft_printf("\v\v\v\t\tStack b:\n");
	print_stack(stack_b);
	free_list(&stack_a);
	free_list(&stack_b);
}

static	void	print_stack(t_node *head)
{
	while (head)
	{
		ft_printf("\t-------------------------------\n");
		ft_printf("\t\tNumber: %d\n", head->number);
		ft_printf("\t\tIndex: %d\n", head->index);
		ft_printf("\t\tPosition: %d\n", head->position);
		ft_printf("\t\tTarget position: %d\n", head->target_position);
		ft_printf("\t\tCost a: %d\n", head->cost_a);
		ft_printf("\t\tCost b: %d\n", head->cost_b);
		ft_printf("\t-------------------------------\n");
		head = head->next;
	}
}
