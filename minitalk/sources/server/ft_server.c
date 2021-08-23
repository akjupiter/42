#include "../minitalk.h"

int num_bit = 0;
char character = 0;

static int ft_power(int n, int p)
{
	if (p == 0)
		return (1);
	else
		return (ft_power(n, p - 1) * n);
}

static void sighandler(int signum)
{
    if(signum == SIGUSR1)
      character += ft_power(2, num_bit++);
    else
      num_bit++;
    if (num_bit > 7)
    {
        ft_putchar_fd(character, 1);
        if (!character)
          ft_putchar_fd('\n', 1);
        num_bit = 0;
        character = 0;
    }
}

int main ()
{
    struct sigaction sigactionhandler;

    sigactionhandler.sa_handler = sighandler;
    ft_putstr_fd("Server pid: ", 1);
    ft_putnbr_fd(getpid(), 1);
    ft_putstr_fd("\n\n", 1);
    while (1)
    {
        sigaction(SIGUSR1, &sigactionhandler, NULL);
        sigaction(SIGUSR2, &sigactionhandler, NULL);
        pause();
    }
    return (0);
}
