/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:02:10 by dicosta-          #+#    #+#             */
/*   Updated: 2024/12/17 18:56:48 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	int		counter;
	va_list	ap;

	va_start(ap, format);
	i = 0;
	counter = 0;
	if (!format)
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] == ' ')
		{
			i++;
			i += skipspaces(format, i, &counter);
			counter += ft_print_format(format[i], ap);
		}
		else if (format[i] == '%' && format[i + 1])
			counter += ft_print_format(format[++i], ap);
		else
			counter += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (counter);
}

int	skipspaces(const char *format, int i, int *counter)
{
	int	j;

	j = i;
	while (format[j] == ' ')
		j++;
	if (format[j] != '%')
		*counter += write(1, " ", 1);
	return (j - i);
}

// int main()
// {
// 	char *ptr = "Diogo";
// 	char *ptr1 = NULL;
// 	ft_printf("OWN\n\n");
// 	int	own = ft_printf("INT: %i\nUNS: %u\nDEC: %d\nhex: %x\nHEX: %X\nSTR: %s\nCHR: %c\nPTR: %p\n %p\n %% % % % % % %", 1, 1, 1, 3000, 3000, "asas", 'a', ptr, ptr1);
// 	ft_printf("\nCounter: %d\n\n\n", own);
// 	printf("ORIGINAL\n\n");
// 	int	og = printf("INT: %i\nUNS: %u\nDEC: %d\nhex: %x\nHEX: %X\nSTR: %s\nCHR: %c\nPTR: %p\n %p\n %% % % % % % %", 1, 1, 1, 3000, 3000, "asas", 'a', ptr, ptr1);
// 	printf("\nCounter: %d\n\n\n", og);
// 	char *a = NULL; 
// 	ft_printf(" NULL %s NULL ", a);
// 	char *b = NULL;
// 	printf(" NULL %s NULL ", b);
// }