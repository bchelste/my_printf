/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 17:30:07 by bchelste          #+#    #+#             */
/*   Updated: 2021/01/19 17:43:17 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi_prf(char *form_str, t_inf *inf)
{
	int	res;

	res = 0;
	while ((form_str[inf->i] >= '0') && (form_str[inf->i] <= '9'))
	{
		res = (res * 10) + (form_str[inf->i] - 48);
		inf->i++;
	}
	return (res);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnchar(int n, char c)
{
	while (n > 0)
	{
		write(1, &c, 1);
		n--;
	}
}

int		ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (i);
	while (*str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}
