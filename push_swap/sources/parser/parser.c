/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajupiter <ajupiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 16:56:44 by ajupiter          #+#    #+#             */
/*   Updated: 2021/08/18 02:01:06 by ajupiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	exit_program(char *message)
{
	ft_putstr_fd(message, 2);
	exit(EXIT_FAILURE);
}

static void	ft_is_number(char **argv, int len, char *str)
{
	size_t		i;
	long long	value;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') && ft_strlen(str) >= 2)
		i++;
	while (i < ft_strlen(str))
	{
		if (!ft_isdigit(str[i++]))
		{
			if (!argv[0])
				free_tab2d(argv, len + 1);
			exit_program("Error\n");
		}
	}
	value = ft_atoll(str);
	if (value < INT_MIN || value > INT_MAX)
	{
		if (!argv[0])
			free_tab2d(argv, len + 1);
		exit_program("Error\n");
	}
}

static void	ft_is_duplicated(int *array, int value, int pos_value, int nb_value)
{
	int	i;

	i = pos_value;
	while (i < nb_value - 1)
	{
		if (value == array[i + 1])
		{
			free(array);
			exit_program("Error\n");
		}
		i++;
	}
}

char	**init_variables(int argc, char **argv, t_stack *stacks, int *i)
{
	stacks->a = NULL;
	stacks->b = NULL;
	*i = argc - 1;
	if (argc == 1)
		exit(EXIT_SUCCESS);
	if (argc == 2)
	{
		if (ft_strlen(argv[1]) == 0)
			exit_program("Error\n");
		if (ft_strlen(argv[1]) > 1)
		{
			*i = count_words(argv[1], ' ');
			argv = ft_split(argv[1], ' ', *i);
		}
	}
	return (argv);
}

void	parse(char **argv, int nb_value)
{
	int	i;
	int	j;
	int	*array;

	i = nb_value;
	while (i > 0)
	{
		if (ft_strlen(argv[i]) == 0)
			exit_program("Error\n");
		ft_is_number(argv, nb_value, argv[i--]);
	}
	array = (int *)malloc(nb_value * sizeof(int));
	if (!array)
		exit_program("malloc error\n");
	i = nb_value;
	j = 0;
	while (i > 0)
		array[j++] = ft_atoi(argv[i--]);
	j = 0;
	while (j < nb_value)
	{
		ft_is_duplicated(array, array[j], j, nb_value);
		j++;
	}
	free(array);
}
