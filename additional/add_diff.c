/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_diff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 16:31:33 by astepano          #+#    #+#             */
/*   Updated: 2017/06/20 16:31:34 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

static t_diff	*create_diff(int *arr, int maxlen)
{
	t_diff	*diff;
	int		i;

	diff = (t_diff *)malloc(sizeof(t_diff));
	diff->ways = (int *)malloc(sizeof(int) * maxlen);
	diff->len = maxlen;
	i = 0;
	while (i < diff->len)
	{
		diff->ways[i] = arr[i];
		i++;
	}
	return (diff);
}

int				add_diff(t_info *in, int *arr, int maxlen)
{
	t_diff	**diffs;
	int		i;
	int		len;

	len = 0;
	while (in->diffs && in->diffs[len])
		len++;
	diffs = (t_diff **)malloc(sizeof(t_diff *) * (len + 2));
	i = 0;
	while (i < len)
	{
		diffs[i] = in->diffs[i];
		i++;
	}
	diffs[i] = create_diff(arr, maxlen);
	diffs[i + 1] = NULL;
	if (in->diffs)
		free(in->diffs);
	in->diffs = diffs;
	return (i);
}
