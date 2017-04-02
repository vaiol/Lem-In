/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_additional.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 18:49:21 by astepano          #+#    #+#             */
/*   Updated: 2017/04/02 18:49:23 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_all.h"

size_t	pf_free_brace(char **colors, char **escapes, size_t i)
{
	if (colors)
		free(colors);
	if (escapes)
		free(escapes);
	return (i);
}
