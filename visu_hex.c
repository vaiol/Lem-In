/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 01:42:59 by astepano          #+#    #+#             */
/*   Updated: 2017/04/02 01:43:00 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu_hex.h"

char	**create_map(void)
{
	char	**map;
	int		i;
	int		j;

	map = (char **)malloc(sizeof(char *) * MAP_SIZE);
	i = 0;
	while (i < MAP_SIZE)
	{
		map[i] = (char *)malloc(sizeof(char) * (MAP_SIZE + 1));
		j = 0;
		while (j < MAP_SIZE)
		{
			map[i][j] = ' ';
			j++;
		}
		map[i][j] = '\0';
		i++;
	}
	return (map);
}

void	print_map(char **map)
{
	int	max;
	int	i;
	int	j;

	max = 0;
	i = 0;
	while (i < MAP_SIZE)
	{
		j = 0;
		while (j < MAP_SIZE)
		{
			if (map[i][j] != ' ')
				max = i;
			j++;
		}
		i++;
	}
	i = 0;
	while (i <= max)
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}

void	put_room(char **map, t_room *room)
{
	int	i;
	int	x;
	int	y;

	x = room->coord_x;
	y = room->coord_y;
	map[y][x - 1] = '[';
	i = 0;
	while (room->name[i])
	{
		if (x + i < MAP_SIZE)
			map[y][x + i] = room->name[i];
		i++;
	}
	if (x + i < MAP_SIZE)
		map[y][x + i] = ']';

}

void	horizontal_line(t_room *r1, t_room *r2, char **map)
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
		return ;
	while (x < max)
	{
		map[y][x] = '-';
		x++;
	}
}

void	vertical_line(t_room *r1, t_room *r2, char **map)
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
		max = r2->coord_y + 1;
		y = r1->coord_y - 1;
	}
	else
		return ;
	while (y <= max)
	{
		map[y][x] = '|';
		y++;
	}
}

int		check1(int y, int x, char **map)
{
	if (map[y][x] != '\\' && map[y][x] != '/'
		&& map[y][x] != '|' && map[y][x] != '-' && map[y][x] != '_')
		return (1);
	return (0);
}

int		check(int y, int x, char **map)
{
	if (map[y][x] != ' ' && map[y][x] != '\\' && map[y][x] != '/'
		&& map[y][x] != '|' && map[y][x] != '-' && map[y][x] != '_')
		return (1);
	return (0);
}

int		check_left(int y, int x, char **map)
{
	if (check(y, x, map))
		return (1);
	y--;
	if (check(y, x, map))
		return (1);
	y++;
	x--;
	if (check(y, x, map))
		return (1);
	return (0);
}

int		left_d(t_coord r1, t_coord r2, char **map)
{
	int	x;
	int y;

	x = r1.x;
	y = r1.y;
	while (x <= r2.x && y <= r2.y)
	{
		if (!check1(y, x, map)) {
			return (0);
		}
		x++;
		y++;
	}
	if (!check_left(y, x, map))
		return (0);
	x = r1.x;
	y = r1.y;
	while (x <= r2.x && y <= r2.y)
	{
		if (map[y][x] == ' ')
			map[y][x] = '\\';
		x++;
		y++;
	}
	return (1);
}

//left:
//y, x + 2
//y + 1, x + 1
//y + 1, x + 2
//y + 1, x
//y + 1, x - 1
int		left_diagonal(t_room *r1, t_room *r2, char **map)
{
	t_coord c1;
	t_coord c2;

	c2.x = r2->coord_x;
	c2.y = r2->coord_y;
	c1.y = r1->coord_y + 1;
	c1.x = r1->coord_x + 2;
	if (left_d(c1, c2, map))
		return (1);
	c1.x--;
	if (left_d(c1, c2, map))
		return (1);
	c1.x--;
	if (left_d(c1, c2, map))
		return (1);
	c1.x--;
	if (left_d(c1, c2, map))
		return (1);
	c1.y--;
	c1.x += 3;
	if (left_d(c1, c2, map))
		return (1);
	return (0);
}

int		check_right(int y, int x, char **map)
{
	if (check(y, x, map))
		return (1);
	y--;
	if (check(y, x, map))
		return (1);
	y++;
	x++;
	if (check(y, x, map))
		return (1);
	return (0);
}

int		right_d(t_coord r1, t_coord r2, char **map)
{
	int	x;
	int y;

	x = r1.x;
	y = r1.y;
	while (x >= r2.x && y <= r2.y)
	{
		if (!check1(y, x, map)) {
			return (0);
		}
		x--;
		y++;
	}
	if (!check_right(y, x, map))
		return (0);
	x = r1.x;
	y = r1.y;
	while (x >= r2.x && y <= r2.y)
	{
		if (map[y][x] == ' ')
			map[y][x] = '/';
		x--;
		y++;
	}
	return (1);
}


//right:
//y, x - 2
//y + 1, x + 1
//y + 1, x
//y + 1, x - 1
//y + 1, x - 2
int		right_diagonal(t_room *r1, t_room *r2, char **map)
{
	t_coord c1;
	t_coord c2;

	c2.x = r2->coord_x;
	c2.y = r2->coord_y;
	c1.y = r1->coord_y + 1;
	c1.x = r1->coord_x - 2;
	if (right_d(c1, c2, map))
		return (1);
	c1.x++;
	if (right_d(c1, c2, map))
		return (1);
	c1.x++;
	if (right_d(c1, c2, map))
		return (1);
	c1.x++;
	if (right_d(c1, c2, map))
		return (1);
	c1.y--;
	c1.x -= 3;
	if (right_d(c1, c2, map))
		return (1);
	return (0);
}

int		diagonal_line(t_room *r1, t_room *r2, char **map)
{
	if (r1->coord_y < r2->coord_y)
	{
		if (r1->coord_x < r2->coord_x)
			return (left_diagonal(r1, r2, map));
		else
			return (right_diagonal(r1, r2, map));
	}
	else
	{
		if (r1->coord_x > r2->coord_x)
			return (left_diagonal(r2, r1, map));
		else
			return (right_diagonal(r2, r1, map));
	}
}

int		diagonal(t_room *r1, t_room *r2, char **map)
{
	int	x;
	int	y;
	int diff;

	y = r2->coord_y - r1->coord_y;
	x = r2->coord_x - r1->coord_x;
	diff = ABS(x) - ABS(y);
	if (ABS(diff) >= 0 && ABS(diff) <= 3)
		return (diagonal_line(r1, r2, map));
	return (0);
}

void	put_link_vh(t_info *in, char **map, t_link *link)
{
	t_room	*r1;
	t_room	*r2;

	r1 = in->rooms[link->room1];
	r2 = in->rooms[link->room2];
	if (r1->coord_y == r2->coord_y)
		horizontal_line(r1, r2, map);
	else if (r1->coord_x == r2->coord_x)
		vertical_line(r1, r2, map);
	else
	{
		if (diagonal(r1, r2, map))
			return;
//		put_link_rec(in, r1, r2, map);
	}
}

void	put_map(t_info *in)
{
	char	**map;
	int		i;

	map = create_map();
	i = 0;
	while (in->rooms[i])
	{
		put_room(map, in->rooms[i]);
		i++;
	}
	i = 0;
	while (in->links[i])
	{
		put_link_vh(in, map, in->links[i]);
		i++;
	}
	print_map(map);
}

void	print_result(t_info *in, int last)
{
	int	moves;

	if (last == 0)
		return ;
	create_ants(in);
	output_ways(in);

	put_map(in);
	ft_printf("\n");
	moves = 0;
	while (print_ants(in))
	{
		ft_printf("\n");
		moves++;
	}
	ft_printf("\n");
	ft_printf("{green}MOVES: %d{eoc}\n", moves);
}

int		main(void)
{
	t_info	*in;
	char	**file;
	int		l;

	file = read_file();
	in = create_info(file);
	l = parse_input(in);
	l = find_ways(in, l);
	write_file(file, l);
	print_result(in, l);
	remove_all(in);
	return (0);
}
