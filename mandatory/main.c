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

int	main(void)
{
	t_node	*node1;
	t_node	*node2;
	t_node	*node3;
	t_node	*node4;
	t_node	*node5;

	t_node *last_node;
	int		size;

	node1 = create_node(10);
	node2 = create_node(200);
	node3 = create_node(300);
	node4 = create_node(400);
	node5 = create_node(42);

	link_node(&node1, node2);
	link_node(&node1, node3);
	link_node(&node1, node4);
	link_node(&node1, node5);

	last_node = get_last_node(&node1);
	ft_printf("%d\n", last_node->number);

	size = get_list_size(node1);
	ft_printf("%d\n", size);

	free_list(&node1);

	size = get_list_size(node1);
	ft_printf("%d\n", size);
}
