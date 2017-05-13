#ifndef HOTRACE_H
# define HOTRACE_H

#define MAPSIZE 10

typedef struct s_bucket
{
	struct s_bucket	*next;
	char 			*key;
	char			*value;
}				t_bucket;

int		sax_hash(char *key);

#endif
