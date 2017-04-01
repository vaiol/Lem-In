/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 01:43:33 by astepano          #+#    #+#             */
/*   Updated: 2017/04/02 01:43:35 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	remove_next(t_info *in)
{
	int	i;

	i = 0;
	while (in->matrix && i < in->size)
		free(in->matrix[i++]);
	if (in->matrix)
		free(in->matrix);
	i = 0;
	while (in->ways && in->ways[i])
	{
		free(in->ways[i]->way);
		free(in->ways[i++]);
	}
	if (in->ways)
		free(in->ways);
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

void		remove_additional(int *paste, int *distance, int *way)
{
	free(paste);
	free(distance);
	free(way);
}
