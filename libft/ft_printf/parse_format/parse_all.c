/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 21:14:20 by astepano          #+#    #+#             */
/*   Updated: 2017/03/10 17:29:12 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_all.h"

static t_conversion	*create_conversion(void)
{
	t_conversion	*conversion;

	conversion = (t_conversion *)malloc(sizeof(t_conversion));
	conversion->precision = -1;
	conversion->minimum_width = 0;
	conversion->hashtag = 0;
	conversion->apostrophe = 0;
	conversion->padding = '\0';
	conversion->sign = '\0';
	conversion->type = '\0';
	conversion->size = N;
	conversion->ldouble = '\0';
	return (conversion);
}

size_t				parse(const char *f, size_t i, va_list valist)
{
	size_t			tmp;
	t_conversion	*form;

	if (f[i - 1] == '{')
		return (parse_brace(f, i, valist));
	form = create_conversion();
	tmp = 0;
	while (f[i] && tmp != i)
	{
		tmp = i;
		i = parse_flags(f, i, form);
		i = parse_minwidth(f, i, form, valist);
		i = parse_precision(f, i, form, valist);
		i = parse_size(f, i, form);
	}
	if (f[i])
	{
		i = parse_type(f, i, form);
		put_conversion(form, valist);
	}
	free(form);
	return (i);
}
