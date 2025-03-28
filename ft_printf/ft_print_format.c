/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:05:40 by dicosta-          #+#    #+#             */
/*   Updated: 2024/11/22 15:25:51 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_format(char specifier, va_list ap)
{
	int	counter;

	counter = 0;
	if (specifier == '%')
		counter += write(1, "%", 1);
	else if (specifier == 'i')
		counter += ft_print_digit(va_arg(ap, int));
	else if (specifier == 'd')
		counter += ft_print_digit(va_arg(ap, int));
	else if (specifier == 'u')
		counter += ft_print_unsigned(va_arg(ap, unsigned int));
	else if (specifier == 's')
		counter += ft_print_str(va_arg(ap, char *));
	else if (specifier == 'x')
		counter += ft_print_hex(va_arg(ap, unsigned int), LC_HEX);
	else if (specifier == 'X')
		counter += ft_print_hex(va_arg(ap, unsigned int), HC_HEX);
	else if (specifier == 'c')
		counter += ft_print_chr(va_arg(ap, int));
	else if (specifier == 'p')
		counter += ft_print_ptr(va_arg(ap, unsigned long));
	return (counter);
}
