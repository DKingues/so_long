/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:27:33 by dicosta-          #+#    #+#             */
/*   Updated: 2024/11/21 16:50:07 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(unsigned long long nbr)
{
	int	counter;

	counter = 0;
	if (nbr == 0)
		counter += write(1, "(nil)", 5);
	else
	{
		counter += write(1, "0x", 2);
		counter += ft_print_hex(nbr, LC_HEX);
	}
	return (counter);
}
