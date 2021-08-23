#ifndef UTILS_H
# define UTILS_H

#include <unistd.h>

size_t		ft_strlen(const char *s);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(const char *s, int fd);
void	ft_putnbr_fd(int nb, int fd);
int	ft_atoi(const char *nptr);

#endif
