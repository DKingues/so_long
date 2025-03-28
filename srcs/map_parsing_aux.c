/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_aux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:25:03 by dicosta-          #+#    #+#             */
/*   Updated: 2025/03/27 18:26:23 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Checks horizontal borders

bool	x_border_check(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1')
			return (false);
		i++;
	}
	return (true);
}
// Checks vertical borders

bool	y_border_check(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[0] == '1' && line[i - 1] == '1')
		return (true);
	else
		return (false);
}
// Gets last line of array

int	last_line(char *map)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	return (free(line), close(fd), i);
}
// Gets string lenght

int	line_len(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}
