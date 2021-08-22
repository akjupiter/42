#include "utils.h"


size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr_fd(const char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

void	exit_error(char *message)
{
	ft_putstr_fd(message, 2);
	exit(EXIT_FAILURE);
}
