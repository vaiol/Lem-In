/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_conversion.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astepano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 17:32:17 by astepano          #+#    #+#             */
/*   Updated: 2017/03/10 17:32:31 by astepano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUT_CONVERSION_H
# define PUT_CONVERSION_H

# include "handle/handle.h"

void	put_char(t_conversion *conv, va_list valist);
void	put_string(t_conversion *conv, va_list valist);
void	put_unsigned(t_conversion *conv, unsigned long long number);
void	put_signed(t_conversion *conv, long long number);
void	put_memory(t_conversion *conv, va_list valist);
void	put_printed(t_conversion *conv, va_list valist);
void	put_float(t_conversion *conv, va_list valist);
void	put_unprintable(t_conversion *conv, va_list valist);

#endif
