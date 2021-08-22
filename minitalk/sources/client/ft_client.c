#include "../../librarie/utils.h"

void sighandler(int pid, char *message)
{
    int index;
    int byte;
    int bit;
    
    index = 0;
    
    while(message[index] != '\0') //
    {
        byte = message[index];
        bit = 7;
        
        while (bit-- >= 0)
        {
                if(byte % 2 == 0)
                {
                    kill(pid, SIGUSR1);
                }
                else
                {
                    kill(pid, SIGUSR2);
                }
                         
                byte = byte / 2;
        }
	    
	index++;
    }
}

int main (int argc, char **argv)
{
	if (argc == 3)
    {
        sighandler(argc, argv[2]);
    }
	
    exit(EXIT_FAILURE);
}
