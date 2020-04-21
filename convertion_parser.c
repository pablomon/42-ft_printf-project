/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertion_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmontese <pmontese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:20:05 by pmontese          #+#    #+#             */
/*   Updated: 2020/01/30 20:52:28 by pmontese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	parse_flags(const char *str, struct s_format *f)
{
	int	characters_read;

	characters_read = 0;
	while (ft_iscontained(str[characters_read], "0+-"))
	{
		if (str[characters_read] == '0')
			f->zero = 1;
		if (str[characters_read] == '+')
			f->plus = 1;
		if (str[characters_read] == '-')
			f->hyphen = 1;
		characters_read++;
	}
	return (characters_read);
}

size_t	parse_width(const char *str, va_list ap, struct s_format *f)
{
	int		characters_read;
	char	tempstr[10000];
	int		star_val;

	characters_read = str[0] == '*' ? 1 : 0;
	if (str[0] == '*')
	{
		star_val = va_arg(ap, int);
		f->hyphen = star_val < 0 ? 1 : f->hyphen;
		star_val = star_val < 0 ? -star_val : star_val;
		f->width = star_val;
	}
	else if (ft_iscontained(*str, "123456789"))
	{
		while (ft_iscontained(str[characters_read], "0123456789"))
		{
			tempstr[characters_read] = str[characters_read];
			characters_read++;
		}
		tempstr[characters_read] = 0;
		f->width = ft_atoi(tempstr);
	}
	return (characters_read);
}

int		parse_precision(const char *str, va_list ap, struct s_format *f)
{
	int		characters_read;
	char	tempstr[10000];
	int		star_val;

	characters_read = 0;
	tempstr[0] = '0';
	characters_read++;
	if (str[characters_read] == '*')
	{
		characters_read++;
		star_val = va_arg(ap, int);
		star_val = star_val < 0 ? -1 : star_val;
		f->precision = star_val;
	}
	else
	{
		while (ft_iscontained(str[characters_read], "0123456789"))
		{
			tempstr[characters_read] = str[characters_read];
			characters_read++;
		}
		tempstr[characters_read] = 0;
		f->precision = ft_atoi(tempstr);
	}
	return (characters_read);
}

void	set_format(struct s_format *f)
{
	f->conversion_type = '0';
	f->precision = -1;
	f->hyphen = 0;
	f->plus = 0;
	f->width = 0;
	f->zero = 0;
	f->arg = 0;
}

int		parse_conversion(const char *str, va_list ap, t_format *f)
{
	int		i;

	if (!*str)
		return (0);
	set_format(f);
	i = parse_flags(str, f);
	i += parse_width(&str[i], ap, f);
	if (str[i] == '.')
		i += parse_precision(&str[i], ap, f);
	f->arg = va_arg(ap, void*);
	if (ft_iscontained(str[i], CONVERTIONS))
	{
		f->conversion_type = str[i];
		i++;
	}
	return (i);
}
