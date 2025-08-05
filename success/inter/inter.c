#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	int j;
	int l;

	i = 0;
	l = 0;
	if (ac == 3)
	{
		while (av[1][i] != '\0')
		{
			j = 0;
			while (av[2][j] != '\0')
			{
				if(av[1][i] == av[2][j])
				{ 
					l = 0;
					while (av[1][l] != av[1][i])
						l++;
					if (l == i)
					{
						l = 0;
						while (av[2][l] != av[2][j])
							l++;
						if (l == j)
							write(1, &av[1][i], 1);
					}
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
}