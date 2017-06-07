/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 14:01:20 by astepano          #+#    #+#             */
/*   Updated: 2017/04/01 14:01:21 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	get_room(t_info *in, char *name)
{
	int	i;

	if (in->rooms == NULL)
		return (-1);
	i = 0;
	while (in->rooms[i])
	{
		if (ft_strequ(in->rooms[i]->name, name))
			return (i);
		i++;
	}
	return (-1);
}

static int	parse_link(t_info *in, int i)
{
	int		room1;
	int		room2;
	int		count;
	char	**arr;

	arr = ft_strsplit(in->input[i], '-');
	count = 0;
	while (arr[count])
		count++;
	if (count != 2)
	{
		ft_arrdel(arr);
		return (0);
	}
	room1 = get_room(in, arr[0]);
	room2 = get_room(in, arr[1]);
	ft_arrdel(arr);
	if (room1 < 0 || room2 < 0)
		return (0);
	add_link(in, room1, room2);
	return (1);
}

static int	parse_room(t_info *in, int i)
{
	int		room;
	int		count;
	char	**arr;

	arr = ft_strsplit(in->input[i], ' ');
	count = 0;
	while (arr[count])
		count++;
	if (count != 3 || arr[0][0] == 'L' || ft_strcchr(arr[0], '-')
		|| !isint(arr[1]) || !isint(arr[2]) || room_exist(in, arr))
	{
		ft_arrdel(arr);
		return (0);
	}
	room = add_room(in, arr);
	ft_arrdel(arr);
	if (iscommand(in->input[i - 1]))
		return (add_command(in, i, room));
	return (1);
}

static int	parse_ant(t_info *in)
{
	in->ants_count = ft_atoi(in->input[0]);
	if (in->ants_count <= 0 || !isint(in->input[0]))
		return (0);
	return (1);
}

int			parse_input(t_info *in)
{
	int	command;
	int	i;

	if (!(i = parse_ant(in)))
		return (0);
	if (iscommand(in->input[i]))
		i++;
	command = 1;
	while (in->input[i] && parse_room(in, i))
	{
		i++;
		command = 0;
		if (iscommand(in->input[i]))
		{
			i++;
			command = 1;
		}
	}
	if (command)
		return (i);
	while (in->input[i] && parse_link(in, i))
		i++;
	return (i);
}
