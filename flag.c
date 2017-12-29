/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okovalov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 16:58:35 by okovalov          #+#    #+#             */
/*   Updated: 2017/10/23 17:35:34 by okovalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		flag(const char *format, int i, t_prnt *prf)
{
	while (format[i] == '-' || format[i] == '+'
		|| format[i] == ' ' || format[i] == '#' || format[i] == '0')
	{
		if (prf->flg[prf->jj] && prf->jj < 5)
			prf->jj++;
		prf->flg[prf->jj] = format[i++];
	}
	return (i);
}

int		hl(const char *format, int i, t_prnt *prf)
{
	if (format[i] == 'h' && (format[i + 1] == 'h'
		|| (format[i + 1] == ' ' && format[i + 2] == 'h')))
	{
		if (format[i + 1] == ' ' && prf->jj < 5)
		{
			prf->flg[prf->jj] = ' ';
			i++;
		}
		i += 2;
		prf->razm = 'H';
	}
	if (format[i] == 'l' && (format[i + 1] == 'l'
		|| (format[i + 1] == ' ' && format[i + 2] == 'l')))
	{
		if (format[i + 1] == ' ' && prf->jj < 5)
		{
			prf->flg[prf->jj] = ' ';
			i++;
		}
		i += 2;
		prf->razm = 'L';
	}
	return (i);
}

void	minuso(t_prnt prf)
{
	if (ft_strchr(prf.flg, '-'))
	{
		if (prf.tochn[1] < prf.lng && ft_strchr(prf.flg, '#'))
			prf.shur[0]--;
		while (prf.shur[0]--
			- (prf.tochn[1] > prf.lng ? prf.tochn[1] : prf.lng) >= 1)
			ft_putchar(' ');
	}
}

void	minusx(t_prnt prf)
{
	if (ft_strchr(prf.flg, '-'))
		while (prf.shur[0]-- - (prf.tochn[1] > prf.lng ? prf.tochn[1] : prf.lng)
			- (ft_strchr(prf.flg, '#') ? 2 : 0) >= 1)
			ft_putchar(' ');
}
