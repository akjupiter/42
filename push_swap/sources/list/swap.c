/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajupiter <ajupiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 16:54:53 by ajupiter          #+#    #+#             */
/*   Updated: 2021/08/13 16:54:58 by ajupiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	sa(t_stack *number)
{
	t_integer	*temp;

	if (!number->a || !number->a->next)
		return ;
	temp = number->a->next;
	number->a->next = number->a->next->next;
	temp->next = number->a;
	number->a = temp;
}

void	sb(t_stack *number)
{
	t_integer	*temp;

	if (!number->b || !number->b->next)
		return ;
	temp = number->b->next;
	number->b->next = number->b->next->next;
	temp->next = number->b;
	number->b = temp;
}

void	ss(t_stack *number)
{
	sa(number);
	sb(number);
}
