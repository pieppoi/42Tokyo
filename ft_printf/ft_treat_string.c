/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaz <kaz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 15:50:33 by mkazuhik          #+#    #+#             */
/*   Updated: 2024/07/09 23:32:13 by kaz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_treat_string(char *str)
{
	int	n;

	if (str == NULL)
		str = "(null)";
	n = ft_strlen(str);
	ft_putstr_fd(str, 1);
	return (n);
}
