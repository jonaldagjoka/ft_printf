/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgjoka <jgjoka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 12:11:22 by jgjoka            #+#    #+#             */
/*   Updated: 2025/11/13 20:11:53 by jgjoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static void	ft_print_rec(unsigned int n)
{
	if (n >= 10)
		ft_print_rec(n / 10);
	ft_putchar_fd((n % 10) + '0', 1);
}

int	ft_print_unsigned(unsigned int n)
{
	unsigned int	i;
	unsigned int	temp;

	ft_print_rec(n);
	i = 1;
	temp = n;
	while (temp >= 10)
	{
		temp /= 10;
		i++;
	}
	return (i);
}
