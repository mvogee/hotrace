
#include "../includes/hotrace.h"

int		sax_hash(char *key) // takes a key string and returns the hashed int for the key
{
	int hash;

	hash = 0;
	while (*key)
	{
		hash ^= (hash << 5) + (hash >> 2) + *key;
		key++;
	}
	return (hash % MAPSIZE);
}
