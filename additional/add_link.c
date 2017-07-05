/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/20 16:31:19 by astepano          #+#    #+#             */
/*   Updated: 2017/06/20 16:31:40 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lemin.h"

int		add_link(t_info *in, int room1, int room2)
{
	t_link	**links;
	int		i;
	int		len;

	len = 0;
	while (in->links && in->links[len])
		len++;
	links = (t_link **)malloc(sizeof(t_link *) * (len + 2));
	i = 0;
	while (i < len)
	{
		links[i] = in->links[i];
		i++;
	}
	links[i] = (t_link *)malloc(sizeof(t_link));
	links[i]->room1 = room1;
	links[i]->room2 = room2;
	links[i + 1] = NULL;
	if (in->links)
		free(in->links);
	in->links = links;
	return (i);
}
