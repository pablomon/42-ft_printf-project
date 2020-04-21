/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmontese <pmontese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:57:28 by pmontese          #+#    #+#             */
/*   Updated: 2020/01/28 20:09:06 by pmontese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_lllen(long long nbr)
{
	int					len;
	unsigned long long	unbr;

	len = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		unbr = -nbr;
		len++;
	}
	else
		unbr = nbr;
	while (unbr != 0)
	{
		unbr = unbr / 10;
		len++;
	}
	return (len);
}

char	*lltoa(long long n)
{
	char	*str;
	int		len;

	len = ft_lllen(n);
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[len] = 0;
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n != 0 && len >= 0)
	{
		str[len-- - 1] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

char	*ulltobase(unsigned long long unbr, size_t base, char *base_lex)
{
	char	str[64];
	size_t	i;

	ft_memset(str, '\0', 64);
	i = 0;
	while (unbr / base > 0)
	{
		str[i] = base_lex[unbr % base];
		i++;
		unbr = unbr / base;
	}
	str[i] = base_lex[unbr % base];
	ft_rev_str(str);
	return (ft_strdup(str));
}

char	*ft_strfill(char symbol, size_t length, char *str, size_t prepend)
{
	size_t	size;
	char	*fill;
	char	*filled;

	size = ft_strlen(str);
	if (size >= length)
		return (ft_strdup(str));
	if (!(fill = (char*)malloc(sizeof(char) * (length - size + 1))))
		return (NULL);
	fill[length - size] = 0;
	ft_memset(fill, symbol, length - size);
	if (prepend)
		filled = ft_strjoin(fill, str);
	else
		filled = ft_strjoin(str, fill);
	free(fill);
	return (filled);
}

char	*get_hex_str(long long nbr, int capital)
{
	unsigned long long	unbr;
	char				*base;
	char				*str;

	if (nbr < -2147483648)
		unbr = 2147483648;
	else if (nbr < 0)
		unbr = -nbr;
	else
		unbr = nbr;
	base = capital ? BIG_BASE16 : SMALL_BASE16;
	str = ulltobase(unbr, 16, base);
	return (str);
}
