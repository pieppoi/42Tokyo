#include "get_next_line.h"

// static char	*next_line(int fd, char *save, char *buf)
// {
// 	char	*tmp;
// 	ssize_t	readlen;

// 	readlen = 1;
// 	while (readlen != '\0')
// 	{
// 		readlen = read(fd, buf, BUFFER_SIZE);
// 		if ((readlen == -1) || (readlen == 0 && save[0] == '\0'))
// 			return (NULL);
// 		buf[readlen] = '\0';
// 		if (!save)
// 			save = ft_strdup("");
// 		tmp = save;
// 		save = ft_strjoin(tmp, buf);
// 		free(tmp);
// 		tmp = NULL;
// 		if (ft_strchr(buf, '\n'))
// 			break ;
// 	}
// 	return (save);
// }

// static char	*next_save(char *str)
// {
// 	size_t	count;
// 	char	*tmp;

// 	count = 0;
// 	while (str[count] != '\n' && str[count] != '\0')
// 		count++;
// 	if (str[count] == '\0' || str[1] == '\0')
// 		return (NULL);
// 	tmp = ft_substr(str, count + 1, ft_strlen(str) - count);
// 	if (*tmp == '\0')
// 	{
// 		free(tmp);
// 		tmp = NULL;
// 	}
// 	str[count + 1] = '\0';
// 	return (tmp);
// }

// char	*get_next_line(int fd)
// {
// 	char		*str;
// 	char		*buf;
// 	static char	*save;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	if (!buf)
// 		return (NULL);
// 	if (!save)
// 	{
// 		save = ft_strdup("");
// 		if (!save)
// 			return (NULL);
// 	}
// 	str = next_line(fd, save, buf);
// 	free (buf);
// 	buf = NULL;
// 	if (!str)
// 		return (NULL);
// 	save = next_save(str);
// 	return (str);
// }