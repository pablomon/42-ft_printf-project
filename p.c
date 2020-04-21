/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmontese <pmontese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:55:32 by pmontese          #+#    #+#             */
/*   Updated: 2020/01/30 17:33:11 by pmontese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_p(t_format *f)
{
	unsigned long long	nbr;
	char				*str;
	char				*str2;
	int					chars_put;

	nbr = (unsigned long long)f->arg;
	str = get_hex_str(nbr, f->conversion_type == 'P');
	if (str[0] == '0' && f->precision == 0)
		str2 = do_flags(f, "");
	else
		str2 = do_flags(f, str);
	free(str);
	chars_put = putstr_count(str2, 1);
	free(str2);
	return (chars_put);
}
