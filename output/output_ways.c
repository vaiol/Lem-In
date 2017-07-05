/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_ways.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 16:43:21 by astepano          #+#    #+#             */
/*   Updated: 2017/06/12 16:43:22 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

static void	out_ants_eoc(t_way *way, t_info *in)
{
	if (way->ants && in->put_ants)
		ft_printf("{yellow} | ANTS: %d{eoc}\n", way->ants);
	else
		ft_printf("{eoc}\n");
}

void		output_ways(t_info *in)
{
	int	j;
	int	i;

	i = 0;
	ft_printf("{red}SELECTED WAYS:{eoc}\n");
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
			ft_printf("%s", in->rooms[in->ways[i]->way[j]]->name);
			j++;
		}
		out_ants_eoc(in->ways[i], in);
		i++;
	}
	ft_printf("\n");
}
