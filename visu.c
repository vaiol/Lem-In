#include "visu_hex.h"

t_vlink			*create_vlink(char e, t_coord prev, t_coord next, t_room *room)
{
	t_vlink	*vlink;

	vlink = (t_vlink *)malloc(sizeof(t_vlink));
	vlink->e[0] = '\0';
	vlink->e[1] = e;
	vlink->coords[0].x = prev.x;
	vlink->coords[0].y = prev.y;
	vlink->coords[1].x = next.x;
	vlink->coords[1].y = next.y;
	vlink->end = room;
	vlink->len = 1;
	return (vlink);
}


int		is_move(t_vlink *vlink, char **map, t_coord coord)
{
	int	i;

	i = 0;
	if (coord.y < 0 || coord.x < 0 || coord.y >= MAP_SIZE || coord.x >= MAP_SIZE)
		return (0);
	if (map[coord.y][coord.x] != ' ')
		return (0);
	while (i <= vlink->len)
	{
		if (coord.x == vlink->coords[i].x && coord.y == vlink->coords[i].y)
			return (0);
		i++;
	}
	return (1);
}

t_vlink	*vlink_next(t_vlink *vlink, char e, t_coord coord, char **map)
{
	t_coord	move;

	move.x = vlink->coords[vlink->len].x + coord.x;
	move.y = vlink->coords[vlink->len].y + coord.y;
	if (!is_move(vlink, map, move))
		return (NULL);
	if (vlink->len + 1 >= MAX_VLINK_LEN)
		return (NULL);
	vlink->coords[vlink->len + 1].x = move.x;
	vlink->coords[vlink->len + 1].y = move.y;
	vlink->e[vlink->len + 1] = e;
	vlink->len++;
	return (vlink);
}

t_coord	get_coord(int x, int y)
{
	t_coord	coord;

	coord.x = x;
	coord.y = y;
	return (coord);
}

/*
-1, -1:
	'\' -> "_\|"
	'|' -> "\"
0, -1:
 	'/' -> "|"
	'\' -> "|"
	'|' -> "/|\"
+1, -1:
	'/' -> "_|/"
	'|' -> "/"
-1, 0:
	'_' -> "\_"
+1, 0:
	'_' -> "_/"
-1, +1:
	'_' -> "/"
	'/' -> "|/"
	'|' -> "/"
0, +1:
	'|' -> "/|\"
	'/' -> "|"
	'\' -> "|"
+1, +1:
	'_' -> "\"
	'|' -> "\"
	'\' -> "\|"
*/

t_coord	find_shortest()
{

}


void	put_down(t_info *in, t_vlink *vlink, char **map)
{
	if (vlink->e[vlink->len] == '\\')
		recursion(in, vlink_next(vlink, '|', get_coord(1, 1), map), map);
	if (vlink->e[vlink->len] == '/')
		recursion(in, vlink_next(vlink, '|', get_coord(-1, 1), map), map);
	if (vlink->e[vlink->len] == '|')
		recursion(in, vlink_next(vlink, '|', get_coord(0, 1), map), map);
	if (vlink->e[vlink->len] == '_')
	{
		recursion(in, vlink_next(vlink, '/', get_coord(-1, 1), map), map);
		recursion(in, vlink_next(vlink, '\\', get_coord(1, 1), map), map);
	}
}

void	put_up(t_info *in, t_vlink *vlink, char **map)
{
	if (vlink->e[vlink->len] == '\\')
		recursion(in, vlink_next(vlink, '_', get_coord(-1, -1), map), map);
	if (vlink->e[vlink->len] == '/')
		recursion(in, vlink_next(vlink, '_', get_coord(1, -1), map), map);
	if (vlink->e[vlink->len] == '|')
		recursion(in, vlink_next(vlink, '|', get_coord(0, -1), map), map);
	if (vlink->e[vlink->len] == '_')
	{
		recursion(in, vlink_next(vlink, '/', get_coord(1, 0), map), map);
		recursion(in, vlink_next(vlink, '\\', get_coord(-1, 0), map), map);
	}
}

void	put_left(t_info *in, t_vlink *vlink, char **map)
{
	if (vlink->e[vlink->len] == '\\')
		recursion(in, vlink_next(vlink, '_', get_coord(-1, -1), map), map);
	if (vlink->e[vlink->len] == '|')
		recursion(in, vlink_next(vlink, '\\', get_coord(-1, -1), map), map);
	if (vlink->e[vlink->len] == '_')
		recursion(in, vlink_next(vlink, '_', get_coord(-1, 0), map), map);
}

