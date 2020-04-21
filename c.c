/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmontese <pmontese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:27:06 by pmontese          #+#    #+#             */
/*   Updated: 2020/01/30 17:19:22 by pmontese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_c(t_format *f)
{
	char	c;
	char	*str1;
	int		chars_put;
	int		len;

	c = (int)f->arg;
	len = f->width > 1 ? f->width - 1 : 0;
	str1 = ft_strnew(len);
	ft_memset(str1, ' ', len);
	if (f->hyphen)
	{
		chars_put = putchar_count(c, 1);
		chars_put += putstr_count(str1, 1);
	}
	else
	{
		chars_put = putstr_count(str1, 1);
		chars_put += putchar_count(c, 1);
	}
	free(str1);
	return (chars_put);
}
