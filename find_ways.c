/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_ways.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 01:43:42 by astepano          #+#    #+#             */
/*   Updated: 2017/04/02 01:43:44 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_hex.h"

static int	djkstr_find(t_info *in, int *distance, int *past)
{
	int	i;
	int	v;
	int w;

	w = INFINITY;
	v = -1;
	i = 0;
	while (i < in->size)
	{
		if (past[i] == 0 && distance[i] < w)
		{
			v = i;
			w = distance[i];
		}
		i++;
	}
	return (v);
}

static int	djkstr_find_way(t_info *in, int *dist, int *past, int *way)
{
	int	i;
	int	v;

	v = in->start;
	while (v >= 0 && v != in->end)
	{
		i = 0;
		while (i < in->size)
		{
			if (in->matrix[v][i] == 1
				&& (past[i] == 0 && dist[i] > dist[v] + in->matrix[v][i]))
			{
				dist[i] = dist[v] + in->matrix[v][i];
				way[i] = v;
			}
			i++;
		}
		v = djkstr_find(in, dist, past);
		if (v >= 0)
			past[v] = 1;
	}
	return (v);
}

static int	djkstr_way(t_info *in, int *paste, int *distance, int *way)
{
	int	i;

	i = 0;
	while (i < in->size)
	{
		distance[i] = INFINITY;
		paste[i] = 0;
		i++;
	}
	way[in->start] = 0;
	distance[in->start] = 0;
	paste[in->start] = 1;
	return (djkstr_find_way(in, distance, paste, way));
}

static int	djkstr_shortest(t_info *in)
{
	int v;
	int	i;
	int *paste;
	int *distance;
	int *way;

	paste = (int *)malloc(sizeof(int) * in->size);
	distance = (int *)malloc(sizeof(int) * in->size);
	way = (int *)malloc(sizeof(int) * in->size);
	v = djkstr_way(in, paste, distance, way);
	if (v < 0)
	{
		remove_additional(paste, distance, way);
		return (-1);
	}
	i = add_way(in, way, distance[in->end] + 1);
	remove_additional(paste, distance, way);
	return (i);
}

int			find_ways(t_info *in, int last)
{
	int	exist;
	int	way;

	build_matrix(in);
	exist = 0;
	while ((way = djkstr_shortest(in)) >= 0)
	{
		exist = last;
		if (in->ways[way]->len == 2)
			break ;
		remove_vertices(in, way);
	}
	return (exist);
}
