/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_result.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 16:43:26 by astepano          #+#    #+#             */
/*   Updated: 2017/06/12 16:57:11 by astepano         ###   ########.fr       */
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
	int move;
	int	i;

	exist = 0;
	i = 0;
	while (in->ants[i])
	{
		if (check_ant(in, i))
		{
			if (exist > 0)
				ft_printf(" ");
			way = in->ants[i]->way;
			move = in->ants[i]->move;
			ft_printf("L%d-%s", in->ants[i]->name,
					in->rooms[in->ways[way]->way[move]]->name);
			exist = 1;
			in->ants[i]->move++;
			if (in->ways[way]->len <= in->ants[i]->move)
				in->ants[i]->move = -1;
		}
		i++;
	}
	return (exist);
}

void		output_result(t_info *in, int last, char **file)
{
	int	moves;

	output_file(in, file, last);
	if (last == 0)
		return ;
	if (in->put_all_ways)
		output_all_ways(in);
	else if (in->put_ways)
		output_ways(in);
	if (in->put_map)
		visu_put_map(in);
	if (in->put_ant_moves)
		moves = output_ant_moves(in);
	else
	{
		moves = 0;
		while (print_ants(in))
		{
			ft_printf("\n");
			moves++;
		}
	}
	if (in->put_moves)
		ft_printf("\n{green}MOVES: %d{eoc}\n", moves);
}
