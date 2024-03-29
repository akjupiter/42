/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajupiter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 19:37:39 by ajupiter          #+#    #+#             */
/*   Updated: 2019/11/16 19:37:43 by ajupiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static int	get_start(const char *s, const char *set)
{
	int		i;

	i = 0;
	while (s[i] && ft_strchr(set, s[i]))
		i++;
	return (i);
}

static int	get_end(const char *s, const char *set)
{
	int		i;

	i = ft_strlen(s) - 1;
	while (s[i] && ft_strchr(set, s[i]))
		i--;
	return (i);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*str;

	if (!s1)
		return ((char*)s1);
	if ((start = get_start(s1, set)) == ft_strlen(s1))
	{
		if (!(str = ft_calloc(1, sizeof(char))))
			return (NULL);
		return (str);
	}
	end = get_end(s1, set);
	if (!(str = ft_calloc(end - start + 2, sizeof(char))))
		return (NULL);
	s1 += start;
	i = 0;
	while (i <= end - start)
	{
		str[i] = *(s1 + i);
		i++;
	}
	str[i] = '\0';
	return (str);
}
