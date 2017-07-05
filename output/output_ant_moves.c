/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_ant_moves.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 15:59:38 by astepano          #+#    #+#             */
/*   Updated: 2017/06/20 15:59:39 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

static int	check_ant(t_info *in, int index)
{
	int	i;

	if (in->ants[index]->move < 0)
		return (0);
	i = 0;
	while (in->ants[i])
	{
		if (i != index && in->ants[i]->way == in->ants[index]->way)
		{
			if (in->ants[i]->move == (in->ants[index]->move + 1))
				return (0);
		}
		i++;
	}
	return (1);
}

static int	print_ants(t_info *in)
{
	int	exist;
	int	way;
	int	i;

	exist = 0;
	i = 0;
	while (in->ants[i])
	{
		if (check_ant(in, i))
		{
			way = in->ants[i]->way;
			exist = 1;
			in->ants[i]->move++;
			if (in->ways[way]->len <= in->ants[i]->move)
				in->ants[i]->move = -1;
		}
		i++;
	}
	return (exist);
}

static void	out1(t_info *in, int **am, int moves)
{
	int	j;
	int	i;

	j = 0;
	while (j < in->ants_count)
	{
		am[j][0] = in->ants[j]->move++;
		j++;
	}
	i = 1;
	while (print_ants(in))
	{
		j = 0;
		while (j < in->ants_count)
		{
			am[j][i] = in->ants[j]->move;
			j++;
		}
		i++;
	}
	output_res(in, moves, am);
}

int			output_ant_moves(t_info *in)
{
	int	**am;
	int	i;
	int	moves;

	moves = 0;
	while (print_ants(in))
		moves++;
	am = (int **)malloc(sizeof(int *) * (in->ants_count));
	i = 0;
	while (i < in->ants_count)
	{
		am[i] = (int *)malloc(sizeof(int) * (moves + 1));
		in->ants[i]->move = 0;
		i++;
	}
	out1(in, am, moves + 1);
	i = 0;
	while (i < in->ants_count)
	{
		in->ants[i]->move = 1;
		free(am[i]);
		i++;
	}
	free(am);
	return (moves);
}
