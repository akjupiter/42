/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajupiter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 22:40:23 by ajupiter          #+#    #+#             */
/*   Updated: 2018/02/02 01:53:53 by ajupiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int	temp;
	int				size;
	char			tiret;
	char			caractere;

	tiret = '-';
	size = 1;
	if (nb < 0)
	{
		write(fd, &tiret, 1);
		nb = -nb;
	}
	temp = nb;
	while ((temp /= 10) > 0)
		size *= 10;
	temp = nb;
	while (size)
	{
		caractere = (temp / size) + 48;
		write(fd, &caractere, 1);
		temp %= size;
		size /= 10;
	}
}
