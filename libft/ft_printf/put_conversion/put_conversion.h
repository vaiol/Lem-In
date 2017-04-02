/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_conversion.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 19:04:24 by astepano          #+#    #+#             */
/*   Updated: 2017/04/02 19:04:25 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUT_CONVERSION_H
# define PUT_CONVERSION_H

# include "handle/handle.h"

void	pf_put_char(t_conversion *conv, va_list valist);
void	pf_put_string(t_conversion *conv, va_list valist);
void	pf_put_unsigned(t_conversion *conv, unsigned long long number);
void	pf_put_signed(t_conversion *conv, long long number);
void	pf_put_memory(t_conversion *conv, va_list valist);
void	pf_put_printed(t_conversion *conv, va_list valist);
void	pf_put_float(t_conversion *conv, va_list valist);
void	pf_put_unprintable(t_conversion *conv, va_list valist);

#endif
