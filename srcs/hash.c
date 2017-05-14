/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 22:25:51 by mvogee            #+#    #+#             */
/*   Updated: 2016/03/14 22:27:09 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

static int	hr_abs(int x)
{
	return (x < 0 ? x * -1 : x);
}

int			sax_hash(char *key)
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
