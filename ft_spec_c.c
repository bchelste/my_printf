/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 12:48:24 by bchelste          #+#    #+#             */
/*   Updated: 2021/01/19 17:45:26 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_spec_c(va_list arg, t_inf *inf)
{
	char	c;

	c = va_arg(arg, int);
	if (inf->minus == 1)
		ft_putchar(c);
	if (inf->width > 1)
	{
		inf->len = inf->len + inf->width - 1;
		if ((inf->zero == 1) && (inf->minus == 0))
			while (inf->width-- > 1)
				ft_putchar('0');
		else
			while (inf->width-- > 1)
				ft_putchar(' ');
	}
	if (inf->minus == 0)
		ft_putchar(c);
	inf->len++;
	inf->i++;
}
