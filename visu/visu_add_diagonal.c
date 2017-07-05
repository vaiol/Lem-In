/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_add_diagonal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 16:04:47 by astepano          #+#    #+#             */
/*   Updated: 2017/06/20 16:04:48 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

int	visu_rdd(int x, t_room *r1, t_room *r2, char **map)
{
	int y;

	y = r1->coord_y + 1;
	while (y < r2->coord_y)
	{
		map[y][x] = '\\';
		x++;
		y++;
	}
	return (x);
}

int	visu_rud(int x, t_room *r1, t_room *r2, char **map)
{
	int y;

	y = r1->coord_y - 1;
	while (y > r2->coord_y)
	{
		map[y][x] = '/';
		x++;
		y--;
	}
	return (x);
}

int	visu_ldd(int x, t_room *r1, t_room *r2, char **map)
{
	int y;

	y = r1->coord_y + 1;
	while (y < r2->coord_y)
	{
		map[y][x] = '/';
		x--;
		y++;
	}
	return (x);
}

int	visu_lud(int x, t_room *r1, t_room *r2, char **map)
{
	int y;

	y = r1->coord_y - 1;
	while (y > r2->coord_y)
	{
		map[y][x] = '\\';
		x--;
		y--;
	}
	return (x);
}
