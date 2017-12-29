/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okovalov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 12:42:44 by okovalov          #+#    #+#             */
/*   Updated: 2017/10/06 13:18:30 by okovalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_atoi(const char *str)
{
	int		a;
	int		i;

	a = 1;
	i = 0;
	while ((*str == ' ') || (*str == '\t') || (*str == '\n')
		|| (*str == '\v') || (*str == '\r') || (*str == '\f'))
		str++;
	if (*str == '-' && *(str + 1) >= '0' && *(str + 1) <= '9')
	{
		a = -1;
		str++;
	}
	else if (*str == '+' && *(str + 1) >= '0' && *(str + 1) <= '9')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		i = i * 10 + *str - '0';
		str++;
	}
	return (i * a);
}

char		*ft_strnew(size_t size)
{
	char	*d;
	int		i;

	i = 0;
	d = (char *)malloc(sizeof(char) * size + 1);
	if (d)
	{
		while (size)
		{
			d[i++] = '\0';
			size--;
		}
		d[i] = '\0';
		return (d);
	}
	else
		return (NULL);
}

size_t		ft_len_num(unsigned long long value, int base)
{
	int		count;

	count = 0;
	if (value <= 0)
		count++;
	while (value != 0)
	{
		count++;
		value /= base;
	}
	return (count);
}

char		*ft_lower_case(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] += 32;
		i++;
	}
	return (str);
}

char		*ft_itoa_base(unsigned long long value, int base, int flag)
{
	char	*itoa;
	char	*box;
	size_t	len;

	box = "0123456789ABCDEF";
	len = ft_len_num(value, base);
	itoa = ft_strnew(len);
	if (itoa)
	{
		itoa[len] = '\0';
		if (value == 0)
			itoa[0] = '0';
		while (value != 0)
		{
			itoa[--len] = box[(value % base)];
			value = value / base;
		}
		if (flag == 0)
			itoa = ft_lower_case(itoa);
	}
	return (itoa);
}
