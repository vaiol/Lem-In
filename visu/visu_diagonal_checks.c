#include "../lemin.h"

static int	check(int y, int x, char **map)
{
	if (map[y][x] != ' ' && map[y][x] != '\\' && map[y][x] != '/'
		&& map[y][x] != '|' && map[y][x] != '-' && map[y][x] != '_')
		return (1);
	return (0);
}

int		visu_check(int y, int x, char **map)
{
	if (map[y][x] != '\\' && map[y][x] != '/'
		&& map[y][x] != '|' && map[y][x] != '-' && map[y][x] != '_')
		return (1);
	return (0);
}

int		visu_check_left(int y, int x, char **map)
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

int		visu_check_right(int y, int x, char **map)
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