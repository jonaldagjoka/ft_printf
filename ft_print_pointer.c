/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgjoka <jgjoka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 12:11:15 by jgjoka            #+#    #+#             */
/*   Updated: 2025/11/11 15:03:07 by jgjoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(unsigned long ptr)
{
	char			buffer[17];
	int				len;
	unsigned long	temp;
	int				count;
	int				i;

	len = 0;
	temp = ptr;
	count = 0;
	if (ptr == 0)
		return (ft_print_string("(nil)"));
	while (temp != 0)
	{
		buffer[len++] = "0123456789abcdef"[temp % 16];
		temp /= 16;
	}
	count += ft_print_string("0x");
	i = len - 1;
	while (i >= 0)
	{
		count += ft_print_char(buffer[i]);
		i--;
	}
	return (count);
}
