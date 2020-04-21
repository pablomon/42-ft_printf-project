/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmontese <pmontese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:28:43 by pmontese          #+#    #+#             */
/*   Updated: 2020/01/30 17:34:10 by pmontese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_percent(t_format *f)
{
	char			*str1;
	int				chars_put;

	str1 = do_flags(f, "%");
	chars_put = putstr_count(str1, 1);
	free(str1);
	return (chars_put);
}
