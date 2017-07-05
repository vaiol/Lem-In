/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_put_link.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 16:42:44 by astepano          #+#    #+#             */
/*   Updated: 2017/06/12 16:42:46 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

static int	horizontal_line(t_room *r1, t_room *r2, char **map)
{
	int	y;
	int x;
	int	max;

	y = r1->coord_y;
	if (r1->coord_x < r2->coord_x)
	{
		x = r1->coord_x + (int)ft_strlen(r1->name) + 1;
		max = r2->coord_x - 1;
	}
	else if (r1->coord_x > r2->coord_x)
	{
		x = r2->coord_x + (int)ft_strlen(r2->name) + 1;
		max = r1->coord_x - 1;
	}
	else
		return (0);
	while (x < max)
	{
		map[y][x] = '-';
		x++;
	}
	return (1);
}

static int	vertical_line(t_room *r1, t_room *r2, char **map)
{
	int	y;
	int x;
	int	max;

	x = r1->coord_x;
	if (r1->coord_y < r2->coord_y)
	{
		y = r1->coord_y + 1;
		max = r2->coord_y - 1;
	}
	else if (r1->coord_y > r2->coord_y)
	{
		y = r2->coord_y + 1;
		max = r1->coord_y - 1;
	}
	else
		return (0);
	while (y <= max)
	{
		map[y][x] = '|';
		y++;
	}
	return (1);
}

static int	diagonal(t_room *r1, t_room *r2, char **map)
{
	int	x;
	int	y;
	int diff;

	y = r2->coord_y - r1->coord_y;
	x = r2->coord_x - r1->coord_x;
	diff = ABS(x) - ABS(y);
	if (ABS(diff) >= 0 && ABS(diff) <= 3)
		return (visu_diagonal_line(r1, r2, map));
	return (0);
}

int			visu_put_link(t_info *in, char **map, t_link *link)
{
	t_room	*r1;
	t_room	*r2;

	r1 = in->rooms[link->room1];
	r2 = in->rooms[link->room2];
	if (r1->coord_y == r2->coord_y)
		return (horizontal_line(r1, r2, map));
	else if (r1->coord_x == r2->coord_x)
		return (vertical_line(r1, r2, map));
	else
		return (diagonal(r1, r2, map));
}
