#include "../includes/hotrace.h"
#include <stdio.h>
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
	//read from stdin until a newline is hit.
	char *key;
	int len;

	key = NULL;
	len = gnl(0, &key);
	if (len <= 0)
		return (NULL);
	return (key);

}

char	*read_value(void)
{
	char *value;
	int len;

	value = NULL;
	len = gnl(0, &value);
	if (value <= 0)
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

void	create_map(t_bucket **map[]) // t_bucket* map[] makes more sense. its a bucket pointer array.
{
	t_bucket	*entry;
	char		*key;
	char		*value;
	int			hashval;

	while (1)
	{
		key = read_key();
		if (!key)
			break ;
		value = read_value();
		if (!key || !value)
			break ;
		hashval = sax_hash(key);
		printf("%d\n", hashval);
		entry = init_entry(key, value);
		printf("%s\n", entry->key);
		add_entry_to_map(entry, hashval, map);
		printf("%s\n", ((*map)[hashval])->value);
	}
}
