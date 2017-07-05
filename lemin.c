/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 16:44:30 by astepano          #+#    #+#             */
/*   Updated: 2017/06/20 19:25:04 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		main(void)
{
	t_info	*in;
	char	**file;
	int		line;

	file = read_file();
	in = create_info(file);
	line = parse_input(in);
	line = find_all_ways(in, line);
	find_diffs(in, line);
	get_best_ways(in, line);
	parse_commands(in, line, file);
	create_ants(in, line);
	output_result(in, line, file);
	remove_all(in);
//	sleep(5);
	return (0);
}
