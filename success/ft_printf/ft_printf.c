#include <unistd.h>
#include <stdarg.h>

void ft_putstr(char *str, int *len)
{
	int i = 0;
	if(!str)
		str = "(null)";
	while(str[i])
	{
		*len += write(1, &str[i], 1);
		i++;
	}
}

void ft_putnbr(long long int nb, int *len)
{
	if(nb < 0)
	{
		*len += write(1, "-", 1);
		nb = nb * -1;
	}
	if(nb > 9)
		ft_putnbr(nb / 10, len);
	*len += write(1,&"0123456789"[nb % 10], 1);
}

void ft_put_hexa(long long int nb, int *len)
{
	if(nb > 15)
		ft_put_hexa(nb / 16, len);
	*len += write(1,&"0123456789abcdef"[nb % 16], 1);
}

int ft_printf(char *str, ...)
{
	int i = 0;
	int len = 0;
	va_list args;

	va_start(args, str);
	while(str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if(str[i] == 's')
			ft_putstr(va_arg(args, char *), &len);
			if(str[i] == 'd')
				ft_putnbr((long long int)va_arg(args, int), &len);
			if(str[i] == 'x')
				ft_put_hexa((long long int)va_arg(args, unsigned int), &len);
		}
		else
			len += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return(len);
}