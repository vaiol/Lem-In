/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:38:13 by astepano          #+#    #+#             */
/*   Updated: 2017/03/10 17:40:02 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "handle.h"

char	*handle_precision(t_conversion *c, char *str, int l, size_t m)
{
	int	count;

	count = c->precision - ((int)ft_strlen(str) - l);
	if (count > 0)
		str = strjoinchr_begin(str, '0', count, m);
	return (str);
}
