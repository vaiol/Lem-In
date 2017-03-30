/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 20:46:37 by astepano          #+#    #+#             */
/*   Updated: 2017/03/14 20:46:39 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"

static void	handle_f2(int *p, t_arrays *a, t_bufs *bufs)
{
	char	*s;

	s = fmt_unsigned(*(a->d), bufs->buf + 9);
	while (s > bufs->buf)
		*--s = '0';
	out(&(a->copy), s, (size_t)MIN(9, *p));
	a->d++;
	*p -= 9;
}

void		handle_f(t_arrays *a, int p, t_bufs *bufs, int hash)
{
	char	*s;

	if (a->a > a->r)
		a->a = a->r;
	a->d = a->a;
	while (a->d <= a->r)
	{
		s = fmt_unsigned(*(a->d), bufs->buf + 9);
		if (a->d != a->a)
		{
			while (s > bufs->buf)
				*--s = '0';
		}
		else if (s == bufs->buf + 9)
			*--s = '0';
		out(&(a->copy), s, bufs->buf + 9 - s);
		a->d++;
	}
	if (p || hash)
		out(&(a->copy), ".", 1);
	while (a->d < a->z && p > 0)
		handle_f2(&p, a, bufs);
	pad(&(a->copy), '0', p + 9, 9);
}
