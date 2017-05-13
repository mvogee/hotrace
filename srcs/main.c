
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

int main()
{
	t_bucket	*map[MAPSIZE]; // this is hour hashmap.
	create_map(map); // make me. create the hash map by reading from strdin; will be exited when an empty line is hit
	search_map(map); // make me. read search keys and print the value as the given key location.
	free_map(map); // make me. free all elements of the map
	printf("%d\n", sax_hash(argv[1]));
	// read in the input from the stdin.
	// empty line indicates the end of the input.
	// take the key and the next line which is its value in the key = value relationship
	// if there is not a value for the key is this an error?
	// hash the key and create a new node on the hashmap.
	// - need to decide how large of an array to create for the hash map.
	// - for starters just do basic linked list for collision and search the list for the key when retrieving.
	// - later on would be better to impliment some sort of sorting tree for the search as huge sets of data will have a lot of collisions
	// at this point we should have created a fully functional hashmap.

	// this is the easy part.
	// next inputs from the stdin are going to be the keyword searches.
	// take in the keyword and run it through the hashing funciton to get the index of its value
	// if the value does not exist display "keyword Not found."
	// otherwise make sure the keyword and the key match display the keyword. if they dont go through the list till they do.
	return (0);
}
