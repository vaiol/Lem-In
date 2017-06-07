#include "../lemin.h"

static int	left_d(t_coord r1, t_coord r2, char **map)
{
	int	x;
	int y;

	x = r1.x;
	y = r1.y;
	while (x <= r2.x && y <= r2.y)
	{
		if (!visu_check(y, x, map)) {
			return (0);
		}
		x++;
		y++;
	}
	if (!visu_check_left(y, x, map))
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

static int	left_diagonal(t_room *r1, t_room *r2, char **map)
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

static int	right_d(t_coord r1, t_coord r2, char **map)
{
	int	x;
	int y;

	x = r1.x;
	y = r1.y;
	while (x >= r2.x && y <= r2.y)
	{
		if (!visu_check(y, x, map)) {
			return (0);
		}
		x--;
		y++;
	}
	if (!visu_check_right(y, x, map))
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

static int	right_diagonal(t_room *r1, t_room *r2, char **map)
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

int			visu_diagonal_line(t_room *r1, t_room *r2, char **map)
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


