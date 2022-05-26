/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:24:57 by bchelste          #+#    #+#             */
/*   Updated: 2021/01/19 18:22:09 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_len_a(unsigned long a)
{
	int				i;

	i = 0;
	if (a == 0)
		return (1);
	while (a != 0)
	{
		a = a / 16;
		i++;
	}
	return (i);
}

static char			*ft_itoa_a(unsigned long a)
{
	char			*p;
	int				l;
	int				tmp;

	l = ft_len_a(a);
	if ((p = (char*)malloc(sizeof(char) * (l + 1))) == NULL)
		return (NULL);
	p[l] = '\0';
	if (a == 0)
		p[0] = '0';
	while (--l >= 0)
	{
		tmp = a % 16;
		a = a / 16;
		if (tmp < 10)
			p[l] = tmp + 48;
		else
			p[l] = tmp + 87;
	}
	return (p);
}

static void			ft_output_a(unsigned long a, char *p, t_inf *inf)
{
	if ((inf->point != 1) || (a != 0))
		ft_putstr(p);
}

static void			ft_inf_a(unsigned int a, char *p,
									int l, t_inf *inf)
{
	if (inf->minus == 1)
	{
		ft_putstr("0x");
		ft_putnchar(l, '0');
		ft_output_a(a, p, inf);
		if (inf->width > inf->len_arg)
			ft_putnchar((inf->width - (inf->len_arg + l)), ' ');
	}
	else
	{
		if ((inf->width > inf->len_arg) &&
			((inf->zero != 1) || (inf->point != 0)))
			ft_putnchar((inf->width - (inf->len_arg + l)), ' ');
		if ((inf->width > inf->len_arg) &&
			(inf->zero == 1) && (inf->point == 0))
			ft_putnchar((inf->width - (inf->len_arg + l)), '0');
		ft_putstr("0x");
		ft_putnchar(l, '0');
		ft_output_a(a, p, inf);
	}
}

void				ft_spec_p(va_list arg, t_inf *inf)
{
	char			*p;
	unsigned long	a;
	int				l;

	a = va_arg(arg, unsigned long);
	p = ft_itoa_a(a);
	if (p == NULL)
	{
		inf->len = (-1);
		return ;
	}
	inf->len_arg = ft_len_a(a) + 2;
	l = inf->prec - inf->len_arg + 2;
	if (l < 0)
		l = 0;
	if ((inf->point == 1) && (a == 0))
		inf->len_arg--;
	if ((inf->width <= inf->prec) && (l != 0))
		inf->len = inf->len + l;
	if ((inf->width > inf->prec) && (inf->width > inf->len_arg))
		inf->len = inf->len + (inf->width - inf->len_arg);
	ft_inf_a(a, p, l, inf);
	inf->len = inf->len + inf->len_arg;
	inf->i++;
	free(p);
}
