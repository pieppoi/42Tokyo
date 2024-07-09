/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaz <kaz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:19:06 by mkazuhik          #+#    #+#             */
/*   Updated: 2024/07/09 23:36:05 by kaz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
}

// int main()
// {
// 	t_list *list = NULL;

//     ft_lstadd_back(&list, ft_lstnew("3"));
//     ft_lstadd_back(&list, ft_lstnew("2"));
//     ft_lstadd_back(&list, ft_lstnew("1"));

// 	while (list != NULL)
// 	{
// 		printf("%c -> ", *(char *)list->content);
// 		list = list->next;
// 	}
// 	printf("NULL\n");

// 	return (0);
// }