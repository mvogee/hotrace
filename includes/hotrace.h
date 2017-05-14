/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 22:25:51 by mvogee            #+#    #+#             */
/*   Updated: 2016/03/14 22:27:09 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

#define MAPSIZE 1024
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_bucket
{
	struct s_bucket	*next;
	char 			*key;
	char			*value;
}				t_bucket;

int		sax_hash(char *key);
void	create_map(t_bucket *map[MAPSIZE]);
void	add_entry_to_map(t_bucket *entry, int hindex, t_bucket *map[]);
char	*read_key(void);

void	search_map(t_bucket *map[MAPSIZE]);

int				gnl(int const fd, char **line);
unsigned long	hr_strlen(char *str);
char			*hr_strjoin(char const *s1, char const *s2);
void			hr_strdel(char **as);
char			*hr_strcpy(char *dst, const char *src);
char			*hr_strdup(const char *s1);
char			*hr_strsub(char const *s, unsigned int start, size_t len);
char			*hr_strchr(const char *s, int c);

#endif
