/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajupiter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:00:34 by ajupiter          #+#    #+#             */
/*   Updated: 2021/08/14 02:42:06 by ajupiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strcchr(char *src, int c)
{
	while (*src)
		if (*src++ == c)
			return (1);
	return (0);
}

size_t	ft_nstrlen(char *src, int c)
{
	size_t	len;

	len = 0;
	while (src[len] && src[len] != c)
		len++;
	return (len);
}

char	*ft_strconcat(char **dst, char *str)
{
	char	*res;
	size_t	index;
	size_t	len;
	int		r;

	r = !(res = malloc(ft_nstrlen(*dst, 0) + ft_nstrlen(str, 0) + 1));
	if (r)
		return (NULL);
	len = 0;
	while ((*dst)[len])
	{
		res[len] = (*dst)[len];
		len++;
	}
	index = 0;
	while (str[index])
	{
		res[index + len] = str[index];
		index++;
	}
	res[index + len] = 0;
	free(*dst);
	*dst = res;
	return (res);
}

char	*ft_getline(char *src, int c)
{
	char	*res;
	size_t	len;
	int		r;

	len = ft_nstrlen(src, c);
	r = !(res = malloc(len + 1));
	if (r)
		return (NULL);
	res[len] = 0;
	while (len--)
		res[len] = src[len];
	return (res);
}

char	*ft_chrmove(char **dst, int c)
{
	char	*res;
	size_t	index;
	size_t	len;
	int		r;

	index = ft_nstrlen(*dst, c);
	r = !(res = malloc(ft_nstrlen(*dst, 0) - index + 1));
	if (r)
		return (NULL);
	len = ft_nstrlen(*dst, 0) - index;
	res[len] = 0;
	while (len--)
		res[len] = (*dst)[index + 1 + len];
	free(*dst);
	*dst = res;
	return (res);
}
