/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_entry_to_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 22:25:51 by mvogee            #+#    #+#             */
/*   Updated: 2016/03/14 22:27:09 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

void	add_entry_to_map(t_bucket *entry, int hindex, t_bucket *map[])
{
	t_bucket *tmp;

	tmp = map[hindex];
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = entry;
	}
	else
		map[hindex] = entry;
}
