/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaz <kaz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:40:08 by mkazuhik          #+#    #+#             */
/*   Updated: 2024/07/09 23:36:21 by kaz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

// int	main (void)
// {
// 	t_list *list = NULL;
// 	int	i;

//     ft_lstadd_front(&list, ft_lstnew("0"));
//     ft_lstadd_front(&list, ft_lstnew("1"));
//     ft_lstadd_front(&list, ft_lstnew("2"));
// 	i = ft_lstsize(list);
// 	printf ("%d\n", i);
// }
