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

#include "lemin.h"

static int	put_way(t_info *in, int *new_way, int dist)
{
	t_way	**ways;
	int		i;
	int		len;

	len = 0;
	while (in->ways && in->ways[len])
		len++;
	ways = (t_way **)malloc(sizeof(t_way *) * (len + 2));
	i = 0;
	while (i < len)
	{
		ways[i] = in->ways[i];
		i++;
	}
	ways[i] = (t_way *)malloc(sizeof(t_way));
	ways[i]->way = new_way;
	ways[i]->len = dist;
	ways[i]->ants = 0;
	ways[i + 1] = NULL;
	if (in->ways)
		free(in->ways);
	in->ways = ways;
	return (i);
}

int			add_way(t_info *in, int *way, int len)
{
	int *new_way;
	int	i;

	new_way = (int *)malloc(sizeof(int) * (len));
	i = 0;
	while (i < len)
	{
		new_way[i] = way[i];
		i++;
	}
	return (put_way(in, new_way, len));
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
