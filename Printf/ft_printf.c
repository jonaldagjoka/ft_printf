/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgjoka <jgjoka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 12:11:30 by jgjoka            #+#    #+#             */
/*   Updated: 2025/11/13 20:15:00 by jgjoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stddef.h>

static char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

static int	check_type(const char *input, va_list args)
{
	int	i;

	i = 0;
	if (*input == 'c')
		i += ft_print_char(va_arg(args, int));
	else if (*input == 's')
		i += ft_print_string(va_arg(args, char *));
	else if (*input == 'p')
		i += ft_print_pointer(va_arg(args, unsigned long));
	else if (*input == 'd' || *input == 'i')
		i += ft_print_decimal(va_arg(args, int));
	else if (*input == 'u')
		i += ft_print_unsigned(va_arg(args, unsigned int));
	else if (*input == 'x')
		i += ft_print_hex(va_arg(args, unsigned int), 87);
	else if (*input == 'X')
		i += ft_print_hex(va_arg(args, unsigned int), 55);
	return (i);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, input);
	while (*input)
	{
		if (*input == '%')
		{
			input++;
			if (*input == '\0')
				return (-1);
			if (ft_strchr("cspdiuxX", *input))
				i += check_type(input, args);
			else if (*input == '%')
				i += ft_print_char('%');
		}
		else
			i += ft_print_char(*input);
		input++;
	}
	va_end(args);
	return (i);
}
