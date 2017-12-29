/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   castind.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okovalov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 16:41:27 by okovalov          #+#    #+#             */
/*   Updated: 2017/10/23 17:14:22 by okovalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			cind2(t_prnt *prf, va_list ap, intmax_t *tem)
{
	if (prf->razm == 'l' || prf->tup == 'D')
		*tem = (va_arg(ap, long));
	else if (prf->razm == 'h')
		*tem = (short)(va_arg(ap, int));
	else if (prf->razm == 'L')
		*tem = (va_arg(ap, long long));
	else if (prf->razm == 'j')
		*tem = (va_arg(ap, intmax_t));
	else if (prf->razm == 'z')
		*tem = (va_arg(ap, size_t));
	else if (prf->razm == 'H')
		*tem = (char)(va_arg(ap, int));
	else
		*tem = va_arg(ap, int);
	prf->temp = ft_itoaspec(*tem);
	prf->lng = (int)(ft_strlen(prf->temp));
	if (prf->temp[0] == '-' || ft_strchr(prf->flg, '+'))
		prf->shur[0]--;
	if (ft_strchr(prf->flg, ' ') && !ft_strchr(prf->flg, '+')
		&& prf->temp[0] != '-')
	{
		ft_putchar(' ');
		prf->shur[0]--;
	}
}

void			cind3(t_prnt prf, intmax_t tem)
{
	if (prf.temp[0] == '-' && (!ft_strchr(prf.flg, '0') || prf.tochn[1] >= 0))
	{
		ft_putchar('-');
		prf.temp = ft_strsub(prf.temp, 1, ft_strlen(prf.temp) - 1);
		prf.lng = (int)(ft_strlen(prf.temp));
	}
	else if (ft_strchr(prf.flg, '+') && !ft_strchr(prf.flg, '0'))
		ft_putchar('+');
	if (prf.tochn[1] > 0)
		while (prf.tochn[0]-- > prf.lng)
		{
			ft_putchar('0');
			prf.shur[0]--;
		}
	if (prf.tochn[1] == 0 && tem == 0 && prf.shur[1] > 0)
		ft_putchar(' ');
	else if (prf.tochn[1] == 0 && tem == 0 && prf.shur[1] < 0)
		prf.tochn[0]++;
	else
		ft_putstr(prf.temp);
	if (ft_strchr(prf.flg, '-'))
		while (prf.shur[0]-- - prf.lng >= 1)
			ft_putchar(' ');
}

void			cind(t_prnt prf, va_list ap)
{
	intmax_t	tem;

	cind2(&prf, ap, &tem);
	if (prf.temp[0] == '-' && ft_strchr(prf.flg, '0') && prf.tochn[1] >= 0)
		prf.lng--;
	if (prf.temp[0] == '-' && ft_strchr(prf.flg, '0') && prf.tochn[1] <= 0)
	{
		ft_putchar('-');
		prf.temp = ft_strsub(prf.temp, 1, ft_strlen(prf.temp) - 1);
		prf.lng = (int)(ft_strlen(prf.temp));
	}
	else if (ft_strchr(prf.flg, '+') && ft_strchr(prf.flg, '0'))
		ft_putchar('+');
	if (!ft_strchr(prf.flg, '-'))
	{
		while (prf.shur[0]--
			- (prf.tochn[0] > prf.lng ? prf.tochn[0] : prf.lng)
			+ (prf.tochn[1] == -1 && prf.temp[0] == '-'
			&& !ft_strchr(prf.flg, '0') ? 1 : 0)
			+ (prf.tochn[0] < prf.lng && prf.tochn[1] > 0
			&& prf.temp[0] == '-' && !ft_strchr(prf.flg, '0') ? 1 : 0) >= 1)
			zero(prf, 0);
	}
	cind3(prf, tem);
}

int				color(const char *format, int i)
{
	if (format[i] == '{' && (format[i + 1] == 'r' || format[i + 1] == 'g'
				|| format[i + 1] == 'b' || format[i + 1] == 'y'
				|| format[i + 1] == 'm' || format[i + 1] == 'c'
				|| format[i + 1] == 'R') && format[i + 2] == '}')
	{
		i++;
		if (format[i] == 'r')
			ft_putstr("\x1b[31m");
		else if (format[i] == 'g')
			ft_putstr("\x1b[32m");
		else if (format[i] == 'y')
			ft_putstr("\x1b[33m");
		else if (format[i] == 'b')
			ft_putstr("\x1b[34m");
		else if (format[i] == 'm')
			ft_putstr("\x1b[35m");
		else if (format[i] == 'c')
			ft_putstr("\x1b[36m");
		else if (format[i] == 'R')
			ft_putstr("\x1b[0m");
		i += 2;
	}
	return (i);
}

int				percent(const char *format, int i, va_list ap)
{
	int			j;

	if (format[i] == '%' && format[i + 1] && format[i + 1] != '%')
	{
		j = cast(specform(format, i + 1), ap);
		i = j;
		i++;
	}
	else if (format[i])
		ft_putchar(format[i++]);
	return (i);
}
