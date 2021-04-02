/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 16:48:18 by ebarguil          #+#    #+#             */
/*   Updated: 2021/04/02 17:19:58 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
		write(1, &buf[i++], 1);
	write(1, "\n", 1);
}

int		ft_strchr(char *buf, char c)
{
	int	i;

	i = 0;
	while (buf[i])
		if (buf[i++] == c)
			return (1);
	return (0);
}

int		main(int ac, char **av)
{
	char	buf[16384];
	char	*s[2];
	int		i[2];

	if (ac != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	s[0] = av[1];
	s[1] = av[2];
	buf[0] = '\0';
	i[0] = 0;
	i[1] = 0;
	while (s[0] && s[0][i[1]])
		if (ft_strchr(buf, s[0][i[1]++]) == 0)
			buf[i[0]++] = s[0][i[1] - 1];
	i[1] = 0;
	while (s[1] && s[1][i[1]])
		if (ft_strchr(buf, s[1][i[1]++]) == 0)
			buf[i[0]++] = s[1][i[1] - 1];
	buf[i[0]] = '\0';
	ft_putstr(buf);
	return (0);
}
