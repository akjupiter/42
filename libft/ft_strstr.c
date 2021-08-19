/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajupiter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 23:12:04 by ajupiter          #+#    #+#             */
/*   Updated: 2018/01/29 23:26:05 by ajupiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	int		z;
	int		len_needle;

	i = 0;
	z = 0;
	len_needle = ft_strlen(needle);
	if (!len_needle && haystack)
		return ((char *)haystack);
	else if (!len_needle && !ft_strlen(haystack))
		return ("\0");
	while (haystack[i])
	{
		while (needle[z] == haystack[i + z])
		{
			if (z == len_needle - 1)
				return ((char *)&haystack[i]);
			z++;
		}
		z = 0;
		i++;
	}
	return (NULL);
}
