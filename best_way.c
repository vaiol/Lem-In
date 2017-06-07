#include "lemin.h"

static int	get_bestway(t_info *in, int diff)
{
	int best;
	int	min;
	int	i;
	int	way;

	best = 0;
	min = in->ways[0]->len + in->ways[0]->ants;
	i = 0;
	while (i < in->diffs[diff]->len)
	{
		way = in->diffs[diff]->ways[i];
		if (min > (in->ways[way]->len + in->ways[way]->ants))
		{
			best = i;
			min = in->ways[way]->len + in->ways[way]->ants;
		}
		i++;
	}
	return (best);
}

static void	clean_ways(t_info *in, int diff)
{
	int way;
	int i;

	i = 0;
	while (i < in->diffs[diff]->len)
	{
		way = in->diffs[diff]->ways[i];
		in->ways[way]->ants = 0;
		i++;
	}
}

static int	get_count_steps(t_info *in, int diff)
{
	int way;
	int	i;
	int	steps;
	int	max_steps;


	i = 0;
	while (i < in->ants_count)
	{
		way = get_bestway(in, diff);
		in->ways[way]->ants++;
		i++;
	}
	i = 0;
	max_steps = -1;
	while (i < in->diffs[diff]->len)
	{
		way = in->diffs[diff]->ways[i];
		steps = in->ways[way]->ants + in->ways[way]->len - 2;
		if (max_steps < steps)
			max_steps = steps;
		i++;
	}
	return (max_steps);
}

static int	get_best_diff(t_info *in)
{
	int	i;
	int	steps;
	int	min_steps;
	int	best;

	min_steps = INFINITY;
	best = -1;
	i = 0;
	while (in->diffs[i])
	{
		steps = get_count_steps(in, i);
		if (steps < min_steps)
		{
			min_steps = steps;
			best = i;
		}
		clean_ways(in, i);
		i++;
	}
	return (best);
}

void	clean_unused_ways(t_info *in, int best)
{
	int	i;
	int	j;
	int	clean;

	i = 0;
	while (in->ways[i])
	{
		clean = 1;
		j = 0;
		while (j < in->diffs[best]->len)
		{
			if (in->diffs[best]->ways[j] == i)
			{
				clean = 0;
				break ;
			}
			j++;
		}
		if (clean)
			free(in->ways[i]);
		i++;
	}
	free(in->ways);
}

void	get_best_ways(t_info *in)
{
	t_way	**ways;
	int		best;
	int		i;

	best = get_best_diff(in);
	ways = (t_way **)malloc(sizeof(t_way *) * (in->diffs[best]->len + 1));
	i = 0;
	while (i < in->diffs[best]->len)
	{
		ways[i] = in->ways[in->diffs[best]->ways[i]];
		in->ways[in->diffs[best]->ways[i]] = NULL;
		i++;
	}
	ways[i] = NULL;
	clean_unused_ways(in, best);
	in->ways = ways;
}
