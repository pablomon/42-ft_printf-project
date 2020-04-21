/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmontese <pmontese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:28:43 by pmontese          #+#    #+#             */
/*   Updated: 2020/01/30 17:19:39 by pmontese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_d(t_format *f)
{
	char			*str1;
	char			*str2;
	long long int	nbr;
	int				chars_put;

	nbr = (int)f->arg;
	str1 = lltoa(nbr);
	if (str1[0] == '0' && f->precision == 0)
		str2 = do_flags(f, "");
	else
		str2 = do_flags(f, str1);
	free(str1);
	chars_put = putstr_count(str2, 1);
	free(str2);
	return (chars_put);
}
