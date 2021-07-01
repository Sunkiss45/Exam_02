/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 14:36:19 by ebarguil          #+#    #+#             */
/*   Updated: 2021/07/01 10:14:41 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_rec(char **line, int index, int fd)
{
	char	buf;
	int		x;

	x = read(fd, &buf, 1);
	if (x == 1 && buf != '\n')
	{
		x = gnl_rec(line, index + 1, fd);
		if (x != -1)
			(*line)[index] = buf;
	}
	else if (x != -1)
	{
		*line = (char *)malloc(sizeof(char) * (index + 1));
		if (*line != NULL)
			(*line)[index] = '\0';
		else
			x = -1;
	}
	return (x);
}

int	get_next_line(char **line)
{
	return (gnl_rec(line, 0, 0));
}
