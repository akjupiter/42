/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajupiter <ajupiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 16:28:49 by ajupiter          #+#    #+#             */
/*   Updated: 2021/08/18 02:05:30 by ajupiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	check_instruction(t_stack *stack, char *line)
{
	if (!ft_strcmp(line, "sa"))
		sa(stack);
	else if (!ft_strcmp(line, "sb"))
		sb(stack);
	else if (!ft_strcmp(line, "ss"))
		ss(stack);
	else if (!ft_strcmp(line, "pa"))
		pa(stack);
	else if (!ft_strcmp(line, "pb"))
		pb(stack);
	else if (!ft_strcmp(line, "ra"))
		ra(stack);
	else if (!ft_strcmp(line, "rb"))
		rb(stack);
	else if (!ft_strcmp(line, "rr"))
		rr(stack);
	else if (!ft_strcmp(line, "rra"))
		rra(stack);
	else if (!ft_strcmp(line, "rrb"))
		rrb(stack);
	else if (!ft_strcmp(line, "rrr"))
		rrr(stack);
	else
		return (-1);
	return (0);
}

static void	ft_stdin(t_stack *stack)
{
	int		ret;
	char	*line;
	int		check;

	while (1)
	{
		ret = get_next_line(0, &line);
		if (ret > 0)
		{
			check = check_instruction(stack, line);
			free(line);
			if (check == -1)
				exit_program("Error\n");
		}
		if (ret <= 0)
		{
			free(line);
			break ;
		}
	}
}

static void	execute(char **argv, t_stack *stacks, int len)
{
	ft_stdin(stacks);
	if (!stacks->b && is_sorted(stacks->a))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	if (!argv[0])
		free_tab2d(argv, len);
	free_stack(stacks);
}

int	main(int argc, char **argv)
{
	t_stack	stacks;
	int		i;
	int		nb_value;

	argv = init_variables(argc, argv, &stacks, &nb_value);
	parse(argv, nb_value);
	i = nb_value;
	while (i > 0)
		stacks.a = add_int_value(stacks.a, ft_atoi(argv[i--]));
	execute(argv, &stacks, stacklen(stacks.a));
	return (0);
}
