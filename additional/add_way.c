/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_way.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 16:31:51 by astepano          #+#    #+#             */
/*   Updated: 2017/06/20 16:31:52 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

static int	put_way(t_info *in, int *new_way, int dist)
{
	t_way	**ways;
	int		i;
	int		len;

	len = 0;
	while (in->ways && in->ways[len])
		len++;
	ways = (t_way **)malloc(sizeof(t_way *) * (len + 2));
	i = 0;
	while (i < len)
	{
		ways[i] = in->ways[i];
		i++;
	}
	ways[i] = (t_way *)malloc(sizeof(t_way));
	ways[i]->way = new_way;
	ways[i]->len = dist;
	ways[i]->ants = 0;
	ways[i + 1] = NULL;
	if (in->ways)
		free(in->ways);
	in->ways = ways;
	return (i);
}

int			add_way(t_info *in, int *way, int len)
{
	int *new_way;
	int	i;

	new_way = (int *)malloc(sizeof(int) * (len));
	i = 0;
	while (i < len)
	{
		new_way[i] = way[i];
		i++;
	}
	return (put_way(in, new_way, len));
}
