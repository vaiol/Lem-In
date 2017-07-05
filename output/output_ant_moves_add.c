/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_ant_moves_add.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 16:01:13 by astepano          #+#    #+#             */
/*   Updated: 2017/06/20 16:01:14 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

static void	out1(t_info *in, int moves, int **am, int i)
{
	int way;
	int	j;
	int	m;

	way = in->ants[i]->way;
	ft_printf("L%-5d| ", in->ants[i]->name);
	j = 0;
	while (j < moves)
	{
		if (am[i][j] == 0)
			m = am[i][j];
		else
			m = am[i][j] - 1;
		if (m < 0)
			m = in->ways[way]->len - 1;
		if (m == 0)
			ft_printf("{green}");
		else if (m == in->ways[way]->len - 1)
			ft_printf("{red}");
		ft_printf("%3s%2s{eoc}", in->rooms[in->ways[way]->way[m]]->name, " ");
		j++;
	}
	ft_printf("\n");
}

void		output_res(t_info *in, int moves, int **am)
{
	int	i;

	ft_printf("MOVES | ");
	i = 0;
	while (i < moves)
	{
		ft_printf("%3d%2s", i, " ");
		i++;
	}
	ft_printf("\n------|-");
	i = 0;
	while (i < moves)
	{
		ft_printf("%.5s", "----------------------------------------");
		i++;
	}
	ft_printf("\n");
	i = 0;
	while (i < in->ants_count)
	{
		out1(in, moves, am, i);
		i++;
	}
}
