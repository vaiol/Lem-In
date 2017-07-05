/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 16:32:12 by astepano          #+#    #+#             */
/*   Updated: 2017/06/20 16:32:13 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

char	**read_file(void)
{
	char	**input;
	char	*file;

	file = ft_readfd(FD);
	input = ft_strsplit(file, '\n');
	free(file);
	return (input);
}
