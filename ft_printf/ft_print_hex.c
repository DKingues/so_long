/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:28:00 by dicosta-          #+#    #+#             */
/*   Updated: 2024/11/21 16:58:19 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned long long nbr, char *base)
{
	int	counter;

	counter = 0;
	if (nbr > 15)
	{
		counter += ft_print_hex(nbr / 16, base);
	}
	counter += write(1, &base[nbr % 16], 1);
	return (counter);
}
