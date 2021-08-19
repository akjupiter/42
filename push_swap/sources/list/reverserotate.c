/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverserotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajupiter <ajupiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 16:54:01 by ajupiter          #+#    #+#             */
/*   Updated: 2021/08/13 16:54:05 by ajupiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	rra(t_stack *number)
{
	t_integer	*last;
	t_integer	*temp;

	if (!number->a || !number->a->next)
		return ;
	last = number->a;
	while (last->next && last->next->next)
		last = last->next;
	temp = last->next;
	last->next = 0;
	temp->next = number->a;
	number->a = temp;
}

void	rrb(t_stack *number)
{
	t_integer	*last;
	t_integer	*temp;

	if (!number->b || !number->b->next)
		return ;
	last = number->b;
	while (last->next && last->next->next)
		last = last->next;
	temp = last->next;
	last->next = 0;
	temp->next = number->b;
	number->b = temp;
}

void	rrr(t_stack *number)
{
	rra(number);
	rrb(number);
}
