/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajupiter <ajupiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 04:55:44 by ajupiter          #+#    #+#             */
/*   Updated: 2021/08/24 05:01:15 by ajupiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

static int	ft_power(int n, int p)
{
	if (p == 0)
		return (1);
	else
		return (ft_power(n, p - 1) * n);
}

static void	sighandler(int signum)
{
	static t_line	line;

	if (line.num_bit != 0 && line.c != 0 && line.indice_c != 0 && !line.buf[0])
		line = (t_line){0, 0, 0, {}};
	if (signum == SIGUSR1)
		line.c += ft_power(2, line.num_bit++);
	else
		line.num_bit++;
	if (line.num_bit > 7)
	{
		line.buf[line.indice_c] = line.c;
		line.indice_c++;
		if (!line.c)
		{
			ft_putstr_fd(line.buf, 1);
			ft_putstr_fd("\n", 1);
			line.indice_c = 0;
			ft_memset(line.buf, 0, BUFFER_SIZE);
		}
		line.num_bit = 0;
		line.c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = sighandler;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putstr_fd("Server pid: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n\n", 1);
	while (1)
		pause();
	return (0);
}
