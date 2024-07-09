/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaz <kaz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 20:00:41 by mkazuhik          #+#    #+#             */
/*   Updated: 2024/07/09 23:32:59 by kaz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_treat_hex(unsigned int t, int f)
{
	char	*str;
	int		count;

	str = ft_base_point((unsigned long long)t, 16);
	if (f == 1)
	{
		ft_alltolower(str);
	}
	count = ft_putstr_c(str);
	free(str);
	return (count);
}
