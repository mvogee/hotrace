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

t_bucket *init_entry(char *key, char *value)
{
	t_bucket *entry;

	entry = (t_bucket*)malloc(sizeof(t_bucket));
	if (!entry)
		return (NULL);
	entry->key = key;
	entry->value = value;
	entry->next = NULL;
	return (entry);
}

char	*read_key(void)
{
	//read from stdin until a newline is hit.
	char	*buf;
	size_t	bsread;

	bsread = read(0, buf, 1);

}

void	create_map(t_bucket *map[]) // t_bucket* map[] makes more sense. its a bucket pointer array.
{
	t_bucket	*entry;
	char		*key;
	char		*value;
	int			hashval;

	while (1)
	{
		key = read_key(); // make me
		if (!key)
			break ;
		value = read_value(); // make me
		if (!key || !value)
			break ;
		hashval = sax_hash(key); // make me
		entry = init_entry(key, value);
		add_entry_to_map() //make me
	}
}
