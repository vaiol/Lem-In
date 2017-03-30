/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_unsigned.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 21:28:36 by astepano          #+#    #+#             */
/*   Updated: 2017/03/04 21:28:38 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "put_conversion.h"

static char	*get_bx(t_conversion *conv, unsigned long long nbr, int hash, int b)
{
	char	*str;

	str = utoa_base(nbr, b, conv->type, hash);
	str = handle_precision(conv, str, hash, (size_t)hash);
	if (!conv->precision && !nbr)
		str = strclear(str);
	str = handle_minwidth(conv, str, (size_t)hash);
	return (str);
}

static char	*get_ou(t_conversion *conv, unsigned long long nbr, int h, int base)
{
	char	*str;

	str = utoa_base(nbr, base, conv->type, h);
	if (conv->apostrophe)
		str = handle_apostrophe(str);
	str = handle_precision(conv, str, 0, 0);
	if (!conv->precision && !conv->hashtag)
		str = strclear(str);
	str = handle_minwidth(conv, str, 0);
	return (str);
}

/*
** 2005-08-09T18:31:42
*/

static char	*get_time(t_conversion *conv, unsigned long long nbr)
{
	t_time	*timet;
	char	*str;

	timet = handle_time(nbr);
	str = ft_itoa_base(timet->year, 10);
	str = create_time(str, timet->month, "-");
	str = create_time(str, timet->day, "-");
	str = create_time(str, timet->hour, " T");
	str = create_time(str, timet->min, ":");
	str = create_time(str, timet->sec, ":");
	str = handle_precision(conv, str, 0, 0);
	if (!conv->precision && !nbr)
		str = strclear(str);
	str = handle_minwidth(conv, str, 0);
	return (str);
}

void		put_unsigned(t_conversion *conv, unsigned long long number)
{
	char	*nbr;
	int		hash;

	nbr = NULL;
	if (number == 0)
		hash = 0;
	else
		hash = conv->hashtag;
	if (conv->type == 'u')
		nbr = get_ou(conv, number, hash, 10);
	else if (conv->type == 'o')
		nbr = get_ou(conv, number, hash, 8);
	else if (ft_strcchr("xX", conv->type))
		nbr = get_bx(conv, number, hash, 16);
	else if (ft_strcchr("xX", conv->type))
		nbr = get_bx(conv, number, hash, 16);
	else if (conv->type == 'b')
		nbr = get_bx(conv, number, hash, 2);
	else if (conv->type == 'k')
		nbr = get_time(conv, number);
	putstr(nbr);
	free(nbr);
}
