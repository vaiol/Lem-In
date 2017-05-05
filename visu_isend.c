#include "visu_hex.h"

static int	check_left(char element, int x, int y, t_room *r2)
{
	int	x1;
	int	y1;

	x1 = r2->coord_x - 1;
	y1 = r2->coord_y;
	if ((element == '_' || element == '/' || element == '\\')
		&& (x == x1 - 1 && y == y1))
		return (1);
	if (element == '/' && ((x == x1 && y == y1 - 1) || (x == x1 && y == y1 + 1)
						   || (x == x1 - 1 && y == y1 - 1)))
		return (1);
	if (element == '\\' && ((x == x1 && y == y1 - 1) || (x == x1 && y == y1 + 1)
							|| (x == x1 - 1 && y == y1 - 1)))
		return (1);
	return (0);
}

static int	check_right(char element, int x, int y, t_room *r2)
{
	int	i;
	int	x1;
	int	y1;

	i = 0;
	while (r2->name[i])
		i++;
	x1 = r2->coord_x + i + 1;
	y1 = r2->coord_y;
	if ((element == '_' || element == '/' || element == '\\')
		&& (x == x1 + 1 && y == y1))
		return (1);
	if (element == '/' && ((x == x1 && y == y1 - 1) || (x == x1 && y == y1 + 1)
						   || (x == x1 + 1 && y == y1 - 1)))
		return (1);
	if (element == '\\' && ((x == x1 && y == y1 - 1) || (x == x1 && y == y1 + 1)
							|| (x == x1 + 1 && y == y1 - 1)))
		return (1);
	return (0);
}

static int	check_top_bottom(char element, int x, int y, t_room *r2)
{
	int	i;
	int	x1;
	int	y1;

	y1 = r2->coord_y;
	i = 0;
	while (r2->name[i])
	{
		x1 = r2->coord_x + i;
		if ((element == '\\' || element == '/' || element == '|')
			&& (x1 == x && (y == y1 - 1 || y == y1 + 1)))
			return (1);
		i++;
	}
	return (0);
}

int			is_end(char element, int x, int y, t_room *r2)
{
	if (check_left(element, x, y, r2))
		return (1);
	if (check_right(element, x, y, r2))
		return (1);
	if (check_top_bottom(element, x, y, r2))
		return (1);
	return (0);
}

