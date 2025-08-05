
int		max(int* tab, unsigned int len)
{
	int i = 0;
	int max = tab[0];
	while(len > i)
	{
		if(tab[i] > max)
		{
			max = tab[i];
		}
		i++;
	}
	return(max);
}