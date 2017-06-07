/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 01:44:01 by astepano          #+#    #+#             */
/*   Updated: 2017/04/02 01:44:03 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	remove_vertices(t_info *in, int w)
{
	int	j;
	int	i;

	i = 0;
	while (i < in->ways[w]->len)
	{
		if (in->ways[w]->way[i] != in->start && in->ways[w]->way[i] != in->end)
		{
			j = 0;
			while (j < in->size)
			{
				in->matrix[in->ways[w]->way[i]][j] = 0;
				in->matrix[j][in->ways[w]->way[i]] = 0;
				j++;
			}
		}
		i++;
	}
}

char	**clean_input(char **file)
{
	char	**input;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (file && file[i])
		i++;
	input = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (file && file[i])
	{
		if (iscommand(file[i]) && file[i + 1])
		{
			input[j++] = file[i++];
			input[j++] = file[i++];
		}
		else if (iscomment(file[i]))
			i++;
		else
			input[j++] = file[i++];
	}
	input[j] = NULL;
	return (input);
}

t_info	*create_info(char **file)
{
	t_info	*in;

	in = (t_info *)malloc(sizeof(t_info));
	in->ants_count = -1;
	in->start = -1;
	in->end = -1;
	in->rooms = NULL;
	in->links = NULL;
	in->ways = NULL;
	in->ants = NULL;
	in->matrix = NULL;
	in->input = clean_input(file);
	return (in);
}

char	**read_file(void)
{
	char	**input;
	char	*file;

	file = ft_readfd(FD);
	input = ft_strsplit(file, '\n');
	free(file);
	return (input);
}

void	write_file(char **file, int last_line)
{
	int	i;

	i = 0;
	if (last_line == 0)
	{
		ft_printf("ERROR\n");
		return ;
	}
	while (file[i])
	{
		if (iscomment(file[i]))
			last_line++;
		if (i < last_line)
			ft_printf("%s\n", file[i]);
		free(file[i]);
		i++;
	}
	free(file);
}
