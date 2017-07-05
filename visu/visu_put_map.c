/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_put_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 16:42:54 by astepano          #+#    #+#             */
/*   Updated: 2017/06/12 16:42:55 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

static char	**create_map(void)
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

static int	get_max_line(char **map)
{
	int	j;
	int i;
	int	max;

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
	return (max);
}

static void	print_map(char **map)
{
	int	max;
	int	i;

	max = get_max_line(map);
	i = 0;
	while (i < MAP_SIZE)
	{
		if (i <= max)
			ft_printf("%s\n", map[i]);
		free(map[i]);
		i++;
	}
	ft_printf("\n");
	free(map);
}

static void	put_room(char **map, t_room *room)
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

void		visu_put_map(t_info *in)
{
	int		*links;
	char	**map;
	int		i;

	map = create_map();
	i = 0;
	while (in->rooms[i])
		put_room(map, in->rooms[i++]);
	i = 0;
	while (in->links[i])
		i++;
	links = (int *)malloc(sizeof(int) * i);
	i = 0;
	while (in->links[i])
	{
		links[i] = visu_put_link(in, map, in->links[i]);
		i++;
	}
	visu_add_lines(links, in, map);
	print_map(map);
}
