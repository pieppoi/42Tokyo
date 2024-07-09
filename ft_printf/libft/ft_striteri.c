/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaz <kaz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:25:16 by mkazuhik          #+#    #+#             */
/*   Updated: 2024/07/09 23:35:07 by kaz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i] != '\0')
	{
		f (i, &s[i]);
		i++;
	}
}

// static void	function(unsigned int i, char *ch)
// {
// 	i = 0;
// 	if (*ch >= 'a' && *ch <= 'z')
// 		*ch = '*';
// }

// int main()
// {
//     char str[] = "string aBcd12";
//     ft_striteri(str, function);
//     printf("%s\n", str); 
//     return 0;
// }