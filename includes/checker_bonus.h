/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 08:58:24 by almarcos          #+#    #+#             */
/*   Updated: 2024/02/15 18:28:50 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H

# define CHECKER_BONUS_H

# include <libft.h>

# include <limits.h>

typedef struct s_node	t_node;
struct s_node
{
	long			number;
	t_node			*next;
};

t_node		*create_node(long number);
t_node		*get_last_node(t_node *head);
void		link_node(t_node **head, t_node *node);
void		free_list(t_node **head);

void		check_args(int argc, char *argv[]);
void		check_numbers(t_node **stack_a);
void		fill_stack_a(t_node **head, char *argv[]);
short		is_sort(t_node *head);
void		error(void);

void		sa(t_node **stack_a);
void		sb(t_node **stack_b);
void		rra(t_node **stack_a);
void		rrb(t_node **stack_b);
void		ra(t_node **stack_a);
void		rb(t_node **stack_b);
void		ss(t_node **stack_a, t_node **stack_b);
void		pa(t_node **stack_a, t_node **stack_b);
void		pb(t_node **stack_a, t_node **stack_b);
void		rrr(t_node **stack_a, t_node **stack_b);
void		rr(t_node **stack_a, t_node **stack_b);

#endif
