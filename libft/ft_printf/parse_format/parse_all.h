/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_all.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 20:41:45 by astepano          #+#    #+#             */
/*   Updated: 2017/04/02 18:51:26 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_ALL_H
# define PARSE_ALL_H

# include "../ft_printf.h"

size_t	pf_parse_flags(const char *f, size_t i, t_conversion *form);
size_t	pf_parse_type(const char *f, size_t i, t_conversion *form);
size_t	pf_parse_minwidth(const char *f, size_t i, t_conversion *form,
		va_list v);
size_t	pf_parse_precision(const char *f, size_t i, t_conversion *form,
		va_list v);
size_t	pf_parse_size(const char *f, size_t i, t_conversion *form);
size_t	pf_parse_brace(const char *f, size_t i, va_list valist);
size_t	pf_free_brace(char **colors, char **escapes, size_t i);

#endif
