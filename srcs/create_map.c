/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 22:25:51 by mvogee            #+#    #+#             */
/*   Updated: 2016/03/14 22:27:09 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

char		*read_key(void)
{
	char	*key;
	int		len;

	key = NULL;
	len = gnl(0, &key);
	if (len <= 0 || !*key)
		return (NULL);
	return (key);
}

static char	*read_value(void)
{
	char	*value;
	int		len;

	value = NULL;
	len = gnl(0, &value);
	if (len <= 0 || !*value)
		return (NULL);
	return (value);
}

t_bucket	*init_entry(char *key, char *value)
{
	t_bucket *entry;

	entry = (t_bucket*)malloc(sizeof(t_bucket));
	entry->key = key;
	entry->value = value;
	entry->next = NULL;
	return (entry);
}

void		create_map(t_bucket *map[MAPSIZE])
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
		value = read_value();
		if (!key || !value)
			break ;
		hashval = sax_hash(key);
		entry = init_entry(key, value);
		add_entry_to_map(entry, hashval, map);
	}
}
