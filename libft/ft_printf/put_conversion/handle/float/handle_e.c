/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_e.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 20:46:31 by astepano          #+#    #+#             */
/*   Updated: 2017/03/14 20:46:33 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"

static void	handle_e2(t_arrays *a, t_bufs *bufs, t_conversion *c)
{
	char	*s;

	s = fmt_unsigned(*(a->d), bufs->buf + 9);
	if (s == bufs->buf + 9)
		*(--s) = '0';
	if (a->d != a->a)
	{
		while (s > bufs->buf)
			*(--s) = '0';
	}
	else
	{
		out(&(a->copy), s++, 1);
		if (c->precision > 0 || c->hashtag)
			out(&(a->copy), ".", 1);
	}
	out(&(a->copy), s, MIN(bufs->buf + 9 - s, c->precision));
	c->precision -= bufs->buf + 9 - s;
	a->d++;
}

void		handle_e(t_arrays *a, char *es, t_bufs *bufs, t_conversion *c)
{
	if (a->z <= a->a)
		a->z = a->a + 1;
	a->d = a->a;
	while (a->d < a->z && c->precision >= 0)
		handle_e2(a, bufs, c);
	pad(&(a->copy), '0', c->precision + 18, 18);
	out(&(a->copy), es, bufs->ebuf - es);
}
