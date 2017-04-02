/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:44:27 by astepano          #+#    #+#             */
/*   Updated: 2017/04/02 19:08:58 by astepano         ###   ########.fr       */
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

char			*pf_utoa_base(unsigned long long value, int b, char size,
		int hash);
char			*pf_winttostr(wint_t wint);
char			*pf_wstrtostr(wchar_t *s, int max_len);
char			*pf_strjoinchr(char *str, char const chr, int count,
		t_position position);
char			*pf_strjoinchr_begin(char *str, char const chr, int count,
		size_t margin);
char			*pf_strclear(char *str);
char			*pf_zerocut(char *nbr);

#endif
