/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okovalov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:40:41 by okovalov          #+#    #+#             */
/*   Updated: 2017/10/06 13:22:30 by okovalov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char const *s)
{
	if (s)
		while (*s)
		{
			write(1, &(*s), 1);
			g_ns++;
			s++;
		}
}

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char*)s);
	else
		return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t c;

	c = 0;
	while (*str++)
		c++;
	return (c);
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned long	a;
	char			*d;

	if (!s)
		return (NULL);
	a = 0;
	d = (char *)malloc(sizeof(char) * len + 1);
	if (d)
	{
		while (a < len)
			d[a++] = s[start++];
		d[a] = '\0';
		return (d);
	}
	else
		return (NULL);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
	g_ns++;
}
