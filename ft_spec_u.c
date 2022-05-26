/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 16:24:22 by bchelste          #+#    #+#             */
/*   Updated: 2021/01/19 18:31:49 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_len_u(unsigned int u)
{
	int				i;

	i = 0;
	if (u == 0)
		return (1);
	while (u != 0)
	{
		u = u / 10;
		i++;
	}
	return (i);
}

static char			*ft_itoa_u(unsigned int u)
{
	char	*p;
	int		l;

	l = ft_len_u(u);
	p = (char*)malloc(sizeof(char) * (l + 1));
	if (p == NULL)
		return (NULL);
	p[l] = '\0';
	l--;
	if (u == 0)
		p[0] = '0';
	while (l >= 0)
	{
		p[l] = (u % 10) + 48;
		u = u / 10;
		l--;
	}
	return (p);
}

static void			ft_output_u(int u, char *p, t_inf *inf)
{
	if ((inf->point != 1) || (u != 0))
		ft_putstr(p);
	if ((inf->point == 1) && (u == 0) && (inf->width != 0))
		ft_putchar(' ');
	if ((inf->point == 1) && (u == 0) && (inf->width == 0))
		inf->len--;
}

static void			ft_inf_u(unsigned int u, char *p,
							int l, t_inf *inf)
{
	if (inf->minus == 1)
	{
		ft_putnchar(l, '0');
		ft_output_u(u, p, inf);
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
		ft_output_u(u, p, inf);
	}
}

void				ft_spec_u(va_list arg, t_inf *inf)
{
	unsigned int	u;
	char			*p;
	int				l;

	u = va_arg(arg, unsigned int);
	p = ft_itoa_u(u);
	if (p == NULL)
	{
		inf->len = (-1);
		return ;
	}
	inf->len_arg = ft_len_u(u);
	l = inf->prec - inf->len_arg;
	if (l < 0)
		l = 0;
	if (inf->width <= inf->prec)
		inf->len = inf->len + l;
	if ((inf->width > inf->prec) && (inf->width > inf->len_arg))
		inf->len = inf->len + (inf->width - inf->len_arg);
	ft_inf_u(u, p, l, inf);
	inf->len = inf->len + inf->len_arg;
	inf->i++;
	free(p);
}
