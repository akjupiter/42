/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajupiter <ajupiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 05:00:26 by ajupiter          #+#    #+#             */
/*   Updated: 2021/08/24 05:00:32 by ajupiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10240
# endif

# include "../librarie/utils.h"
# include <signal.h>
# include <stdlib.h>

typedef struct s_line
{
	int		num_bit;
	int		c;
	int		indice_c;
	char	buf[BUFFER_SIZE];
}		t_line;

#endif
