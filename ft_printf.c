/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 19:27:36 by bchelste          #+#    #+#             */
/*   Updated: 2021/01/19 18:08:58 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_init_struct(t_inf *inf)
{
	inf->minus = 0;
	inf->zero = 0;
	inf->width = 0;
	inf->prec = 0;
	inf->point = 0;
	inf->type = 0;
	inf->len = 0;
	inf->i = 0;
	inf->len_arg = 0;
}

int				ft_printf(const char *form_str, ...)
{
	va_list		arg;
	t_inf		inf;
	int			length;

	length = 0;
	ft_init_struct(&inf);
	va_start(arg, form_str);
	while (form_str[inf.i] != '\0')
	{
		if (form_str[inf.i] != '%')
		{
			ft_putchar(form_str[inf.i]);
			inf.i++;
			inf.len++;
		}
		else
		{
			if (form_str[inf.i + 1] == '\0')
				break ;
			ft_parser((char*)form_str, arg, &inf);
		}
	}
	length = inf.len;
	va_end(arg);
	return (length);
}
