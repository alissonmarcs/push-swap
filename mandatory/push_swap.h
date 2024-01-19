/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarcos <almarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 08:58:24 by almarcos          #+#    #+#             */
/*   Updated: 2024/01/08 09:18:36 by almarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "../libft/libft.h"

# include <limits.h>

typedef struct s_node	t_node;
struct s_node
{
	int		number;
	int		index;
	int		position;
	int		target_position;
	int		cost_a;
	int		cost_b;
	t_node	*next;
};

t_node		*create_node(int number);
t_node		*get_last_node(t_node **head);
void		link_node(t_node **head, t_node *node);
void		free_list(t_node **head);
int			get_list_size(t_node *head);
void		check_args(int argc, char *argv[]);
void		fill_stack_a(t_node **head, char *argv[]);

/* push swap moviments */
void		sa(t_node **head_stack_a);
void		sb(t_node **head_stack_b);
void		ss(t_node **head_stack_a, t_node **head_stack_b);

void		pa(t_node **head_stack_a, t_node **head_stack_b);
void		pb(t_node **head_stack_a, t_node **head_stack_b);

void		rra(t_node **head_stack_a);
void		rrb(t_node **head_stack_b);
void		rrr(t_node **head_stack_a, t_node **head_stack_b);

void		ra(t_node **head_stack_a);
void		rb(t_node **head_stack_b);
void		rr(t_node **head_stack_a, t_node **head_stack_b);

#endif
