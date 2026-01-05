/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgjoka <jgjoka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 12:11:12 by jgjoka            #+#    #+#             */
/*   Updated: 2025/11/14 18:10:23 by jgjoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

static void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		write(fd, s++, 1);
}

static int	hex_len(unsigned int v)
{
	int	len;

	if (v == 0)
		return (1);
	len = 0;
	while (v)
	{
		v /= 16;
		len++;
	}
	return (len);
}

static char	*make_hex_string(unsigned int v, int asc, int len)
{
	char	*str;

	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (--len >= 0)
	{
		if ((v % 16) < 10)
			str[len] = (v % 16) + '0';
		else
			str[len] = (v % 16) + asc;
		v /= 16;
	}
	return (str);
}

int	ft_print_hex(unsigned int value, int asc)
{
	int		len;
	char	*out;

	len = hex_len(value);
	out = make_hex_string(value, asc, len);
	if (!out)
		return (0);
	ft_putstr_fd(out, 1);
	free(out);
	return (len);
}
