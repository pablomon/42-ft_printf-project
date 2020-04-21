/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmontese <pmontese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:58:27 by pmontese          #+#    #+#             */
/*   Updated: 2020/01/30 17:50:42 by pmontese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_x(t_format *f)
{
	unsigned int	nbr;
	char			*str;
	char			*str2;
	int				chars_put;

	nbr = (unsigned int)f->arg;
	str = get_hex_str(nbr, f->conversion_type == 'X');
	if (str[0] == '0' && f->precision == 0)
		str2 = do_flags(f, "");
	else
		str2 = do_flags(f, str);
	free(str);
	chars_put = putstr_count(str2, 1);
	free(str2);
	return (chars_put);
}
