/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_perc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:29:53 by bchelste          #+#    #+#             */
/*   Updated: 2021/01/19 17:54:15 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_spec_perc(t_inf *inf)
{
	if (inf->minus == 1)
		ft_putchar('%');
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
		ft_putchar('%');
	inf->len++;
	inf->i++;
}
