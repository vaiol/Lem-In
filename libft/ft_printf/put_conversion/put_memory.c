/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_memory.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 19:28:43 by astepano          #+#    #+#             */
/*   Updated: 2017/03/10 17:31:58 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "put_conversion.h"

void	put_memory(t_conversion *conv, va_list valist)
{
	char				*str;
	unsigned long long	memory;

	memory = (unsigned long long)va_arg(valist, void *);
	conv->type = 'x';
	conv->hashtag = 2;
	str = utoa_base(memory, 16, conv->type, conv->hashtag);
	str = handle_precision(conv, str, conv->hashtag, (size_t)conv->hashtag);
	if (!conv->precision && !memory)
		str = ft_strcut(str, 2);
	str = handle_minwidth(conv, str, (size_t)conv->hashtag);
	putstr(str);
	free(str);
}
