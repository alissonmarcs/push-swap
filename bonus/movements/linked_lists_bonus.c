/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:25:15 by almarcos          #+#    #+#             */
/*   Updated: 2024/02/15 17:15:40 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker_bonus.h>

t_node	*create_node(long number)
{
	t_node	*node;

	node = malloc(sizeof (t_node));
	if (!node)
		return (NULL);
	ft_bzero(node, sizeof (t_node));
	node->number = number;
	return (node);
}

void	link_node(t_node **head, t_node *node)
{
	t_node	*last_node;

	if (*head == NULL)
	{
		*head = node;
		return ;
	}
	last_node = get_last_node(head);
	last_node->next = node;
}

t_node	*get_last_node(t_node **head)
{
	t_node	*last;

	last = *head;
	while (last->next != NULL)
		last = last->next;
	return (last);
}

void	free_list(t_node **head)
{
	t_node	*current;
	t_node	*next;

	current = *head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*head = NULL;
}

int	get_list_size(t_node *head)
{
	int	size;

	if (head == NULL)
		return (0);
	size = 1;
	while (head->next != NULL)
	{
		size++;
		head = head->next;
	}
	return (size);
}
