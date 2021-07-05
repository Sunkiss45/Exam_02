/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 15:54:17 by ebarguil          #+#    #+#             */
/*   Updated: 2021/07/05 16:20:39 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		x;

	printf("\n");
	while ((x = get_next_line(&line)) > 0)
	{
		printf("%s\n", line);
		free (line);
		line = NULL;
	}
	return (0);
}
