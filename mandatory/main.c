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

void	print_stack(t_node *head)
{
	while (head)
	{
		ft_printf("%d\n", head->number);
		head = head->next;
	}
}

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;

	check_args(argc, argv);
	fill_stack_a(&stack_a, argv);
	fill_stack_a(&stack_b, argv);
	ss(&stack_a, &stack_b);
	ft_printf("stack a: \n");
	print_stack(stack_a);
	ft_printf("stack b: \n");
	print_stack(stack_b);
	free_list(&stack_a);
	free_list(&stack_b);
}
