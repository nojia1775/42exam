int	ft_atoi_base(const char *str, int str_base)
{
	int i = 0;
	int sign = 1;
	int res = 0;

	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i])
	{
		if(str[i] >= '0' && str[i] <= '9')
			res = res * str_base + str[i] - '0';
		else if (str[i] >= 'A' && str[i] <= 'F')
			res = res * str_base + str[i] - 55;
		else if (str[i] >= 'a' && str[i] <= 'f')
			res = res * str_base + str[i] - 87;
		else
			break;
		i++;
	}
	return(sign * res);
}