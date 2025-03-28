/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:33:38 by dicosta-          #+#    #+#             */
/*   Updated: 2024/11/21 16:53:34 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int d)
{
	int		counter;
	long	bd;

	bd = d;
	counter = 0;
	if (bd > 9)
	{
		counter += ft_print_unsigned(bd / 10);
		counter += ft_print_unsigned(bd % 10);
	}
	else
	{
		bd = bd + '0';
		counter += write(1, &bd, 1);
	}
	return (counter);
}
