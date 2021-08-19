/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajupiter <ajupiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 16:59:18 by ajupiter          #+#    #+#             */
/*   Updated: 2021/08/18 02:01:26 by ajupiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../../libraries/libft.h"
# include "../list/list.h"
# include <limits.h>

char	**init_variables(int argc, char **argv, t_stack *stacks, int *i);
void	parse(char **argv, int nb_value);
void	exit_program(char *message);

#endif
