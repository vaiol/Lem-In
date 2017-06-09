#include "lemin.h"

static int	check(int *arr, int index, int room)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (room == arr[i])
			return (0);
		i++;
	}
	return (1);
}

static void	recursion(t_info *in, int *arr, int ind, int room)
{
	int	i;

	arr[ind] = room;
	if (room == in->end)
	{
		add_way(in, arr, ind + 1);
		return ;
	}
	i = 0;
	while (i < in->size)
	{
		if (in->matrix[i][room] && check(arr, ind, i))
			recursion(in, arr, ind + 1, i);
		i++;
	}
}

int			find_all_ways(t_info *in, int last)
{
	int	i;
	int	*arr;

	if (last == 0)
		return (last);
	i = 0;
	while (in->rooms[i])
		i++;
	arr = (int *)malloc(sizeof(int) * i);
	build_matrix(in);
	recursion(in, arr, 0, in->start);
	free(arr);
	if (in->ways == NULL)
		return (0);
	find_diffs(in);
	get_best_ways(in);
	return (last);
}

