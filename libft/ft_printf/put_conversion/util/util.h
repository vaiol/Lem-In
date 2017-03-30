/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:44:27 by astepano          #+#    #+#             */
/*   Updated: 2017/03/10 17:47:15 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "../../ft_printf.h"

typedef enum	e_position
{
	BEGIN,
	END
}				t_position;

char			*utoa_base(unsigned long long value, int b, char size,
		int hash);
char			*winttostr(wint_t wint);
char			*wstrtostr(wchar_t *s, int max_len);
char			*strjoinchr(char *str, char const chr, int count,
		t_position position);
char			*strjoinchr_begin(char *str, char const chr, int count,
		size_t margin);
char			*strclear(char *str);
char			*zerocut(char *nbr);

#endif
