
#include "../includes/hotrace.h"

int		hr_abs(int x)
{
	return (x < 0 ? x * -1 : x);
}

int		sax_hash(char *key)
{
	int hash;

	hash = 0;
	while (*key)
	{
		hash ^= (hash << 5) + (hash >> 2) + *key;
		key++;
	}
	return (hr_abs(hash % MAPSIZE));
}
