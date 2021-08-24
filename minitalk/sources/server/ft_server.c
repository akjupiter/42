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

int		g_num_bit = 0;
char	g_character = 0;

static int	ft_power(int n, int p)
{
	if (p == 0)
		return (1);
	else
		return (ft_power(n, p - 1) * n);
}

static void	sighandler(int signum)
{
	if (signum == SIGUSR1)
		g_character += ft_power(2, g_num_bit++);
	else
		g_num_bit++;
	if (g_num_bit > 7)
	{
		ft_putchar_fd(g_character, 1);
		if (!g_character)
			ft_putchar_fd('\n', 1);
		g_num_bit = 0;
		g_character = 0;
	}
}

int	main(void)
{
	struct sigaction	sigactionhandler;

	sigactionhandler.sa_handler = sighandler;
	ft_putstr_fd("Server pid: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n\n", 1);
	while (1)
	{
		sigaction(SIGUSR1, &sigactionhandler, NULL);
		sigaction(SIGUSR2, &sigactionhandler, NULL);
		pause();
	}
	return (0);
}
