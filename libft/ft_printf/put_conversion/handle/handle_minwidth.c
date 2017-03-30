/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_minwidth.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:38:05 by astepano          #+#    #+#             */
/*   Updated: 2017/03/10 17:38:06 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle.h"

static int	inan(t_conversion *conv, char *str)
{
	if (!ft_strcchr("aAfFgGeE", (char)conv->type))
		return (1);
	if (ft_isdigit(str[0]) || ft_isdigit(str[1]))
		return (1);
	return (0);
}

char		*handle_minwidth(t_conversion *conv, char *str, size_t margin)
{
	int	count;

	count = conv->minimum_width - (int)ft_strlen(str);
	if (count > 0)
	{
		if (conv->padding == '-')
			str = strjoinchr(str, ' ', count, END);
		else if (conv->padding == '0' && conv->precision < 0 && inan(conv, str))
			str = strjoinchr_begin(str, '0', count, margin);
		else
			str = strjoinchr(str, ' ', count, BEGIN);
	}
	return (str);
}
