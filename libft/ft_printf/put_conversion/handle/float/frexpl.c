/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frexpl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 20:46:25 by astepano          #+#    #+#             */
/*   Updated: 2017/03/14 20:46:27 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"

/*
** re-writen original frexpl function from math.h
*/

long double	ft_frexpl(long double value, int *e)
{
	int			exponent;

	if (value == 0.0 || value == -0.0)
	{
		*e = 0;
		return (value);
	}
	exponent = 0;
	while (value < 0.5)
	{
		value *= 2.0;
		exponent--;
	}
	while (value >= 1.0)
	{
		value *= 0.5;
		exponent++;
	}
	*e = exponent;
	return (value);
}
