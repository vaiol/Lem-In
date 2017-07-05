/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 16:45:35 by astepano          #+#    #+#             */
/*   Updated: 2017/06/12 16:45:36 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	link_exist(t_info *in, int room1, int room2)
{
	int	i;

	i = 0;
	while (in->links && in->links[i])
	{
		if (in->links[i]->room1 == room1 && in->links[i]->room2 == room2)
			return (1);
		if (in->links[i]->room1 == room2 && in->links[i]->room2 == room1)
			return (1);
		i++;
	}
	return (0);
}

void		build_matrix(t_info *in)
{
	int	i;
	int	j;

	in->size = 0;
	while (in->rooms && in->rooms[in->size])
		in->size++;
	in->matrix = (int **)malloc(sizeof(int *) * in->size);
	i = 0;
	while (i < in->size)
	{
		in->matrix[i] = (int *)malloc(sizeof(int) * in->size);
		j = 0;
		while (j < in->size)
		{
			in->matrix[i][j] = link_exist(in, i, j);
			j++;
		}
		i++;
	}
}
