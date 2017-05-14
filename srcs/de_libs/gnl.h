/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvogee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 22:25:51 by mvogee            #+#    #+#             */
/*   Updated: 2016/12/19 22:27:09 by mvogee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 2048


# define SL p = hr_strchr(string[fd], '\n')
# define S hr_strchr(string[fd], '\n')
# include "../../includes/hotrace.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
#include <sys/types.h>


#endif
