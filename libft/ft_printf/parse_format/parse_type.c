/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 19:26:25 by astepano          #+#    #+#             */
/*   Updated: 2017/03/07 19:26:27 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_all.h"

size_t		parse_type(const char *f, size_t i, t_conversion *form)
{
	if (ft_strcchr("SDOUC", f[i]))
	{
		form->size = L;
		form->type = (char)ft_tolower(f[i]);
	}
	else
		form->type = f[i];
	return (i + 1);
}
