/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 01:42:59 by astepano          #+#    #+#             */
/*   Updated: 2017/04/02 01:43:00 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	output_ways(t_info *in)
{
	int	j;
	int	i;

	i = 0;
	ft_printf("\n{red}ALL WAYS:{eoc}\n");
	while (in->ways && in->ways[i])
	{
		if (in->ways[i]->ants)
			ft_printf("{green}");
		else
			ft_printf("{red}");
		ft_printf("%d: ", i + 1);
		j = 0;
		while (j < in->ways[i]->len)
		{
			if (j > 0)
				ft_printf("->");
			ft_printf("%d", in->ways[i]->way[j]);
			j++;
		}
		ft_printf("{eoc}\n");
		i++;
	}
	ft_printf("\n");
}

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
	int	i;

	i = 0;
	exist = 0;
	while (i < in->ants_count)
	{
		if (check_ant(in, i))
		{
			if (exist > 0)
				ft_printf(" ");
			in->ants[i]->move++;
			if (in->ways[in->ants[i]->way]->len <= in->ants[i]->move)
			{
				in->ants[i]->move = -1;
				continue ;
			}
			ft_printf("L%d-%s", in->ants[i]->name,
					  in->rooms[in->ways[in->ants[i]->way]->way[in->ants[i]->move]]->name);
			exist = 1;
		}
		i++;
	}
	ft_printf("\n");
	return (exist);
}

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

static void	create_ants(t_info *in)
{
	int	i;

	in->ants = (t_ant **)malloc(sizeof(t_ant *) * (in->ants_count + 1));
	i = 0;
	while (i < in->ants_count)
	{
		in->ants[i] = (t_ant *)malloc(sizeof(t_ant));
		in->ants[i]->move = 0;
		in->ants[i]->name = i + 1;
		in->ants[i]->way = get_bestway(in);
		in->ways[in->ants[i]->way]->ants++;
		i++;
	}
	in->ants[i] = NULL;
}

void		print_result(t_info *in, int last)
{
	int	moves;

	if (last == 0)
		return ;
	create_ants(in);
	output_ways(in);
	moves = 0;
	while (print_ants(in))
		moves++;
	ft_printf("{green}MOVES: %d{eoc}\n", moves);
}

int		main(void)
{
	t_info	*in;
	char	**file;
	int		l;

	file = read_file();
	in = create_info(file);
	l = parse_input(in);
	l = find_ways(in, l);
	write_file(file, l);
	print_result(in, l);
	remove_all(in);
	return (0);
}
