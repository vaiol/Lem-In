/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 18:50:14 by astepano          #+#    #+#             */
/*   Updated: 2017/04/02 18:51:02 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_all.h"

size_t	pf_parse_precision(const char *f, size_t i, t_conversion *form,
		va_list v)
{
	if (f[i] == '.')
	{
		i++;
		form->precision = 0;
		if (ft_isdigit(f[i]))
		{
			form->precision = ft_atoi(f + i);
			while (ft_isdigit(f[i]))
				i++;
		}
		else if (f[i] == '*')
		{
			form->precision = va_arg(v, int);
			i++;
		}
	}
	return (i);
}
