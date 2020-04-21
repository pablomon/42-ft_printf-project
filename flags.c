/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmontese <pmontese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:30:16 by pmontese          #+#    #+#             */
/*   Updated: 2020/01/30 20:53:20 by pmontese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*put_prefix(t_format *f, char *nbr)
{
	char	*prefix;

	if (f->conversion_type == 'p')
		prefix = ft_strdup("0x");
	else if (*nbr == '-')
		prefix = ft_strdup("-");
	else if (f->plus && f->conversion_type != 'u')
		prefix = ft_strdup("+");
	else
		prefix = ft_strdup("");
	return (prefix);
}

size_t	to_size_t(int nbr)
{
	if (nbr < 0)
		return (0);
	return (nbr);
}

char	*do_flags(t_format *f, char *nbr)
{
	int		is_negative;
	char	*prefix;
	char	*str1;
	char	*str2;

	str1 = NULL;
	prefix = put_prefix(f, nbr);
	is_negative = *nbr == '-' ? 1 : 0;
	if (is_negative)
		nbr++;
	if (f->precision > -1)
		str1 = ft_strfill('0', f->precision, nbr, 1);
	else if (f->zero == 1 && !f->hyphen)
		str1 = ft_strfill('0', to_size_t(f->width - ft_strlen(prefix)), nbr, 1);
	else
		str1 = ft_strdup(nbr);
	str2 = ft_strjoin(prefix, str1);
	free(prefix);
	free(str1);
	if (f->hyphen)
		str1 = ft_strfill(' ', f->width, str2, 0);
	else
		str1 = ft_strfill(' ', f->width, str2, 1);
	free(str2);
	return (str1);
}
