/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_minwidth.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 21:14:50 by astepano          #+#    #+#             */
/*   Updated: 2017/03/04 21:14:51 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_all.h"

size_t	parse_minwidth(const char *f, size_t i, t_conversion *form, va_list v)
{
	if (ft_isdigit(f[i]))
	{
		form->minimum_width = ft_atoi(f + i);
		while (ft_isdigit(f[i]))
			i++;
	}
	else if (f[i] == '*')
	{
		form->minimum_width = va_arg(v, int);
		if (form->minimum_width < 0)
		{
			form->minimum_width = -form->minimum_width;
			form->padding = '-';
		}
		i++;
	}
	return (i);
}
