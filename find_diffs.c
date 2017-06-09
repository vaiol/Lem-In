#include "lemin.h"

static t_diff	*create_diff(int *arr, int maxlen)
{
	t_diff	*diff;
	int		i;

	diff = (t_diff *)malloc(sizeof(t_diff));
	diff->ways = (int *)malloc(sizeof(int) * maxlen);
	diff->len = maxlen;
	i = 0;
	while (i < diff->len)
	{
		diff->ways[i] = arr[i];
		i++;
	}
	return (diff);
}

static int		add_diff(t_info *in, int *arr, int maxlen)
{
	t_diff	**diffs;
	int		i;
	int		len;

	len = 0;
	while (in->diffs && in->diffs[len])
		len++;
	diffs = (t_diff **)malloc(sizeof(t_diff *) * (len + 2));
	i = 0;
	while (i < len)
	{
		diffs[i] = in->diffs[i];
		i++;
	}
	diffs[i] = create_diff(arr, maxlen);
	diffs[i + 1] = NULL;
	if (in->diffs)
		free(in->diffs);
	in->diffs = diffs;
	return (i);
}

static int		is_parallel(t_info *in, int w1, int w2)
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

static int		is_parallel_ways(t_info *in, int *arr, int len, int way)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (!is_parallel(in, arr[i], way))
			return (0);
		i++;
	}
	return (1);
}

static void	recursion(t_info *in, int *arr, int len, int way)
{
	int	flag;
	int	i;

	arr[len++] = way;
	flag = 1;
	i = 0;
	while (in->ways[i])
	{
		if (is_parallel_ways(in, arr, len, i))
		{
			recursion(in, arr, len, i);
			flag = 0;
		}
		i++;
	}
	if (flag)
		add_diff(in, arr, len);
}

void		find_diffs(t_info *in)
{
	int	i;
	int	*arr;

	i = 0;
	while (in->ways[i])
		i++;
	arr = (int *)malloc(sizeof(int) * i);
	i = 0;
	while (in->ways[i])
	{
		recursion(in, arr, 0, i);
		i++;
	}
	free(arr);
}