void	put_right(t_info *in, t_vlink *vlink, char **map)
{
	if (vlink->e[vlink->len] == '/')
		recursion(in, vlink_next(vlink, '_', get_coord(1, -1), map), map);
	if (vlink->e[vlink->len] == '|')
		recursion(in, vlink_next(vlink, '/', get_coord(1, -1), map), map);
	if (vlink->e[vlink->len] == '_')
		recursion(in, vlink_next(vlink, '_', get_coord(1, 0), map), map);
}

void	put_rec(t_info *in, t_vlink *vlink, char **map)
{
//	if (vlink->e[vlink->len] == '\\')
//	{
//		recursion(in, vlink_next(vlink, '\\', get_coord(1, 1), map), map);
//		recursion(in, vlink_next(vlink, '\\', get_coord(-1, -1), map), map);
//		recursion(in, vlink_next(vlink, '_', get_coord(-1, -1), map), map);
//		recursion(in, vlink_next(vlink, '|', get_coord(-1, -1), map), map);
//		recursion(in, vlink_next(vlink, '|', get_coord(0, -1), map), map);
//		recursion(in, vlink_next(vlink, '|', get_coord(0, 1), map), map);
//		recursion(in, vlink_next(vlink, '|', get_coord(1, 1), map), map);
//	}
//	if (vlink->e[vlink->len] == '/')
//	{
//		recursion(in, vlink_next(vlink, '/', get_coord(1, -1), map), map);
//		recursion(in, vlink_next(vlink, '/', get_coord(-1, 1), map), map);
//		recursion(in, vlink_next(vlink, '_', get_coord(1, -1), map), map);
//		recursion(in, vlink_next(vlink, '|', get_coord(1, -1), map), map);
//		recursion(in, vlink_next(vlink, '|', get_coord(-1, 1), map), map);
//		recursion(in, vlink_next(vlink, '|', get_coord(0, 1), map), map);
//		recursion(in, vlink_next(vlink, '|', get_coord(0, -1), map), map);
//	}
//	if (vlink->e[vlink->len] == '|')
//	{
//		recursion(in, vlink_next(vlink, '|', get_coord(0, -1), map), map);
//		recursion(in, vlink_next(vlink, '|', get_coord(0, 1), map), map);
//		recursion(in, vlink_next(vlink, '\\', get_coord(-1, -1), map), map);
//		recursion(in, vlink_next(vlink, '\\', get_coord(0, -1), map), map);
//		recursion(in, vlink_next(vlink, '\\', get_coord(1, 1), map), map);
//		recursion(in, vlink_next(vlink, '\\', get_coord(0, 1), map), map);
//		recursion(in, vlink_next(vlink, '/', get_coord(0, -1), map), map);
//		recursion(in, vlink_next(vlink, '/', get_coord(1, -1), map), map);
//		recursion(in, vlink_next(vlink, '/', get_coord(-1, 1), map), map);
//		recursion(in, vlink_next(vlink, '/', get_coord(0, 1), map), map);
//	}
//	if (vlink->e[vlink->len] == '_')
//	{
//
//		recursion(in, vlink_next(vlink, '_', get_coord(1, 0), map), map);
//		recursion(in, vlink_next(vlink, '_', get_coord(-1, 0), map), map);
//		recursion(in, vlink_next(vlink, '\\', get_coord(1, 1), map), map);
//		recursion(in, vlink_next(vlink, '/', get_coord(-1, 1), map), map);
//		recursion(in, vlink_next(vlink, '/', get_coord(1, 0), map), map);
//		recursion(in, vlink_next(vlink, '\\', get_coord(-1, 0), map), map);
//	}
	put_up(in, vlink, map);
	put_left(in, vlink, map);
	put_down(in, vlink, map);
	put_right(in, vlink, map);
}


void	recursion(t_info *in, t_vlink *vlink, char **map)
{
	int		i;

	if (vlink == NULL)
		return;
	i = vlink->len;
	ft_printf("rec: %d, %s\n", i, vlink->end->name);
	if (is_end(vlink->e[i], vlink->coords[i].x, vlink->coords[i].y, vlink->end))
	{
		vlink->len--;
		return (add_vlink(in, vlink));
	}
	if ((vlink->len + 1) < MAX_VLINK_LEN)
		put_rec(in, vlink, map);
	vlink->len--;
	if (vlink->len == 0)
		free(vlink);
}

void	put_link_rec(t_info *in, t_room *r1, t_room *r2, char **map)
{
	if (r2->coord_y == 7)
		return;
	ft_printf("left: ");
	start_left(in, r1, r2, map);
	ft_printf("right: ");
	start_right(in, r1, r2, map);
//	ft_printf("side: ");
//	start_side(in, r1, r2, map);
}

