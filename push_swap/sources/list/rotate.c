/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajupiter <ajupiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 16:51:06 by ajupiter          #+#    #+#             */
/*   Updated: 2021/08/13 16:52:03 by ajupiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ra(t_stack *number)
{
	t_integer	*temp;
	t_integer	*last;

	if (!number->a)
		return ;
	temp = number->a;
	number->a = number->a->next;
	temp->next = 0;
	if (number->a)
	{
		last = number->a;
		while (last->next)
			last = last->next;
		last->next = temp;
	}
	else
		number->a = temp;
}

void	rb(t_stack *number)
{
	t_integer	*temp;
	t_integer	*last;

	if (!number->b)
		return ;
	temp = number->b;
	number->b = number->b->next;
	temp->next = 0;
	if (number->b)
	{
		last = number->b;
		while (last && last->next)
			last = last->next;
		last->next = temp;
	}
	else
		number->b = temp;
}

void	rr(t_stack *number)
{
	ra(number);
	rb(number);
}
