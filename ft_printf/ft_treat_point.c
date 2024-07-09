/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:57:08 by mkazuhik          #+#    #+#             */
/*   Updated: 2024/05/14 19:40:41 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_treat_point(unsigned long long point)
{
	char	*p;
	int		n;

	p = ft_alltolower(ft_base_point(point, 16));
	n = ft_putstr_c("0x");
	n += ft_putstr_c(p);
	free(p);
	return (n);
}
