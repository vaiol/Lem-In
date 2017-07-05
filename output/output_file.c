/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 16:43:37 by astepano          #+#    #+#             */
/*   Updated: 2017/06/12 16:55:59 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

void	output_file(t_info *in, char **file, int last_line)
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
		if (!in->put_hide && (!in->put_clean
					|| !iscomment(file[i])) && i < last_line)
			ft_printf("%s\n", file[i]);
		free(file[i]);
		i++;
	}
	if (!in->put_hide)
		ft_printf("\n");
	free(file);
}
