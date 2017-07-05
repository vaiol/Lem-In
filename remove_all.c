/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 16:43:51 by astepano          #+#    #+#             */
/*   Updated: 2017/06/12 16:43:53 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	remove_next_next(t_info *in)
{
	int	i;

	i = 0;
	while (in->diffs && in->diffs[i])
	{
		free(in->diffs[i]->ways);
		free(in->diffs[i++]);
	}
	if (in->diffs)
		free(in->diffs);
}

static void	remove_next(t_info *in)
{
	int	i;

	i = 0;
	while (in->matrix && i < in->size)
		free(in->matrix[i++]);
	if (in->matrix)
		free(in->matrix);
	i = 0;
	while (in->all_ways && in->all_ways[i])
	{
		free(in->all_ways[i]->way);
		free(in->all_ways[i++]);
	}
	if (in->all_ways)
		free(in->all_ways);
	if (in->ways)
		free(in->ways);
	i = 0;
	while (in->ants && in->ants[i])
		free(in->ants[i++]);
	if (in->ants)
		free(in->ants);
	remove_next_next(in);
}

int			remove_all(t_info *in)
{
	int i;

	i = 0;
	while (in->rooms && in->rooms[i])
	{
		free(in->rooms[i]->name);
		free(in->rooms[i++]);
	}
	if (in->rooms)
		free(in->rooms);
	i = 0;
	while (in->links && in->links[i])
		free(in->links[i++]);
	if (in->links)
		free(in->links);
	if (in->input)
		free(in->input);
	remove_next(in);
	free(in);
	return (0);
}
