/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajupiter <ajupiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 18:10:36 by ajupiter          #+#    #+#             */
/*   Updated: 2021/08/16 02:34:23 by ajupiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "../../libraries/libft.h"
# include "../list/list.h"
# include "../parser/parser.h"

void	ft_heapsort(int *arr, int n);
void	very_smallsort(t_stack *stacks);
void	smallsort(t_stack *stacks);
void	bigsort(t_stack *stack);

#endif
