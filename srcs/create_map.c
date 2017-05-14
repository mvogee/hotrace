#include "../includes/hotrace.h"
// todo
/*
 XX 1. create a hashing funciton and make sure it works. XX

 2. read our lines from the stdio
 3. fill hashmap (hard part); depending on our map size we might get a lot of collision unless we go dynamic and rehash with every entry which would be auful if you ask me. and slow
 4. make search
 5. optimze by making collision searches faster. possibly by doing a tree sort instead of linked list.
*/

char	*read_key(void)
{
	char *key;
	int len;

	key = NULL;
	len = gnl(0, &key);
	if (len <= 0 || !*key)
		return (NULL);
	return (key);
}

char	*read_value(void)
{
	char *value;
	int len;

	value = NULL;
	len = gnl(0, &value);
	if (len <= 0 || !*value)
		return (NULL);
	return (value);
}

t_bucket *init_entry(char *key, char *value)
{
	t_bucket *entry;

	entry = (t_bucket*)malloc(sizeof(t_bucket));
	entry->key = key;
	entry->value = value;
	entry->next = NULL;
	return (entry);
}

void	create_map(t_bucket *map[MAPSIZE]) // t_bucket* map[] makes more sense. its a bucket pointer array.
{
	t_bucket	*entry;
	char		*key;
	char		*value;
	int			hashval;

	while (1)
	{
		key = NULL;
		value = NULL;
		key = read_key();
		if (!key)
			break ;
		value = read_value(); // should we allow empty values? right now we break for either being \n
		if (!key || !value)
			break ;
		hashval = sax_hash(key);
		entry = init_entry(key, value);
		add_entry_to_map(entry, hashval, map);
	}
}
