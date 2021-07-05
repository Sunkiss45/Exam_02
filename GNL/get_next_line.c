/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 14:36:19 by ebarguil          #+#    #+#             */
/*   Updated: 2021/07/05 10:39:20 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_rec(char **line, int i, int fd)
{
	char	buf;
	int		r;

	r = read(fd, &buf, 1);
	if (r == 1 && buf != '\n')
	{
		r = gnl_rec(line, i + 1, fd);
		if (r != -1)
			(*line)[i] = buf;
	}
	else if (r != -1)
	{
		*line = (char *)malloc(sizeof(char) * (i + 1));
		if (*line != NULL)
			(*line)[i] = '\0';
		else
			r = -1;
	}
	return (r);
}

int	get_next_line(char **line)
{
	return (gnl_rec(line, 0, 0));
}
