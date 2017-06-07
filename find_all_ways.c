#include "lemin.h"

static int	is_parallel(t_info *in, int w1, int w2)
{
	int i;
	int	j;
	int	r;

	i = 0;
	while (i < in->ways[w1]->len)
	{
		j = 0;
		while (j < in->ways[w2]->len)
		{
			r = in->ways[w1]->way[i];
			if (r == in->ways[w2]->way[j] && r != in->end && r != in->start)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}


static void	find_diffs(t_info *in)
{
	int	i;
	int	j;

	i = 0;
	while (in->ways[i])
	{
		j = 0;
		while (in->ways[j])
		{
			if (i == j || is_parallel(in, i, j))
			{
				in->diffs[i]->ways[in->diffs[i]->len] = j;
				in->diffs[i]->len++;
			}
			j++;
		}
		i++;
	}
}

static void create_diffs(t_info *in)
{
	int	i;
	int	len;

	len = 0;
	while (in->ways[len])
		len++;
	in->diffs = (t_diff **)malloc(sizeof(t_diff *) * (len + 1));
	i = 0;
	while (i < len)
	{
		in->diffs[i] = (t_diff *)malloc(sizeof(t_diff));
		in->diffs[i]->len = 0;
		in->diffs[i]->ways = (int *)malloc(sizeof(int) * len);
		i++;
	}
	in->diffs[i] = NULL;
}

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
//		ft_printf("1\n");
		add_way(in, arr, ind + 1);
		return ;
	}
	i = 0;
//	ft_printf("%d", in->size);
	while (i < in->size)
	{
//		if (in->links[i]->room1 == room && in->links[i]->room2 != arr[ind - 1])
//			recursion(in, arr, ind + 1, in->links[i]->room2);
//		else if (in->links[i]->room2 == room && in->links[i]->room1 != arr[ind - 1])
//			recursion(in, arr, ind + 1, in->links[i]->room1);
		if (in->matrix[i][room] && check(arr, ind, i))
		{
			recursion(in, arr, ind + 1, i);
		}
		i++;
	}
}

int			find_all_ways(t_info *in, int last)
{
	int	i;
	int	*arr;

	i = 0;
	while (in->rooms[i])
		i++;
	arr = (int *)malloc(sizeof(int) * i);
	build_matrix(in);
	recursion(in, arr, 0, in->start);
	free(arr);
	if (in->ways == NULL)
		return (0);
	create_diffs(in);
	find_diffs(in);
	get_best_ways(in);
	return (last);
}

