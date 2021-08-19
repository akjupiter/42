/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajupiter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 19:36:54 by ajupiter          #+#    #+#             */
/*   Updated: 2019/11/16 19:36:59 by ajupiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && ((const unsigned char*)s)[i] != (unsigned char)c)
		i++;
	if (i < n && ((const unsigned char*)s)[i] == (unsigned char)c)
		return ((void*)s + i);
	else
		return (NULL);
}
