/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:26:14 by bchelste          #+#    #+#             */
/*   Updated: 2021/01/19 18:35:07 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_len_x(unsigned int x)
{
	int				i;

	i = 0;
	if (x == 0)
		return (1);
	while (x != 0)
	{
		x = x / 16;
		i++;
	}
	return (i);
}

static char			*ft_itoa_x(unsigned int x, t_inf *inf)
{
	char			*p;
	int				l;
	int				tmp;

	l = ft_len_x(x);
	if ((p = (char*)malloc(sizeof(char) * (l + 1))) == NULL)
		return (NULL);
	p[l] = '\0';
	if (x == 0)
		p[0] = '0';
	while (--l >= 0)
	{
		tmp = x % 16;
		x = x / 16;
		if (tmp < 10)
			p[l] = tmp + 48;
		else
		{
			if (inf->type == 'x')
				p[l] = tmp + 87;
			if (inf->type == 'X')
				p[l] = tmp + 55;
		}
	}
	return (p);
}

static void			ft_output_x(int x, char *p, t_inf *inf)
{
	if ((inf->point != 1) || (x != 0))
		ft_putstr(p);
	if ((inf->point == 1) && (x == 0) && (inf->width != 0))
		ft_putchar(' ');
	if ((inf->point == 1) && (x == 0) && (inf->width == 0))
		inf->len--;
}

static void			ft_inf_x(unsigned int x, char *p, int l, t_inf *inf)
{
	if (inf->minus == 1)
	{
		ft_putnchar(l, '0');
		ft_output_x(x, p, inf);
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
		ft_putnchar(l, '0');
		ft_output_x(x, p, inf);
	}
}

void				ft_spec_x(va_list arg, t_inf *inf)
{
	unsigned int	x;
	char			*p;
	int				l;

	x = va_arg(arg, unsigned int);
	p = ft_itoa_x(x, inf);
	if (p == NULL)
	{
		inf->len = (-1);
		return ;
	}
	inf->len_arg = ft_len_x(x);
	l = inf->prec - inf->len_arg;
	if (l < 0)
		l = 0;
	if (inf->width <= inf->prec)
		inf->len = inf->len + l;
	if ((inf->width > inf->prec) && (inf->width > inf->len_arg))
		inf->len = inf->len + (inf->width - inf->len_arg);
	ft_inf_x(x, p, l, inf);
	inf->len = inf->len + inf->len_arg;
	inf->i++;
	free(p);
}
