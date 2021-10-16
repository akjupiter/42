/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajupiter <ajupiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 04:37:25 by ajupiter          #+#    #+#             */
/*   Updated: 2021/08/24 04:44:28 by ajupiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static void	sighandler(int pid, char *message)
{
	char	character;
	int		num_bit;
	int		i;

	i = 0;
	while (i < (int)ft_strlen(message) + 1)
	{
		character = message[i];
		num_bit = 7;
		while (num_bit-- >= 0)
		{
			if (character % 2 != 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			character /= 2;
			usleep(250);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		sighandler(ft_atoi(argv[1]), argv[2]);
	else
		exit(EXIT_FAILURE);
	return (0);
}
