#include "visu_hex.h"


static void		start_left1(t_info *in, t_room *r1, t_room *r2, char **map)
{
	int		i;
	t_coord	prev;
	t_coord	next;

	i = 0;
	while (r1->name[i])
		i++;
	prev.x = r1->coord_x - 1;
	prev.y = r1->coord_y;
	next.x = prev.x;
	next.y = prev.y + 1;
	if (map[next.y ][next.x] == ' ')
	{
		recursion(in, create_vlink('/', prev, next, r2), map);
		recursion(in, create_vlink('\\',prev, next, r2), map);
	}
	next.x = prev.x - 1;
	next.y = prev.y - 1;
	if (map[next.y ][next.x] == ' ')
	{
		recursion(in, create_vlink('/', prev, next, r2), map);
		recursion(in, create_vlink('\\',prev, next, r2), map);
	}
}
void			start_left(t_info *in, t_room *r1, t_room *r2, char **map)
{
	t_coord	prev;
	t_coord	next;

	prev.x = r1->coord_x - 1;
	prev.y = r1->coord_y;
	next.x = prev.x - 1;
	next.y = prev.y;
	if (map[next.y][next.x] == ' ')
	{
		recursion(in, create_vlink('_', prev, next, r2), map);
//		recursion(in, create_vlink('/', prev, next, r2), map);
//		recursion(in, create_vlink('\\',prev, next, r2), map);
	}
	next.x = prev.x;
	next.y = prev.y - 1;
	if (map[next.y ][next.x] == ' ')
	{
		recursion(in, create_vlink('/', prev, next, r2), map);
		recursion(in, create_vlink('\\',prev, next, r2), map);
	}
	start_left1(in, r1, r2, map);
}


static void		start_right1(t_info *in, t_room *r1, t_room *r2, char **map)
{
	int		i;
	t_coord	prev;
	t_coord	next;

	i = 0;
	while (r1->name[i])
		i++;
	prev.x = r1->coord_x + i + 1;
	prev.y = r1->coord_y;
	next.x = prev.x;
	next.y = prev.y + 1;
	if (map[next.y ][next.x] == ' ')
	{
		recursion(in, create_vlink('/', prev, next, r2), map);
		recursion(in, create_vlink('\\',prev, next, r2), map);
	}
//	next.x = prev.x + 1;
//	next.y = prev.y - 1;
//	if (map[next.y ][next.x] == ' ')
//	{
//		recursion(in, create_vlink('/', prev, next, r2), map);
//		recursion(in, create_vlink('\\',prev, next, r2), map);
//	}
}

void			start_right(t_info *in, t_room *r1, t_room *r2, char **map)
{
	int		i;
	t_coord	prev;
	t_coord	next;

	i = 0;
	while (r1->name[i])
		i++;
	prev.x = r1->coord_x + i + 1;
	prev.y = r1->coord_y;
	next.x = prev.x + 1;
	next.y = prev.y;
	if (map[next.y][next.x] == ' ')
	{
		recursion(in, create_vlink('_', prev, next, r2), map);
//		recursion(in, create_vlink('/', prev, next, r2), map);
//		recursion(in, create_vlink('\\',prev, next, r2), map);
	}
	next.x = prev.x;
	next.y = prev.y - 1;
	if (map[next.y ][next.x] == ' ')
	{
		recursion(in, create_vlink('/', prev, next, r2), map);
//		recursion(in, create_vlink('\\',prev, next, r2), map);
	}
	start_right1(in, r1, r2, map);
}

void			start_side(t_info *in, t_room *r1, t_room *r2, char **map)
{
	int	i;
	t_coord	prev;
	t_coord	next;

	prev.y = r1->coord_y;
	i = 0;
	while (r1->name[i])
	{
		prev.x = r2->coord_x + i;
		next.x = prev.x;
		next.y = prev.y - 1;
		recursion(in, create_vlink('/', prev, next, r2), map);
		recursion(in, create_vlink('\\',prev, next, r2), map);
		recursion(in, create_vlink('|', prev, next, r2), map);
		next.y = prev.y + 1;
		recursion(in, create_vlink('/', prev, next, r2), map);
		recursion(in, create_vlink('\\',prev, next, r2), map);
		recursion(in, create_vlink('|', prev, next, r2), map);
	}
}
