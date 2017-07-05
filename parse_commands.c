/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 16:44:12 by astepano          #+#    #+#             */
/*   Updated: 2017/06/12 16:44:15 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	addcomm(t_info *in, char *str)
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
	else if (ft_strequ(str, "##antmoves"))
		in->put_ant_moves = 1;
	else if (ft_strequ(str, "##ants"))
		in->put_ants = 1;
}

void		parse_commands(t_info *in, int last_line, char **file)
{
	int	i;

	if (last_line == 0)
		return ;
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
