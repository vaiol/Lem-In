/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 01:43:50 by astepano          #+#    #+#             */
/*   Updated: 2017/04/02 01:43:51 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		iscommand(char *str)
{
	if (ft_strequ(str, "##start") || ft_strequ(str, "##end"))
		return (1);
	return (0);
}

int		iscomment(char *str)
{
	if (str[0] == '#' && !iscommand(str))
		return (1);
	return (0);
}

int		isint(char *str)
{
	unsigned int	result;
	int				minus;
	size_t			i;

	i = 0;
	minus = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		minus = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	result = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		result = result * 10 + (str[i] - 48);
		if (result >= 2147483648 || (result > 2147483648 && minus))
			return (0);
		i++;
	}
	return (1);
}

int		room_exist(t_info *in, char **arr)
{
	int		i;
	char	*name;
	int		x;
	int		y;

	if (in->rooms == NULL)
		return (0);
	name = arr[0];
	x = ft_atoi(arr[1]);
	y = ft_atoi(arr[2]);
	i = 0;
	while (in->rooms[i])
	{
		if (ft_strequ(name, in->rooms[i]->name))
			return (1);
		if (x == in->rooms[i]->coord_x && y == in->rooms[i]->coord_y)
			return (1);
		i++;
	}
	return (0);
}
