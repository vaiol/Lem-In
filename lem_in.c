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

void	output_ways(t_info *in)
{
	int	j;
	int	i;

	i = 0;
	while (in->ways && in->ways[i])
	{
		j = 0;
		while (j < in->ways[i]->len)
		{
			ft_printf("%d ", in->ways[i]->way[j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
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
	output_ways(in);
	remove_all(in);
	return (0);
}
