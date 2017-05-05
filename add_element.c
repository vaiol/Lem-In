/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_element.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 01:44:11 by astepano          #+#    #+#             */
/*   Updated: 2017/04/02 01:44:12 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_hex.h"

static int	put_way(t_info *in, int *new_way, int dist)
{
	t_way	**way;
	int		i;
	int		len;

	len = 0;
	while (in->ways && in->ways[len])
		len++;
	way = (t_way **)malloc(sizeof(t_way *) * (len + 2));
	i = 0;
	while (i < len)
	{
		way[i] = in->ways[i];
		i++;
	}
	way[i] = (t_way *)malloc(sizeof(t_way));
	way[i]->way = new_way;
	way[i]->len = dist;
	way[i]->ants = 0;
	way[i + 1] = NULL;
	if (in->ways)
		free(in->ways);
	in->ways = way;
	return (i);
}

int			add_way(t_info *in, int *way, int distance)
{
	int *new_way;
	int	i;
	int j;

	new_way = (int *)malloc(sizeof(int) * (distance));
	j = 0;
	i = in->end;
	while (i != in->start)
	{
		new_way[j] = i;
		i = way[i];
		j++;
	}
	new_way[j] = in->start;
	i = 0;
	while (i < (distance / 2))
	{
		j = new_way[i];
		new_way[i] = new_way[distance - i - 1];
		new_way[distance - i - 1] = j;
		i++;
	}
	return (put_way(in, new_way, distance));
}

int			add_link(t_info *in, int room1, int room2)
{
	t_link	**links;
	int		i;
	int		len;

	len = 0;
	while (in->links && in->links[len])
		len++;
	links = (t_link **)malloc(sizeof(t_link *) * (len + 2));
	i = 0;
	while (i < len)
	{
		links[i] = in->links[i];
		i++;
	}
	links[i] = (t_link *)malloc(sizeof(t_link));
	links[i]->room1 = room1;
	links[i]->room2 = room2;
	links[i + 1] = NULL;
	if (in->links)
		free(in->links);
	in->links = links;
	return (i);
}

int			add_room(t_info *in, char **arr)
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

int			add_command(t_info *in, int i, int room)
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
