/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 19:49:48 by almarcos          #+#    #+#             */
/*   Updated: 2024/02/07 14:51:45 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker_bonus.h>

static	void	read_movements(t_node **stack_a, t_node **stack_b);
static	void	perform_movements(t_node **stack_a, t_node **stack_b,
					char *line);
static	void	safe_exit(t_node **stack_a, t_node **stack_b, char *line);

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	check_args(argc, argv);
	fill_stack_a(&stack_a, argv);
	check_numbers(&stack_a);
	read_movements(&stack_a, &stack_b);
	if (is_sort(stack_a) && !stack_b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	free_list(&stack_a);
	free_list(&stack_b);
	exit(EXIT_SUCCESS);
}

static	void	read_movements(t_node **stack_a, t_node **stack_b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		perform_movements(stack_a, stack_b, line);
		free(line);
	}
	get_next_line(-1);
}

static	void	perform_movements(t_node **stack_a, t_node **stack_b,
					char *line)
{
	if (!ft_strncmp(line, "sa\n", 3))
		sa(stack_a);
	else if (!ft_strncmp(line, "sb\n", 3))
		sb(stack_b);
	else if (!ft_strncmp(line, "ss\n", 3))
		ss(stack_a, stack_b);
	else if (!ft_strncmp(line, "pa\n", 3))
		pa(stack_a, stack_b);
	else if (!ft_strncmp(line, "pb\n", 3))
		pb(stack_a, stack_b);
	else if (!ft_strncmp(line, "ra\n", 3))
		ra(stack_a);
	else if (!ft_strncmp(line, "rb\n", 3))
		rb(stack_b);
	else if (!ft_strncmp(line, "rr\n", 3))
		rr(stack_a, stack_b);
	else if (!ft_strncmp(line, "rra\n", 4))
		rra(stack_a);
	else if (!ft_strncmp(line, "rrb\n", 4))
		rrb(stack_b);
	else if (!ft_strncmp(line, "rrr\n", 4))
		rrr(stack_a, stack_b);
	else
		safe_exit(stack_a, stack_b, line);
}

static	void	safe_exit(t_node **stack_a, t_node **stack_b, char *line)
{
	free(line);
	get_next_line(-1);
	free_list(stack_a);
	free_list(stack_b);
	error();
}
