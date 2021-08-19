/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_ft_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajupiter <ajupiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 04:07:12 by ajupiter          #+#    #+#             */
/*   Updated: 2021/08/17 08:36:21 by ajupiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_chars(const char *s, char c)
{
	int		total;

	total = 0;
	while (*s && *s == c)
		s++;
	while (*s && *s++ != c)
		total++;
	return (total);
}

int	count_words(const char *s, char c)
{
	int		i;
	int		total;
	int		mot;

	i = 0;
	total = 0;
	mot = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && mot == 0)
		{
			mot = 1;
			total++;
		}
		else if (s[i] == c && mot == 1)
			mot = 0;
		i++;
	}
	return (total);
}

char	**free_tab2d(char **tab, int len)
{
	int		i;

	i = 0;
	while (i < len + 1)
		free(tab[i++]);
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c, int nb_words)
{
	int		i;
	int		j;
	char	**tab_split;
	int		r;

	i = 1;
	if (!s)
		return (NULL);
	r = !(tab_split = ft_calloc(nb_words + 2, sizeof(char *)));
	if (r)
		return (NULL);
	while (i < nb_words + 1)
	{
		j = 0;
		while (*s && *s == c)
			s++;
		r = !(tab_split[i] = ft_calloc(count_chars(s, c) + 1, sizeof(char)));
		if (r)
			return (free_tab2d(tab_split, nb_words));
		while (*s && *s != c)
			tab_split[i][j++] = *s++;
		tab_split[i++][j] = '\0';
	}
	tab_split[i] = NULL;
	return (tab_split);
}
