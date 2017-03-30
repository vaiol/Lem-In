/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_printed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 19:52:55 by astepano          #+#    #+#             */
/*   Updated: 2017/03/10 19:52:57 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "put_conversion.h"

void	put_printed(t_conversion *conv, va_list valist)
{
	void	*n;

	n = va_arg(valist, void *);
	if (conv->size == N)
		*((int *)n) = printed_count();
	else if (conv->size == HH)
		*((char *)n) = (char)printed_count();
	else if (conv->size == H)
		*((short *)n) = (short)printed_count();
	else if (conv->size == L)
		*((long *)n) = printed_count();
	else if (conv->size == LL)
		*((long long *)n) = printed_count();
	else if (conv->size == Z)
		*((ssize_t *)n) = printed_count();
	else if (conv->size == J)
		*((intmax_t *)n) = printed_count();
}
