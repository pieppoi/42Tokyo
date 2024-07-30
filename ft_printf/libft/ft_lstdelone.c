/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaz <kaz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 15:41:27 by mkazuhik          #+#    #+#             */
/*   Updated: 2024/07/09 23:36:11 by kaz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

// static void	del(void *content)
// {
// 	free(content);
// }

// int main()
// {
// 	char *content = strdup("Dynamic string content");
//     if (!content) {
//         perror("Failed to allocate content");
//         exit(EXIT_FAILURE);
//     }

//     t_list *node = ft_lstnew(content);
//     if (!node)
// 	{
//         perror("Failed to create list node");
//         free(content);
//         exit(EXIT_FAILURE);
//     }

//     ft_lstdelone(node, del);

//     printf("Node and its content have been deleted\n");

// 	return (0);
// }