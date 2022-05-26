/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 16:10:46 by bchelste          #+#    #+#             */
/*   Updated: 2021/01/20 13:42:22 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_get_flag(char *form_str, t_inf *inf)
{
	inf->zero = 0;
	inf->minus = 0;
	while ((form_str[inf->i] == '0') || (form_str[inf->i] == '-'))
	{
		if (form_str[inf->i] == '0')
			inf->zero = 1;
		if (form_str[inf->i] == '-')
			inf->minus = 1;
		inf->i++;
	}
}

void		ft_get_width(char *form_str, va_list arg, t_inf *inf)
{
	inf->width = 0;
	if (form_str[inf->i] == '*')
	{
		inf->width = va_arg(arg, int);
		if (inf->width < 0)
		{
			inf->width = inf->width * (-1);
			inf->minus = 1;
		}
		inf->i++;
	}
	if ((form_str[inf->i] >= '0') && (form_str[inf->i] <= '9'))
		inf->width = ft_atoi_prf(form_str, inf);
	while ((form_str[inf->i] >= '0') && (form_str[inf->i] <= '9'))
		inf->i++;
}

void		ft_get_precision(char *form_str, va_list arg, t_inf *inf)
{
	inf->point = 0;
	inf->prec = 0;
	if (form_str[inf->i] == '.')
	{
		inf->point = 1;
		inf->i++;
		if (form_str[inf->i] == '*')
		{
			inf->prec = va_arg(arg, int);
			if (inf->prec < 0)
			{
				inf->prec = 0;
				inf->point = 0;
			}
			inf->i++;
		}
		if ((form_str[inf->i] >= '0') && (form_str[inf->i] <= '9'))
			inf->prec = ft_atoi_prf(form_str, inf);
		while ((form_str[inf->i] >= '0') && (form_str[inf->i] <= '9'))
			inf->i++;
		if (inf->prec > 0)
			inf->point = 2;
	}
}

void		ft_get_specifier(char *form_str, va_list arg, t_inf *inf)
{
	if (form_str[inf->i] == 'c')
		ft_spec_c(arg, inf);
	else if (form_str[inf->i] == 's')
		ft_spec_s(arg, inf);
	else if (form_str[inf->i] == 'p')
		ft_spec_p(arg, inf);
	else if ((form_str[inf->i] == 'd') || (form_str[inf->i] == 'i'))
		ft_spec_di(arg, inf);
	else if (form_str[inf->i] == 'u')
		ft_spec_u(arg, inf);
	else if (form_str[inf->i] == 'x')
	{
		inf->type = 'x';
		ft_spec_x(arg, inf);
	}
	else if (form_str[inf->i] == 'X')
	{
		inf->type = 'X';
		ft_spec_x(arg, inf);
	}
	else if (form_str[inf->i] == '%')
		ft_spec_perc(inf);
	else
		return ;
}

void		ft_parser(char *form_str, va_list arg, t_inf *inf)
{
	inf->len_arg = 0;
	inf->i++;
	if (form_str[inf->i] == ' ')
	{
		ft_putchar(' ');
		inf->len++;
		inf->i++;
	}
	ft_get_flag(form_str, inf);
	ft_get_width(form_str, arg, inf);
	ft_get_precision(form_str, arg, inf);
	ft_get_specifier(form_str, arg, inf);
}
