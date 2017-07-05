/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 16:04:58 by astepano          #+#    #+#             */
/*   Updated: 2017/06/20 16:04:59 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

static int	right_horizontal(int x, t_room *r1, t_room *r2, char **map)
{
	int diff;
	int x1;
	int	y;

	diff = 100;
	while (ABS(diff) < 0 || ABS(diff) > 2)
	{
		y = r2->coord_y - r1->coord_y;
		x1 = r2->coord_x - x;
		diff = ABS(x1) - ABS(y);
		map[r1->coord_y][x] = '-';
		x++;
	}
	map[r1->coord_y][x++] = '-';
	map[r1->coord_y][x++] = '-';
	return (x);
}

static int	left_horizontal(int x, t_room *r1, t_room *r2, char **map)
{
	int diff;
	int x1;
	int	y;

	diff = 100;
	while (ABS(diff) < 0 || ABS(diff) > 2)
	{
		y = r2->coord_y - r1->coord_y;
		x1 = r2->coord_x - x;
		diff = ABS(x1) - ABS(y);
		map[r1->coord_y][x] = '-';
		x--;
	}
	map[r1->coord_y][x--] = '-';
	map[r1->coord_y][x--] = '-';
	return (x);
}

static void	put_line1(t_room *r1, t_room *r2, char **map)
{
	int	y;
	int	x;

	x = r1->coord_x + 2;
	y = r1->coord_y;
	if (map[y][x] == ' ')
	{
		x = right_horizontal(x, r1, r2, map);
		if (r1->coord_y < r2->coord_y)
			visu_rdd(x, r1, r2, map);
		else
			visu_rud(x, r1, r2, map);
		return ;
	}
	x = r2->coord_x - 2;
	y = r2->coord_y;
	if (map[y][x] == ' ')
	{
		x = left_horizontal(x, r2, r1, map);
		if (r2->coord_y < r1->coord_y)
			visu_ldd(x, r2, r1, map);
		else
			visu_lud(x, r2, r1, map);
		return ;
	}
}

static void	put_line2(t_room *r1, t_room *r2, char **map)
{
	int	y;
	int	x;

	x = r1->coord_x - 2;
	y = r1->coord_y;
	if (map[y][x] == ' ')
	{
		x = left_horizontal(x, r1, r2, map);
		if (r1->coord_y < r2->coord_y)
			visu_ldd(x, r1, r2, map);
		else
			visu_lud(x, r1, r2, map);
		return ;
	}
	x = r2->coord_x + 2;
	y = r2->coord_y;
	if (map[y][x] == ' ')
	{
		x = right_horizontal(x, r2, r1, map);
		if (r2->coord_y < r1->coord_y)
			visu_rdd(x, r2, r1, map);
		else
			visu_rud(x, r2, r1, map);
		return ;
	}
}

void		visu_add_lines(int *links, t_info *in, char **map)
{
	int		i;
	t_room	*r1;
	t_room	*r2;

	i = 0;
	while (in->links[i])
	{
		r1 = in->rooms[in->links[i]->room1];
		r2 = in->rooms[in->links[i]->room2];
		if (links[i] == 0)
		{
			if (r1->coord_x < r2->coord_x)
				put_line1(r1, r2, map);
			else
				put_line2(r1, r2, map);
		}
		i++;
	}
	free(links);
}
