/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 16:31:45 by astepano          #+#    #+#             */
/*   Updated: 2017/06/20 16:31:46 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

int		add_room(t_info *in, char **arr)
{
	t_room	**rooms;
	int		i;
	int		len;

	len = 0;
	while (in->rooms && in->rooms[len])
		len++;
	rooms = (t_room **)malloc(sizeof(t_room *) * (len + 2));
	i = 0;
	while (i < len)
	{
		rooms[i] = in->rooms[i];
		i++;
	}
	rooms[i] = (t_room *)malloc(sizeof(t_room));
	rooms[i]->name = ft_strdup(arr[0]);
	rooms[i]->coord_x = ft_atoi(arr[1]);
	rooms[i]->coord_y = ft_atoi(arr[2]);
	rooms[i + 1] = NULL;
	if (in->rooms)
		free(in->rooms);
	in->rooms = rooms;
	return (i);
}
