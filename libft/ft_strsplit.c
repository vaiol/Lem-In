/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 12:13:13 by astepano          #+#    #+#             */
/*   Updated: 2016/12/17 14:03:44 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words_count(const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	count;

	if (!s)
		return (0);
	count = 0;
	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i + j] && s[i + j] != c)
			j++;
		if (j > 0)
		{
			count++;
			i = i + j - 1;
		}
		i++;
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**result;

	if (!s)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * ft_words_count(s, c) + 1);
	if (!result)
		return (NULL);
	i = 0;
	k = 0;
	while (s[i])
	{
		j = 0;
		while (s[i + j] && s[i + j] != c)
			j++;
		if (j > 0)
			result[k++] = ft_strsub(s, i--, j);
		i += j + 1;
	}
	result[k] = NULL;
	return (result);
}
