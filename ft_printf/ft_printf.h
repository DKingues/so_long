/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:29:51 by dicosta-          #+#    #+#             */
/*   Updated: 2024/12/02 21:10:41 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

// Hexadecimal bases
# define LC_HEX "0123456789abcdef"
# define HC_HEX "0123456789ABCDEF"

// Main ft_printf function
int	ft_printf(const char *format, ...);
int	skipspaces(const char *format, int i, int *counter);

// Type converter
int	ft_print_format(char specifier, va_list ap);

// Char Conversions
int	ft_print_str(char *str);
int	ft_print_chr(int nbr);

// Int Conversions
int	ft_print_digit(int d);
int	ft_print_hex(unsigned long long nbr, char *base);
int	ft_print_ptr(unsigned long long nbr);
int	ft_print_unsigned(unsigned int d);

#endif