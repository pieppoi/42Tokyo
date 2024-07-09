/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaz <kaz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:43:38 by mkazuhik          #+#    #+#             */
/*   Updated: 2024/07/09 13:15:18 by kaz              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main() {
    int fd = open("test.txt", O_RDONLY); // ファイルを読み込み専用で開く
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    char *line;
	// line = get_next_line(fd);
	// printf("%s\n", line);
	if ((line = get_next_line(fd)) == NULL)
	{
		printf("not find next line");
	}
    while ((line = get_next_line(fd)) != NULL)
	{
        printf("%s", line);
        free(line);
    }
	printf("\n");
    close(fd); // ファイルを閉じる
    return 0;
}



// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
// }