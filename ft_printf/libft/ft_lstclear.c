/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaz <kaz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:17:08 by mkazuhik          #+#    #+#             */
/*   Updated: 2024/07/09 23:34:54 by kaz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*node;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		node = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = node;
	}
}

// static void	del(void *content)
// {
// 	free(content);
// }

// int main()
// {
//     t_list *list = ft_lstnew(strdup("1"));
//     ft_lstadd_back(&list, ft_lstnew(strdup("2")));
//     ft_lstadd_back(&list, ft_lstnew(strdup("3")));
//     ft_lstclear(&list, del);
//     printf("List cleared.\n");
//     return 0;
// }