/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmontese <pmontese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:55:32 by pmontese          #+#    #+#             */
/*   Updated: 2020/01/30 17:35:34 by pmontese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*apply_s_flags(t_format *f, char *str)
{
	char	*str2;

	str2 = NULL;
	if (f->precision >= 0)
	{
		if (f->hyphen)
			str2 = ft_strfill(' ', f->width, str, 0);
		else
			str2 = ft_strfill(' ', f->width, str, 1);
	}
	else
	{
		if (f->hyphen)
			str2 = ft_strfill(' ', f->width, str, 0);
		else if (f->zero)
			str2 = ft_strfill('0', f->width, str, 1);
		else
			str2 = ft_strfill(' ', f->width, str, 1);
	}
	if (str2 == NULL)
		str2 = ft_strdup(str);
	return (str2);
}

int		print_s(t_format *f)
{
	char	*input;
	char	*str;
	char	*str2;
	int		chars_put;

	if ((input = (char*)f->arg) == NULL)
		input = "(null)";
	if (f->precision >= 0)
	{
		str = ft_strnew(f->precision);
		ft_strncpy(str, input, f->precision);
	}
	else
		str = ft_strdup(input);
	str2 = apply_s_flags(f, str);
	free(str);
	chars_put = putstr_count(str2, 1);
	free(str2);
	return (chars_put);
}
