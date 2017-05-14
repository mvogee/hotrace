
#include "../includes/hotrace.h"

void	hr_bzero(t_bucket *map[MAPSIZE], int n)
{
 	int i;

	i = 0;
	while (i < n)
	{
		map[i] = NULL;
		i++;
	}
}

void	free_map(t_bucket *map[MAPSIZE])
{
	int			i;
	t_bucket	*tmp;
	t_bucket	*next;

	i = 0;
	while (i < MAPSIZE)
	{
		tmp = map[i];
		while (tmp)
		{
			next = tmp->next;
			free(tmp->key);
			free(tmp->value);
			tmp = next;
		}
		i++;
	}
}

int		main()
{
	t_bucket	*map[MAPSIZE];
	hr_bzero(map, MAPSIZE);
	create_map(map);
	search_map(map);
	free_map(map);
	return (0);
}
