/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_aux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 19:25:03 by dicosta-          #+#    #+#             */
/*   Updated: 2025/04/11 17:22:08 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Checks horizontal borders / X border

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
// Checks vertical borders / Y border

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
// Gets last line of array / height

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
// Gets string lenght / width

int	line_len(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}

void big_free(t_game *game)
{
	int y;

	y = 0;
	while (game->map.map[y])
		free(game->map.map[y++]);
	free(game->map.map);
}
