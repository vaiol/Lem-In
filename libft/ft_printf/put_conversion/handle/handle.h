/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:37:44 by astepano          #+#    #+#             */
/*   Updated: 2017/03/10 17:41:18 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_H
# define HANDLE_H
# define FLOAT_SIZE 1024

# include "../util/util.h"

typedef struct	s_time
{
	int			year;
	int			month;
	int			day;
	int			hour;
	int			min;
	int			sec;
}				t_time;

char			*handle_minwidth(t_conversion *conv, char *str, size_t margin);
char			*handle_precision(t_conversion *c, char *str, int l, size_t m);
t_time			*handle_time(const unsigned long long time);
char			*handle_apostrophe(char *nbr);
char			*handle_a(long double nbr, t_conversion *c);
char			*create_time(char *t1, int n2, char *delim);
void			ftoa_conv(char *outstr, long double nbr, t_conversion *c);

#endif
