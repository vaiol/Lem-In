#include "../lemin.h"

static void	horizontal_line(t_room *r1, t_room *r2, char **map)
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

static void	vertical_line(t_room *r1, t_room *r2, char **map)
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

void		visu_put_link(t_info *in, char **map, t_link *link)
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