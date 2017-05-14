/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 22:25:51 by mvogee            #+#    #+#             */
/*   Updated: 2016/03/14 22:27:09 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

static void	hr_bzero(t_bucket *map[MAPSIZE], int n)
{
 	int			i;

	i = 0;
	while (i < n)
	{
		map[i] = NULL;
		i++;
	}
}

static void	free_map(t_bucket *map[MAPSIZE])
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

int			main(void)
{
	t_bucket	*map[MAPSIZE];
	hr_bzero(map, MAPSIZE);
	create_map(map);
	search_map(map);
	free_map(map);
	return (0);
}
