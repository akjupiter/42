/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajupiter <ajupiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 18:02:58 by ajupiter          #+#    #+#             */
/*   Updated: 2021/08/19 16:29:59 by ajupiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	copy2array(int *copy, int *array, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		copy[i] = array[i];
		i = i + 1;
	}
}

static void	simplifyarray(int *array, int len)
{
	int	i;
	int	j;
	int	*tmp_array;

	tmp_array = (int *)malloc(len * sizeof(int));
	copy2array(tmp_array, array, len);
	ft_heapsort(tmp_array, len);
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (array[i] == tmp_array[j])
			{
				array[i] = j;
				j = len;
			}
			j++;
		}
		i++;
	}
	free(tmp_array);
}

static void	copy2stack(int *array, t_integer *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->value = array[i++];
		stack = stack->next;
	}
}

static void	execute(t_stack *stacks, char **argv)
{
	int	len;

	len = stacklen(stacks->a);
	if (len == 3)
		very_smallsort(stacks);
	else if (len < 101)
		smallsort(stacks);
	else
		bigsort(stacks);
	if (!argv[0])
		free_tab2d(argv, len + 1);
	free_stack(stacks);
}

int	main(int argc, char **argv)
{
	t_stack	stacks;
	int		*array;
	int		i;
	int		nb_value;

	argv = init_variables(argc, argv, &stacks, &nb_value);
	parse(argv, nb_value);
	i = nb_value;
	while (i > 0)
		stacks.a = add_int_value(stacks.a, ft_atoi(argv[i--]));
	array = (int *)malloc(nb_value * sizeof(int));
	if (!array)
		exit_program("malloc error");
	i = nb_value;
	while (i > 0)
	{
		array[i - 1] = ft_atoi(argv[i]);
		i--;
	}
	simplifyarray(array, nb_value);
	copy2stack(array, stacks.a);
	free(array);
	execute(&stacks, argv);
	return (0);
}
