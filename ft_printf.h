/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchelste <bchelste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 17:30:01 by bchelste          #+#    #+#             */
/*   Updated: 2021/01/19 18:16:28 by bchelste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_inf
{
	int			minus;
	int			zero;
	int			width;
	int			prec;
	int			point;
	char		type;
	int			len;
	int			i;
	int			len_arg;
}				t_inf;

int				ft_printf(const char *str, ...);
void			ft_init_struct(t_inf *inf);

void			ft_get_flag(char *form_str, t_inf *inf);
void			ft_get_width(char *form_str, va_list arg, t_inf *inf);
void			ft_get_precision(char *form_str, va_list arg, t_inf *inf);
void			ft_get_specifier(char *form_str, va_list arg, t_inf *inf);
void			ft_parser(char *form_str, va_list arg, t_inf *inf);

void			ft_spec_c(va_list arg, t_inf *inf);
void			ft_spec_s(va_list arg, t_inf *inf);
void			ft_spec_p(va_list arg, t_inf *inf);
void			ft_spec_di(va_list arg, t_inf *inf);
void			ft_spec_u(va_list arg, t_inf *inf);
void			ft_spec_x(va_list arg, t_inf *inf);
void			ft_spec_perc(t_inf *inf);

int				ft_atoi_prf(char *form_str, t_inf *inf);
void			ft_putchar(char c);
void			ft_putnchar(int n, char c);
int				ft_strlen(const char *str);
void			ft_putstr(char *str);

int				ft_len_di(int n);
char			*ft_itoa_di(int n);

#endif
