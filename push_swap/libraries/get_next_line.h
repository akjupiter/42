/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajupiter <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 18:02:57 by ajupiter          #+#    #+#             */
/*   Updated: 2020/03/05 19:01:38 by ajupiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

int		ft_strcchr(char *src, int c);
size_t	ft_nstrlen(char *src, int c);
char	*ft_strconcat(char **dst, char *str);
char	*ft_getline(char *src, int c);
char	*ft_chrmove(char **dst, int c);
int		get_next_line(int fd, char **line);

#endif
