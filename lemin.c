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

void	addcomm(t_info *in, char *str)
{
	if (ft_strequ(str, "##map"))
		in->put_map = 1;
	else if (ft_strequ(str, "##moves"))
		in->put_moves = 1;
	else if (ft_strequ(str, "##allways"))
		in->put_all_ways = 1;
	else if (ft_strequ(str, "##ways"))
		in->put_ways = 1;
	else if (ft_strequ(str, "##hide"))
		in->put_hide = 1;
	else if (ft_strequ(str, "##clean"))
		in->put_clean = 1;
}


void	add_commands(t_info *in, int last_line, char **file)
{
	int	i;

	i = 0;
	while (file[i])
	{
		if (iscomment(file[i]))
		{
			addcomm(in, file[i]);
			last_line++;
		}
		if (i >= last_line)
			return ;
		i++;
	}
}

void	print_result(t_info *in, int last)
{
	int	moves;

	if (last == 0)
		return ;
	create_ants(in);
	if (in->put_all_ways)
		output_all_ways(in);
	else if (in->put_ways)
		output_ways(in);
	if (in->put_map)
		visu_put_map(in);
	moves = 0;
	while (print_ants(in))
	{
		ft_printf("\n");
		moves++;
	}
	if (in->put_moves)
		ft_printf("\n{green}MOVES: %d{eoc}\n", moves);
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
	add_commands(in, l, file);
	write_file(in, file, l);
	print_result(in, l);
	remove_all(in);
	sleep(10);
	return (0);
}
