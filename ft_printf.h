/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmontese <pmontese@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:42:59 by pmontese          #+#    #+#             */
/*   Updated: 2020/01/30 20:50:12 by pmontese         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define CONVERTIONS	"cspdiuxX%%"
# define SMALL_BASE16	"0123456789abcdef"
# define BIG_BASE16		"0123456789ABCDEF"

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct	s_format
{
	char		zero;
	char		hyphen;
	char		plus;
	int			width;
	int			precision;
	char		conversion_type;
	void		*arg;
}				t_format;

int				ft_printf(const char *str, ...);
int				parse_conversion(const char *str, va_list ap, t_format *f);
char			*do_flags(t_format *f, char *nbr);

char			*ft_strfill(char sym, size_t len, char *str, size_t prepend);
char			*ulltobase(unsigned long long unbr, size_t base, char *lex);
size_t			ft_lllen(long long nbr);
char			*lltoa(long long n);
char			*get_hex_str(long long nbr, int capital);
int				print_conversion(t_format *f);
int				print_c(t_format *f);
int				print_d(t_format *f);
int				print_p(t_format *f);
int				print_s(t_format *f);
int				print_u(t_format *f);
int				print_x(t_format *f);
int				print_percent(t_format *f);

int				putchar_count(char c, int fd);
int				putstr_count(char *s, int fd);

#endif
