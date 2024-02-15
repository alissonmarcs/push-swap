/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 08:59:51 by almarcos          #+#    #+#             */
/*   Updated: 2024/02/15 17:31:30 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	check_args(argc, argv);
	fill_stack_a(&stack_a, argv);
	check_numbers(&stack_a);
	set_node_indexes(stack_a, get_list_size(stack_a));
	sort(&stack_a, &stack_b);
	free_list(&stack_a);
}
