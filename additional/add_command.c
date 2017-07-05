/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 16:31:27 by astepano          #+#    #+#             */
/*   Updated: 2017/06/20 16:31:28 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

int		add_command(t_info *in, int i, int room)
{
	if (ft_strequ(in->input[i - 1], "##start"))
	{
		if (in->start != -1)
			return (0);
		in->start = room;
		return (1);
	}
	else if (ft_strequ(in->input[i - 1], "##end"))
	{
		if (in->end != -1)
			return (0);
		in->end = room;
		return (1);
	}
	return (0);
}
