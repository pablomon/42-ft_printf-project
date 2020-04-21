/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmontese <pmontese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:30:50 by pmontese          #+#    #+#             */
/*   Updated: 2020/01/30 17:25:13 by pmontese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		putchar_count(char c, int fd)
{
	ft_putchar_fd(c, fd);
	return (1);
}

int		putstr_count(char *s, int fd)
{
	char	c;
	int		chars_put;

	chars_put = 0;
	if (s)
	{
		while (*s)
		{
			c = *s;
			chars_put += putchar_count(c, fd);
			s++;
		}
	}
	return (chars_put);
}

int		print_conversion(t_format *f)
{
	char	type;
	int		chars_put;

	chars_put = -1;
	type = f->conversion_type;
	if (type == 'd' || type == 'i')
		chars_put = print_d(f);
	else if (type == 'c')
		chars_put = print_c(f);
	else if (type == 's')
		chars_put = print_s(f);
	else if (type == 'u')
		chars_put = print_u(f);
	else if (type == 'x' || type == 'X')
		chars_put = print_x(f);
	else if (type == 'p')
		chars_put = print_p(f);
	else if (type == '%')
		chars_put = print_percent(f);
	return (chars_put);
}

int		print(const char *str, va_list ap, t_format *f)
{
	int	chars_put;

	chars_put = 0;
	if (str == NULL)
		return (-1);
	while (*str)
	{
		while (*str && *str != '%')
		{
			chars_put += putchar_count(*str, 1);
			str++;
		}
		if (*str == '%' && str++)
		{
			if (*str == '%' && str++)
				chars_put += putchar_count('%', 1);
			else
			{
				str += parse_conversion(str, ap, f);
				chars_put += print_conversion(f);
			}
		}
	}
	return (chars_put);
}

int		ft_printf(const char *str, ...)
{
	int			chars_put;
	va_list		ap;
	t_format	*f;

	va_start(ap, str);
	if ((f = (t_format*)malloc(sizeof(t_format))) == NULL)
		return (-1);
	chars_put = print(str, ap, f);
	va_end(ap);
	free(f);
	return (chars_put);
}
