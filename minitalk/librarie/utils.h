#ifndef UTILS_H
# define UTILS_H

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

size_t		ft_strlen(const char *s);
void	ft_putstr_fd(const char *s, int fd);
void	exit_program(char *message);

#endif
