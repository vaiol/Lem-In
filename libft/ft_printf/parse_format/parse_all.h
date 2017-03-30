/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_all.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 20:41:45 by astepano          #+#    #+#             */
/*   Updated: 2017/03/07 20:41:46 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_ALL_H
# define PARSE_ALL_H

# include "../ft_printf.h"

size_t	parse_flags(const char *f, size_t i, t_conversion *form);
size_t	parse_type(const char *f, size_t i, t_conversion *form);
size_t	parse_minwidth(const char *f, size_t i, t_conversion *form, va_list v);
size_t	parse_precision(const char *f, size_t i, t_conversion *form, va_list v);
size_t	parse_size(const char *f, size_t i, t_conversion *form);
size_t	parse_brace(const char *f, size_t i, va_list valist);

#endif
