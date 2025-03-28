/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:02:44 by dicosta-          #+#    #+#             */
/*   Updated: 2025/03/15 17:26:57 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	line = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0 || fd > FD_MAX)
		return (NULL);
	while (buffer[0] || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin(buffer, line);
		if (!line)
			return (NULL);
		buffer_clean(buffer);
		if (line[linelen(line) - 1] == '\n')
			break ;
	}
	return (line);
}

// int	main(void)
// {
// 	int	fd = open("gnl.txt", O_RDONLY);
// 	char *line;
// 	int 	i = 0;
// 	while (fd == 2)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 		free(line);
// 		i++;
// 		sleep(1);
// 	}
// }