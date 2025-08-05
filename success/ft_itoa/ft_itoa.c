#include <stdio.h>
#include <stdlib.h>

int	ft_len(int n)
{
	long int	nbr;
	int			i;

	nbr = (long int)n;
	i = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr = nbr * -1;
		i++;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			i;
	long int	nbr;
	
	nbr = (long int)n;
	i = ft_len(nbr);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	if (nbr == 0)
		str[0] = '0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = nbr * -1;
	}
	str[i] = '\0';
	while (nbr > 0)
	{
		i--;
		str[i] = (nbr % 10) + 48;
		nbr = nbr / 10;
	}
	return (str);
}
int	main()
{
	printf("%s", ft_itoa(-2147483648));
}