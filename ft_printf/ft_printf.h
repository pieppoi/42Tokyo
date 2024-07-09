/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaz <kaz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:19:47 by mkazuhik          #+#    #+#             */
/*   Updated: 2024/07/09 23:32:46 by kaz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

char	*ft_alltolower(char *c);
char	*ft_base_point(unsigned long long p, int b);
int		ft_count_out(const char *save, va_list arg);
int		ft_printf(const char *inp, ...);
int		ft_putstr_c(char *c);
int		ft_something_treat(int c, va_list arg);
int		ft_treat_char(char c);
int		ft_treat_hex(unsigned int t, int f);
int		ft_treat_int(int i);
int		ft_treat_point(unsigned long long point);
int		ft_treat_string(char *str);
int		ft_treat_uint(unsigned long long u);

#endif