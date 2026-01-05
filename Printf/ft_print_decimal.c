/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgjoka <jgjoka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 12:11:08 by jgjoka            #+#    #+#             */
/*   Updated: 2025/11/13 19:55:00 by jgjoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static void	ft_print_rec(int n)
{
	if (n <= -10 || n >= 10)
		ft_print_rec(n / 10);
	if (n < 0)
		ft_putchar_fd('0' - (n % 10), 1);
	else
		ft_putchar_fd((n % 10) + '0', 1);
}

int	ft_print_decimal(int n)
{
	int				len;
	long int		nb;

	nb = n;
	len = 1;
	if (nb < 0)
	{
		ft_putchar_fd('-', 1);
		nb = -nb;
		len++;
	}
	ft_print_rec((int)nb);
	while (nb >= 10)
	{
		nb /= 10;
		len++;
	}
	return (len);
}
