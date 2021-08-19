/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajupiter <ajupiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 16:45:26 by ajupiter          #+#    #+#             */
/*   Updated: 2021/08/18 00:59:22 by ajupiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include "../../libraries/libft.h"
# include <stdlib.h>

typedef struct s_integer	t_integer;
typedef struct s_str		t_str;

struct					s_integer
{
	int			value;
	t_integer	*next;
};

typedef struct s_stack
{
	t_integer	*a;
	t_integer	*b;
}						t_stack;

void		init_stacks(t_stack *stacks);
t_integer	*add_int_value(t_integer *t_it, int value);
t_str		*add_str_value(t_str *t_s, char *str);
int			is_sorted(t_integer *t_int);
int			stacklen(t_integer *stack);
void		free_stack(t_stack *stacks);
void		pa(t_stack *stack);
void		pb(t_stack *stack);
void		rra(t_stack *stack);
void		rrb(t_stack *stack);
void		rrr(t_stack *stack);
void		ra(t_stack *stack);
void		rb(t_stack *stack);
void		rr(t_stack *stack);
void		sa(t_stack *stack);
void		sb(t_stack *stack);
void		ss(t_stack *stack);

#endif
