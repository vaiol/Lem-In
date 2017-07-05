/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 16:32:05 by astepano          #+#    #+#             */
/*   Updated: 2017/06/20 16:32:06 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

static char	**clean_input(char **file)
{
	char	**input;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (file && file[i])
		i++;
	input = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (file && file[i])
	{
		if (iscommand(file[i]) && file[i + 1])
		{
			input[j++] = file[i++];
			input[j++] = file[i++];
		}
		else if (iscomment(file[i]))
			i++;
		else
			input[j++] = file[i++];
	}
	input[j] = NULL;
	return (input);
}

t_info		*create_info(char **file)
{
	t_info	*in;

	in = (t_info *)malloc(sizeof(t_info));
	in->ants_count = -1;
	in->start = -1;
	in->end = -1;
	in->rooms = NULL;
	in->diffs = NULL;
	in->all_ways = NULL;
	in->links = NULL;
	in->ways = NULL;
	in->ants = NULL;
	in->matrix = NULL;
	in->input = clean_input(file);
	in->put_all_ways = 0;
	in->put_hide = 0;
	in->put_map = 0;
	in->put_moves = 0;
	in->put_ways = 0;
	in->put_clean = 0;
	in->put_ant_moves = 0;
	in->put_ants = 0;
	return (in);
}
