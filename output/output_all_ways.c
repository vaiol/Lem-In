/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_all_ways.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 16:43:14 by astepano          #+#    #+#             */
/*   Updated: 2017/06/12 16:43:15 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

static void	sort_all_ways(t_way **ways)
{
	size_t	i;
	size_t	j;
	size_t	len;
	t_way	*tmp;

	len = 0;
	while (ways[len])
		len++;
	i = 0;
	while (i < (len - 1))
	{
		j = 0;
		while (j < (len - i - 1))
		{
			if (ways[j]->len > ways[j + 1]->len)
			{
				tmp = ways[j];
				ways[j] = ways[j + 1];
				ways[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static void	out_ants_eoc(t_way *way, t_info *in)
{
	if (way->ants && in->put_ants)
		ft_printf("{yellow} | ANTS: %d{eoc}\n", way->ants);
	else
		ft_printf("{eoc}\n");
}

void		output_all_ways(t_info *in)
{
	int	j;
	int	i;

	i = 0;
	sort_all_ways(in->all_ways);
	ft_printf("{red}ALL WAYS:{eoc}\n");
	while (in->all_ways && in->all_ways[i])
	{
		if (in->all_ways[i]->ants)
			ft_printf("{green}");
		else
			ft_printf("{red}");
		ft_printf("%d: ", i + 1);
		j = 0;
		while (j < in->all_ways[i]->len)
		{
			if (j > 0)
				ft_printf("->");
			ft_printf("%s", in->rooms[in->all_ways[i]->way[j]]->name);
			j++;
		}
		out_ants_eoc(in->all_ways[i], in);
		i++;
	}
	ft_printf("\n");
}
