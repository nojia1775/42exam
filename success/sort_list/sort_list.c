#include "list.h"

void	swap_value(t_list *a, t_list *b)
{
	int swap;
	
	swap = a->data;
	a->data = b->data;
	b->data = swap;
}

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int swapped = 1;
	t_list *tmp;

	tmp = lst;
	while (swapped == 1)
	{
		swapped = 0;
		while (tmp && tmp->next)
		{
			if (((*cmp)(tmp->data, tmp->next->data)) == 0)
			{
				swap_value(tmp, tmp->next);
				swapped = 1;
			}
			tmp = tmp->next;
		}
		tmp = lst;
	}
	return(lst);
}


