/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additionals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 20:46:02 by astepano          #+#    #+#             */
/*   Updated: 2017/03/14 20:46:03 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"

void	out(char **sp, const char *s, size_t l)
{
	while (l--)
	{
		**sp = *s;
		(*sp)++;
		s++;
	}
}

void	pad(char **sp, char c, int w, int l)
{
	char pad[FLOAT_SIZE];

	if (l >= w)
		return ;
	l = w - l;
	ft_memset(pad, c, l > (int)sizeof(pad) ? sizeof(pad) : (size_t)l);
	while (l >= (int)sizeof(pad))
	{
		out(sp, pad, sizeof(pad));
		l -= (int)sizeof(pad);
	}
	out(sp, pad, (size_t)l);
}

char	*fmt_unsigned(uintmax_t x, char *s)
{
	unsigned long	y;

	while (x > ULONG_MAX)
	{
		*(--s) = (char)('0' + x % 10);
		x /= 10;
	}
	y = x;
	while (y)
	{
		*(--s) = (char)('0' + y % 10);
		y /= 10;
	}
	return (s);
}

int		infinite(long double nbr, int t, char *copy, t_indecies *i)
{
	char	*s;

	if (nbr == INFINITY || nbr != nbr)
	{
		s = (t & 32) ? "inf\0" : "INF\0";
		if (nbr != nbr)
		{
			s = (t & 32) ? "nan\0" : "NAN\0";
			i->pl = 0;
		}
		out(&copy, i->prefix, (size_t)i->pl);
		out(&copy, s, 4);
		return (1);
	}
	return (0);
}

char	*infin(long double nbr, t_conversion *c, int sign)
{
	char	*result;
	char	*s;

	s = (c->type == 'x') ? ft_strdup("inf") : ft_strdup("INF");
	if (nbr != nbr)
		s = (c->type == 'x') ? ft_strdup("nan") : ft_strdup("NAN");
	c->type -= ('x' - 'a');
	if (sign)
	{
		result = ft_strjoin("-", s);
		free(s);
		return (result);
	}
	return (s);
}
