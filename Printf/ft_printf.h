/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgjoka <jgjoka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 12:11:35 by jgjoka            #+#    #+#             */
/*   Updated: 2025/11/13 20:10:55 by jgjoka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int		ft_printf(const char *input, ...);
int		ft_print_pointer(unsigned long value);
int		ft_print_unsigned(unsigned int nb);
int		ft_print_string(char *s);
int		ft_print_decimal(int n);
int		ft_print_char(char c);
int		ft_print_hex(unsigned int value, int asc);

#endif
