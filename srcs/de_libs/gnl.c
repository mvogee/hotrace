/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 22:24:47 by mvogee            #+#    #+#             */
/*   Updated: 2017/01/12 17:45:26 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"
#include "../../includes/hotrace.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

static int		search(int const fd, char *buff, char *string[fd])
{
	char		*join;
	char		*p;
	int			i;

	while (!(SL) && (i = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[i] = '\0';
		join = string[fd];
		string[fd] = hr_strjoin(join, buff);
		hr_strdel(&join);
	}
	if (i == 0 && !hr_strlen(string[fd]))
		return (0);
	if (i == -1)
		return (-1);
	return (1);
}

int				gnl(int const fd, char **line)
{
	static char	*string[1025];
	int			i;
	char		buff[BUFF_SIZE + 1];

	if (!line || fd < 0 || read(fd, buff, 0) < 0)
		return (-1);
	if (!string[fd])
		string[fd] = hr_strdup("");
	if ((i = search(fd, buff, &*string)) == -1)
		return (-1);
	*line = string[fd];
	if (hr_strchr(string[fd], '\n'))
		*line = hr_strsub(string[fd], 0, S - string[fd]);
	else
		*line = hr_strdup(string[fd]);
	(S ? string[fd] = hr_strdup(S + 1) : hr_strdel(&string[fd]));
	if (i == 0)
	{
		string[fd] = NULL;
		return (0);
	}
	return (1);
}
