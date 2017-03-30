/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_unprintable.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 19:21:32 by astepano          #+#    #+#             */
/*   Updated: 2017/03/20 19:21:34 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "put_conversion.h"

char		*add_str(char *s1, size_t index, char *s2)
{
	char	*result;
	size_t	i;
	size_t	j;

	result = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	i = -1;
	j = 0;
	while (++i < index)
		result[i] = s1[i];
	while (s2[j])
	{
		result[i + j] = s2[j];
		j++;
	}
	j = i + j;
	i++;
	while (s1[i])
	{
		result[j] = s1[i];
		i++;
		j++;
	}
	result[j] = '\0';
	return (result);
}

char		*add_unprintable(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (ft_isprint(str[i]))
		{
			i++;
			continue ;
		}
		else if (str[i] == '\t')
			str = add_str(str, i, "\\t");
		else if (str[i] == '\n')
			str = add_str(str, i, "\\n");
		else if (str[i] == '\v')
			str = add_str(str, i, "\\v");
		else if (str[i] == '\f')
			str = add_str(str, i, "\\f");
		else if (str[i] == '\r')
			str = add_str(str, i, "\\r");
		else
			str = add_str(str, i, utoa_base((unsigned)str[i], 16, 'x', 1));
		i = 0;
	}
	return (str);
}

void		put_unprintable(t_conversion *conv, va_list valist)
{
	char	*str;

	str = ft_strdup(va_arg(valist, char *));
	str = add_unprintable(str);
	str = ft_strcut(str, conv->precision);
	conv->precision = -1;
	str = handle_minwidth(conv, str, 0);
	putstr(str);
	free(str);
}
