/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_all_ways.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 16:45:12 by astepano          #+#    #+#             */
/*   Updated: 2017/06/12 17:01:09 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	check(int *arr, int index, int room)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (room == arr[i])
			return (0);
		i++;
	}
	return (1);
}

static void	recursion(t_info *in, int *arr, int ind, int room)
{
	int	i;

	arr[ind] = room;
	if (room == in->end)
	{
		add_way(in, arr, ind + 1);
		return ;
	}
	i = 0;
	while (i < in->size)
	{
		if (in->matrix[i][room] && check(arr, ind, i))
			recursion(in, arr, ind + 1, i);
		i++;
	}
}

static void	find_straight_path(t_info *in)
{
	int	j;
	int	i;

	i = 0;
	while (in->ways[i])
	{
		if (in->ways[i]->len == 2)
		{
			j = 0;
			while (in->ways[j])
			{
				if (i != j)
				{
					free(in->ways[j]->way);
					free(in->ways[j]);
				}
				j++;
			}
			in->ways[0] = in->ways[i];
			in->ways[1] = NULL;
			break ;
		}
		i++;
	}
}

int			find_all_ways(t_info *in, int last)
{
	int	i;
	int	*arr;

	if (last == 0 || in->end == -1 || in->start == -1)
		return (0);
	i = 0;
	while (in->rooms[i])
		i++;
	arr = (int *)malloc(sizeof(int) * i);
	build_matrix(in);
	recursion(in, arr, 0, in->start);
	free(arr);
	if (in->ways == NULL)
		return (0);
	find_straight_path(in);
	return (last);
}
