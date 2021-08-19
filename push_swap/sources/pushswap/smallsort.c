/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajupiter <ajupiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 18:11:22 by ajupiter          #+#    #+#             */
/*   Updated: 2021/08/16 17:48:34 by ajupiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	detect_min(t_integer *stack, int len)
{
	int	min;
	int	pos_min;
	int	i;

	min = stack->value;
	pos_min = 0;
	i = 1;
	while (i < len)
	{
		if (min > stack->next->value)
		{
			min = stack->next->value;
			pos_min = i;
		}
		stack = stack->next;
		i++;
	}
	return (pos_min);
}

static int	detect_max(t_integer *stack, int len)
{
	int	max;
	int	pos_max;
	int	i;

	max = stack->value;
	pos_max = 0;
	i = 1;
	while (i < len)
	{
		if (max < stack->next->value)
		{
			max = stack->next->value;
			pos_max = i;
		}
		stack = stack->next;
		i++;
	}
	return (pos_max);
}

static void	execute_instruction(int number, t_stack *stacks)
{
	if (number == 0)
	{
		pb(stacks);
		ft_putstr_fd("pb\n", 1);
	}
	else if (number == 1)
	{
		sa(stacks);
		ft_putstr_fd("sa\n", 1);
	}
	else if (number == 2)
	{
		ra(stacks);
		ft_putstr_fd("ra\n", 1);
	}
	else if (number == 3)
	{
		rra(stacks);
		ft_putstr_fd("rra\n", 1);
	}
	else if (number == 4)
	{
		pa(stacks);
		ft_putstr_fd("pa\n", 1);
	}
}

void	smallsort(t_stack *stacks)
{
	int	pos_min;
	int	len;

	while (!is_sorted(stacks->a))
	{
		len = stacklen(stacks->a);
		pos_min = detect_min(stacks->a, len);
		if (pos_min == 0)
			execute_instruction(0, stacks);
		else if (stacks->a->value > stacks->a->next->value)
			execute_instruction(1, stacks);
		else if ((pos_min > 0 && pos_min <= (len / 2) && (len % 2) != 0)
			|| (pos_min > 0 && pos_min < (len / 2) && (len % 2) == 0))
			execute_instruction(2, stacks);
		else if ((pos_min > (len / 2) && (len % 2) != 0)
			|| (pos_min >= (len / 2) && (len % 2) == 0))
			execute_instruction(3, stacks);
	}
	while (stacks->b)
		execute_instruction(4, stacks);
}

void	very_smallsort(t_stack *stacks)
{
	int	pos_max;
	int	len;

	while (!is_sorted(stacks->a))
	{
		len = stacklen(stacks->a);
		pos_max = detect_max(stacks->a, len);
		if (pos_max == 0)
			execute_instruction(2, stacks);
		else if (pos_max == 1)
			execute_instruction(3, stacks);
		if (stacks->a->value > stacks->a->next->value)
			execute_instruction(1, stacks);
	}
}
