/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 19:34:33 by dicosta-          #+#    #+#             */
/*   Updated: 2024/11/25 17:10:39 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_digit(int d)
{
	int		counter;
	long	bd;

	bd = d;
	counter = 0;
	if (bd < 0)
	{
		counter += write(1, "-", 1);
		bd *= -1;
	}
	if (bd > 9)
	{
		counter += ft_print_digit(bd / 10);
		counter += ft_print_digit(bd % 10);
	}
	else
	{
		bd = bd + '0';
		counter += write(1, &bd, 1);
	}
	return (counter);
}
