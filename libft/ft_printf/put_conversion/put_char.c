/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 21:27:17 by astepano          #+#    #+#             */
/*   Updated: 2017/03/04 21:27:18 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "put_conversion.h"

void		put_char(t_conversion *conv, va_list valist)
{
	int		char_len;
	int		count;
	char	chr;

	char_len = 1;
	if (conv->type != 'c')
		chr = conv->type;
	else if (conv->size == L)
		chr = (char)va_arg(valist, wint_t);
	else
		chr = va_arg(valist, int);
	count = conv->minimum_width - char_len;
	if (count > 0)
	{
		if (conv->padding == '-')
			ft_write(&chr, (size_t)char_len--);
		while (count--)
		{
			if (conv->padding == '0')
				ft_write("0", 1);
			else
				ft_write(" ", 1);
		}
	}
	ft_write(&chr, (size_t)char_len);
}
