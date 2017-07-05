/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 16:45:20 by astepano          #+#    #+#             */
/*   Updated: 2017/06/12 16:45:21 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	get_bestway(t_info *in)
{
	int best;
	int	min;
	int	i;

	i = 0;
	best = i;
	min = in->ways[i]->len + in->ways[i]->ants;
	while (in->ways[i])
	{
		if (min > (in->ways[i]->len + in->ways[i]->ants))
		{
			best = i;
			min = in->ways[i]->len + in->ways[i]->ants;
		}
		i++;
	}
	return (best);
}

static void	get_ants(t_info *in)
{
	int	i;
	int	j;

	in->ants = (t_ant **)malloc(sizeof(t_ant *) * (in->ants_count + 1));
	i = 0;
	while (i < in->ants_count)
	{
		j = 0;
		while (in->ways[j])
		{
			if (in->ways[j]->ants > 0 && i < in->ants_count)
			{
				in->ants[i] = (t_ant *)malloc(sizeof(t_ant));
				in->ants[i]->move = 1;
				in->ants[i]->name = i + 1;
				in->ants[i]->way = j;
				in->ways[j]->ants--;
				i++;
			}
			j++;
		}
	}
	in->ants[i] = NULL;
}

void		create_ants(t_info *in, int last)
{
	int	i;

	if (last == 0)
		return ;
	i = 0;
	while (i++ < in->ants_count)
		in->ways[get_bestway(in)]->ants++;
	get_ants(in);
	i = 0;
	while (in->ways[i])
	{
		in->ways[i]->ants = 0;
		i++;
	}
	i = 0;
	while (i++ < in->ants_count)
		in->ways[get_bestway(in)]->ants++;
}
