#include "../minitalk.h"

void sighandler(int pid, char *message)
{
    char character;
    int num_bit;
    unsigned int i;

    i = 0;
    while(i < ft_strlen(message) + 1)
    {
        character = message[i];
        num_bit = 7;
        while (num_bit-- >= 0)
        {
            if(character % 2 != 0)
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);
            character /= 2;
            usleep(100);
        }
	      i++;
    }
}

int main (int argc, char **argv)
{
	if (argc == 3)
    sighandler(ft_atoi(argv[1]), argv[2]);
  else
    exit(EXIT_FAILURE);
  return (0);
}
