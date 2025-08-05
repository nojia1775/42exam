#include <unistd.h>

void	repeat_alpha(char c, int i)
{
	while(i > 0)
	{
		write(1, &c, 1);
		i--;
	}
}

int main(int ac, char **av)
{
	int i = 0;
	if (ac == 2)
	{
		while (av[1][i])
		{
			if(av[1][i] >= 'a' && av[1][i] <= 'z')
				repeat_alpha(av[1][i], (av[1][i] + 1 - 'a'));
			else if(av[1][i] >= 'A' && av[1][i] <= 'Z')
				repeat_alpha(av[1][i], (av[1][i] + 1 - 'A'));
			else
				write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}