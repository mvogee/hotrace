
#include "../includes/hotrace.h"
#include <stdio.h>

void	add_entry_to_map(t_bucket *entry, int hindex, t_bucket *map[])
{
	t_bucket *tmp;

	tmp = map[hindex];
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = entry;
	}
	else
		map[hindex] = entry;
}
