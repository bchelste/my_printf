/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_src_spec_di.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 18:12:51 by bchelste          #+#    #+#             */
/*   Updated: 2021/01/19 18:39:51 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_len_di(int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa_di(int n)
{
	char	*p;
	int		l;
	int		k;

	l = ft_len_di(n);
	k = 1;
	if (n < 0)
	{
		k = -1;
		l--;
	}
	p = (char*)malloc(sizeof(char) * (l + 1));
	if (p == NULL)
		return (NULL);
	p[l] = '\0';
	l--;
	if (n == 0)
		p[0] = '0';
	while (l >= 0)
	{
		p[l] = ((n % 10) * k) + 48;
		n = n / 10;
		l--;
	}
	return (p);
}
