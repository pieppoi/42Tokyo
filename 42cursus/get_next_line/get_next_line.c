/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaz <kaz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 16:28:54 by mkazuhik          #+#    #+#             */
/*   Updated: 2024/07/05 21:56:11 by kaz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*next_line(int fd, char *save, char *buf)
{
	char	*tmp;
	ssize_t	readlen;

	readlen = 1;
	while (!ft_strchr(buf, '\n') && readlen != '\0')
	{
		readlen = read(fd, buf, BUFFER_SIZE);
		// if (readlen == -1)
		// 	return (0);
		// else if (readlen == 0)
		// 	break ;
		if (readlen == -1 || (readlen == 0 && save[0] == '\0'))
			return (NULL);
		buf[readlen] = '\0';
		if (!save)
			save = ft_strdup("");
		tmp = save;
		save = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = NULL;
	}
	return (save);
}

char	*next_save(char *save)
{
	size_t	count;
	char	*tmp;

	count = 0;
	while (save[count] != '\0' && save[count] != '\n')
		count++;
	if (save[count] == '\0' || save[1] == '\0')
		return (NULL);
	tmp = ft_substr(save, count + 1, ft_strlen(save) - count);
	if (*tmp == '\0')
	{
		free(save);
		return (NULL);
	}
	save[count + 1] = '\0';
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*str;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	if (!save)
	{
		save = ft_strdup("");
		if (!save)
			return (NULL);
	}
	str = next_line(fd, save, buf);
	free (buf);
	buf = NULL;
	if (!str)
		return (NULL);
	save = next_save(str);
	return (str);
}
