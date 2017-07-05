/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_diffs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 16:45:01 by astepano          #+#    #+#             */
/*   Updated: 2017/06/12 16:45:02 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	is_parallel(t_info *in, int w1, int w2)
{
	int i;
	int	j;
	int	r;

	i = 0;
	while (i < in->ways[w1]->len)
	{
		j = 0;
		while (j < in->ways[w2]->len)
		{
			r = in->ways[w1]->way[i];
			if (r == in->ways[w2]->way[j] && r != in->end && r != in->start)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	is_parallel_ways(t_info *in, int *arr, int len, int way)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (arr[i] == way || !is_parallel(in, arr[i], way))
			return (0);
		i++;
	}
	return (1);
}

static void	recursion(t_info *in, int *arr, int len, int way)
{
	int	flag;
	int	i;

	arr[len++] = way;
	flag = 1;
	i = 0;
	while (in->ways[i])
	{
		if (is_parallel_ways(in, arr, len, i))
		{
			recursion(in, arr, len, i);
			flag = 0;
		}
		i++;
	}
	if (flag)
		add_diff(in, arr, len);
}

void		find_diffs(t_info *in, int last)
{
	int	i;
	int	*arr;

	if (last == 0)
		return ;
	i = 0;
	while (in->ways[i])
		i++;
	arr = (int *)malloc(sizeof(int) * i);
	i = 0;
	while (in->ways[i])
	{
		recursion(in, arr, 0, i);
		i++;
	}
	free(arr);
}
