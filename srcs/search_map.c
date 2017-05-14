
#include "../includes/hotrace.h"

int		hr_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

void 	not_found(char *key)
{
	write(1, key, hr_strlen(key));
	write(1, ": Not found.\n", 13);
}

void	find_value(t_bucket *tmp, char *key)
{
	while (tmp)
	{
		if (hr_strcmp(tmp->key, key))
		{
			write(1, tmp->value, hr_strlen(tmp->value));
			write(1, "\n", 1);
			break ;
		}
		tmp = tmp->next;
		if (!tmp)
			not_found(key);
	}
}

void	search_map(t_bucket *map[MAPSIZE])
{
	char		*key;
	int			hash;
	t_bucket	*tmp;

	while (1)
	{
		key = read_key();
		if (!key)
			break ;
		hash = sax_hash(key);
		if (!(map[hash]))
			not_found(key);
		else
		{
			tmp = map[hash];
			find_value(tmp, key);
			free(key);
		}
	}
}
