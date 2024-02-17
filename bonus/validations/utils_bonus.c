/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:50:23 by almarcos          #+#    #+#             */
/*   Updated: 2024/02/05 19:50:55 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker_bonus.h>

static	int	check_duplicates(t_node *stack_a, long number)
{
	short	ocorrences;

	ocorrences = 0;
	while (stack_a)
	{
		if (stack_a->number == number)
			ocorrences++;
		if (ocorrences > 1)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

void	check_numbers(t_node **stack_a)
{
	t_node	*current;

	current = *stack_a;
	while (current)
	{
		if ((current->number < INT_MIN || current->number > INT_MAX)
			|| check_duplicates(*stack_a, current->number))
		{
			free_list(stack_a);
			error();
		}
		current = current->next;
	}
}

void	fill_stack_a(t_node **head, char *argv[])
{
	t_node	*current_node;
	char	**split;
	int		i;
	int		j;

	i = 0;
	while (argv[++i])
	{
		split = ft_split(argv[i], ' ');
		j = -1;
		while (split[++j])
		{
			current_node = create_node(ft_atol(split[j]));
			link_node(head, current_node);
		}
		ft_free_split(split);
	}
}

short	is_sort(t_node *head)
{
	if (!head)
		return (0);
	while (1)
	{
		if (head->next == NULL)
			return (1);
		if (head->next->number > head->number)
			head = head->next;
		else
			return (0);
	}
}
