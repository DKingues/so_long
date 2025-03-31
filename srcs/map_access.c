/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_access.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:08:53 by dicosta-          #+#    #+#             */
/*   Updated: 2025/03/31 16:34:24 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// transforms map into char **

char	**get_full_map(char *map)
{
	int		fd;
	int		i;
	int		size;
	char	**full_map;

	fd = open(map, O_RDONLY);
	i = 0;
	full_map = malloc(sizeof(char *) * last_line(map));
	if (!full_map)
		return (free(full_map), close(fd), NULL);
	while (i <= last_line(map))
		full_map[i++] = get_next_line(fd);
	return (close(fd), full_map);
}

// map_access will check if the exit is accessible
// from player start position

// Starts in point of P and checks if all C and E are accessible through\
// flood fill algorithm

bool	map_access(char **map, t_game *game)
{
	char	**temp_map;

	temp_map = map;
	flood_fill(temp_map, game->player.y, game->player.x, game);
	if (game->map.e == 0 && game->map.c == 0 && game->map.p == 0)
		return (true);
	return (false);
}

void	flood_fill(char **temp_map, int y, int x, t_game *game)
{
	if (x < 0 || x >= game->map.width || y < 0 || y >= game->map.height)
		return ;
	if (temp_map[y][x] == 'C' || temp_map[y][x] == 'E' || temp_map[y][x] == 'P'
		|| temp_map[y][x] == '0')
	{
		if (temp_map[y][x] == 'E')
			game->map.e--;
		if (temp_map[y][x] == 'C')
			game->map.c--;
		if (temp_map[y][x] == 'P')
			game->map.p--;
		temp_map[y][x] = '-';
		flood_fill(temp_map, y + 1, x, game);
		flood_fill(temp_map, y - 1, x, game);
		flood_fill(temp_map, y, x + 1, game);
		flood_fill(temp_map, y, x - 1, game);
	}
}
