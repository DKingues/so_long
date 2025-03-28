/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:03:04 by dicosta-          #+#    #+#             */
/*   Updated: 2024/12/04 21:09:46 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	linelen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tmp;
	size_t			i;
	size_t			check;

	i = 0;
	check = count * size;
	if (count && (check / count) != size)
		return (NULL);
	tmp = malloc(count * size);
	if (!tmp)
		return (NULL);
	if (count == 0 || size == 0)
		return (tmp);
	while (i < count * size)
	{
		tmp[i] = 0;
		i++;
	}
	return (tmp);
}

char	*ft_strjoin(char *buff, char *line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = ft_calloc((linelen(buff) + linelen(line) + 1), sizeof(char));
	if (!str)
		return (free(line), NULL);
	while (line && line[i])
	{
		str[i] = line[i];
		i++;
	}
	while (buff[j] && buff[j] != '\n')
		str[i++] = buff[j++];
	if (buff[j] == '\n')
		str[i] = '\n';
	if (line)
		free(line);
	return (str);
}

char	*buffer_clean(char *buffer)
{
	int	i;
	int	j;

	j = linelen(buffer);
	i = 0;
	while (j < BUFFER_SIZE)
		buffer[i++] = buffer[j++];
	while (i < BUFFER_SIZE)
		buffer[i++] = '\0';
	return (buffer);
}
