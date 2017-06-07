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

#include "lemin.h"

void	print_result(t_info *in, int last)
{
	int	moves;

	if (last == 0)
		return ;
	create_ants(in);
	output_ways(in);

	visu_put_map(in);
	ft_printf("\n");
	moves = 0;
	while (print_ants(in))
	{
		ft_printf("\n");
		moves++;
	}
	ft_printf("\n");
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
	l = find_all_ways(in, l);
	write_file(file, l);
	print_result(in, l);
	remove_all(in);
	return (0);
}
