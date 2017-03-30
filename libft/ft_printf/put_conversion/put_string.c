/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 21:28:29 by astepano          #+#    #+#             */
/*   Updated: 2017/03/04 21:28:31 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "put_conversion.h"

void		put_string(t_conversion *conv, va_list valist)
{
	char	*str;

	if (conv->size == L)
		str = wstrtostr(va_arg(valist, wchar_t *), conv->precision);
	else
	{
		if (!(str = va_arg(valist, char *)))
			str = ft_strdup("(null)");
		else
			str = ft_strdup(str);
	}
	str = ft_strcut(str, conv->precision);
	conv->precision = -1;
	str = handle_minwidth(conv, str, 0);
	putstr(str);
	free(str);
}
