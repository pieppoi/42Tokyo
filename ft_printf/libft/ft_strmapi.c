/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaz <kaz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:40:17 by mkazuhik          #+#    #+#             */
/*   Updated: 2024/07/09 23:37:20 by kaz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			str_len;
	char			*a;

	if (!s || !f)
		return (NULL);
	str_len = ft_strlen(s);
	i = 0;
	a = (char *)malloc(str_len + 1);
	if (!a)
		return (NULL);
	while (s[i] != '\0')
	{
		a[i] = (*f)(i, s[i]);
		i++;
	}
	a[i] = '\0';
	return (a);
}

// static char	to_uppercase(unsigned int i, char c)
// {
// 	i = 0;
// 	if (c >= 'a' && c <= 'z')
// 		return (c - 32);
// 	return (c);
// }

// int main() {
// 	const char *str = "hello, world";

// 	printf("%s\n", ft_strmapi(str, to_uppercase));
// 	return (0);
// }