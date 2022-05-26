/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 13:05:48 by bchelste          #+#    #+#             */
/*   Updated: 2021/01/20 13:42:12 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_strdup(const char *str)
{
	char	*dup;
	int		i;

	i = 0;
	dup = (char*)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static char	*ft_substr(char const *str, int start, int len)
{
	char	*sub;
	int		i;

	if (str == NULL)
		return (NULL);
	i = 0;
	if (start >= ft_strlen(str))
	{
		sub = (char*)malloc(sizeof(char));
		if (sub == NULL)
			return (NULL);
		*sub = '\0';
		return (sub);
	}
	sub = (char*)malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (NULL);
	while ((str[i] != '\0') && (len > 0))
	{
		sub[i] = str[start + i];
		i++;
		len--;
	}
	sub[i] = '\0';
	return (sub);
}

static char	*ft_str_p(char *str, t_inf *inf)
{
	char	*p;

	if (str == NULL)
		str = "(null)";
	if (inf->point == 0)
		p = ft_strdup(str);
	else
		p = ft_substr(str, 0, inf->prec);
	return (p);
}

static void	ft_inf_s(char *p, t_inf *inf)
{
	if ((inf->minus == 1) && (inf->point != 1))
		ft_putstr(p);
	if (inf->width > inf->len_arg)
	{
		inf->len = inf->len + (inf->width - inf->len_arg);
		if ((inf->zero == 1) && (inf->minus != 1))
			ft_putnchar((inf->width - inf->len_arg), '0');
		else
			ft_putnchar((inf->width - inf->len_arg), ' ');
	}
	if ((inf->minus == 0) && (inf->point != 1))
		ft_putstr(p);
}

void		ft_spec_s(va_list arg, t_inf *inf)
{
	char	*str;
	char	*p;

	str = va_arg(arg, char*);
	p = ft_str_p(str, inf);
	if (p == NULL)
	{
		inf->len = (-1);
		return ;
	}
	inf->len_arg = ft_strlen(p);
	ft_inf_s(p, inf);
	inf->len = inf->len + inf->len_arg;
	inf->i++;
	free(p);
}
