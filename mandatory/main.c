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

	check_args(argc, argv);
	fill_stack_a(&stack_a, argv);
	set_node_indexes(stack_a, argv);
	sort_3(&stack_a);
	print_stack(stack_a);
	free_list(&stack_a);
}

static	void	print_stack(t_node *head)
{
	while (head)
	{
		ft_printf("\t-------------------------\n");
		ft_printf("\t\tnumber: %d\n", head->number);
		ft_printf("\t\tindex: %d\n", head->index);
		ft_printf("\t-------------------------\n");
		head = head->next;
	}
}
