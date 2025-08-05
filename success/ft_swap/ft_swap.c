#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
// int main()
// {
	
// 	int a = 5;
// 	int b = 45;
// 	ft_swap(&a, &b);

// 	printf("a = %d et b = %d\n", a, b);
// }