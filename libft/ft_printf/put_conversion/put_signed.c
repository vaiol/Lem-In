/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_signed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 21:28:21 by astepano          #+#    #+#             */
/*   Updated: 2017/03/10 17:31:25 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "put_conversion.h"

void		put_signed(t_conversion *conv, long long number)
{
	size_t	margin;
	char	*nbr;

	margin = (size_t)(conv->sign || number < 0);
	nbr = ft_itoa_base(number, 10);
	if (conv->sign && number >= 0)
		nbr = strjoinchr(nbr, conv->sign, 1, BEGIN);
	if (conv->apostrophe)
		nbr = handle_apostrophe(nbr);
	nbr = handle_precision(conv, nbr, (int)margin, margin);
	if (!conv->precision && !number)
		nbr = strclear(nbr);
	nbr = handle_minwidth(conv, nbr, margin);
	putstr(nbr);
	free(nbr);
}
