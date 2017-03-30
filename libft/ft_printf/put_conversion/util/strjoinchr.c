/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoinchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:44:05 by astepano          #+#    #+#             */
/*   Updated: 2017/03/10 17:44:06 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

char	*strjoinchr(char *str, char const chr, int count, t_position position)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (!str)
		return (0);
	result = (char *)malloc(sizeof(char) * (ft_strlen(str) + count + 1));
	if (!result)
		return (0);
	j = 0;
	if (position == BEGIN)
	{
		while ((count--) > 0)
			result[j++] = chr;
	}
	i = 0;
	while (str[i])
		result[j++] = str[i++];
	while ((count--) > 0)
		result[j++] = chr;
	result[j] = '\0';
	free(str);
	return (result);
}
