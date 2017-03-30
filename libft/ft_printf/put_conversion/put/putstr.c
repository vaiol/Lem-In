/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:42:50 by astepano          #+#    #+#             */
/*   Updated: 2017/03/10 17:42:51 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "put.h"

void	putstr(char const *s)
{
	size_t size;

	size = 0;
	while (s[size])
		size++;
	ft_write(s, size);
}
