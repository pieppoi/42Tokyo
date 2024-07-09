/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkazuhik <mkazuhik@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 19:15:01 by mkazuhik          #+#    #+#             */
/*   Updated: 2024/05/14 19:45:16 by mkazuhik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_treat_int(int i)
{
	char	*str;
	int		n;

	str = ft_itoa(i);
	n = ft_putstr_c(str);
	free(str);
	return (n);
}
