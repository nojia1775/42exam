#include <unistd.h>

void	print_hex(int nbr)
{
	if (nbr > 15)
		print_hex(nbr / 16);
	write(1, &"0123456789abcdef"[nbr % 16], 1);
}
int	ft_atoi(char *str)
{
	int i = 0;
	int nbr = 0;

	while(str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	return(nbr);

}

int main(int ac, char **av)
{
	if(ac == 2)
		print_hex(ft_atoi(av[1]));
	write(1, "\n", 1);
}