/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:23:53 by bchelste          #+#    #+#             */
/*   Updated: 2021/01/19 18:35:46 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_output_di(int n, char *p, t_inf *inf)
{
	if ((inf->point != 1) || (n != 0))
		ft_putstr(p);
	if ((inf->point == 1) && (n == 0) && (inf->width != 0))
		ft_putchar(' ');
	if ((inf->point == 1) && (n == 0) && (inf->width == 0))
		inf->len--;
}

static void		ft_width_di(int n, char *p, int l, t_inf *inf)
{
	if ((inf->zero == 1) && (l == 0))
	{
		if (inf->point != 0)
			ft_putnchar((inf->width - inf->len_arg), ' ');
		if (n < 0)
			ft_putchar('-');
		if (inf->point == 0)
			ft_putnchar((inf->width - inf->len_arg), '0');
	}
	else
	{
		ft_putnchar((inf->width - (inf->len_arg + l)), ' ');
		if (n < 0)
			ft_putchar('-');
	}
	ft_putnchar(l, '0');
	ft_output_di(n, p, inf);
}

static void		ft_inf_di(int n, char *p, int l, t_inf *inf)
{
	if (inf->minus == 1)
	{
		if (n < 0)
			ft_putchar('-');
		ft_putnchar(l, '0');
		ft_output_di(n, p, inf);
		if (inf->width > inf->len_arg)
			ft_putnchar((inf->width - (inf->len_arg + l)), ' ');
	}
	else
	{
		if (inf->width > inf->len_arg)
			ft_width_di(n, p, l, inf);
		else
		{
			if (n < 0)
				ft_putchar('-');
			ft_putnchar(l, '0');
			ft_output_di(n, p, inf);
		}
	}
}

void			ft_spec_di(va_list arg, t_inf *inf)
{
	char	*p;
	int		n;
	int		l;

	n = va_arg(arg, int);
	p = ft_itoa_di(n);
	if (p == NULL)
	{
		inf->len = (-1);
		return ;
	}
	inf->len_arg = ft_len_di(n);
	l = inf->prec - ft_strlen(p);
	if (l < 0)
		l = 0;
	if (inf->width <= inf->prec)
		inf->len = inf->len + l;
	if ((inf->width > inf->len_arg) && (inf->width > inf->prec))
		inf->len = inf->len + (inf->width - inf->len_arg);
	ft_inf_di(n, p, l, inf);
	inf->len = inf->len + inf->len_arg;
	inf->i++;
	free(p);
}
