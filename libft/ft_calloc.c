/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajupiter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 19:36:26 by ajupiter          #+#    #+#             */
/*   Updated: 2019/11/24 18:09:29 by ajupiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void *tmp;

	tmp = malloc(nmemb * size);
	if (tmp == NULL)
		return (NULL);
	if (tmp)
		ft_bzero(tmp, nmemb * size);
	return (tmp);
}
