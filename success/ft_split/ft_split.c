#include <stdlib.h>

char    **ft_split(char *str)
{
	int i = 0;
	int j = 0;
	int k = 0;
	char **tab;

	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
	tab = malloc(sizeof(char *) * 1000);
	if(!tab)
		return(NULL);
	while (str[i])
	{
		if (str[i] > 32)
		{
			tab[j] = malloc(sizeof(char) * 1000);
			if(!tab[j])
				return(NULL);
			while (str[i] && str[i] > 32)
				tab[j][k++] = str[i++];
			tab[j][k] = '\0';
			k = 0;
			j++;
		}
		else
			i++;
	}
	tab[j] = 0;
	return(tab);
}
// #include <stdio.h>
// int main()
// {
// 	char **str;

// 	str = ft_split("hello c ahlem");
// 	printf("%s", str[2]);
// 	for(int i = 0; str[i]; i++)
// 		free(str[i]);
// 	free(str);
// }