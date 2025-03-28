/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:56:12 by dicosta-          #+#    #+#             */
/*   Updated: 2025/03/28 18:15:00 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// map_exists Checks if map file exists and if its empty.

bool	map_exists(char *map)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return (false);
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	if (i < 1)
		return (free(line), close(fd), false);
	return (free(line), close(fd), true);
}
// map_ECP Checks if theres a correct amount of Exits, Collectibles and Players.

bool	map_ecp(char **map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				game->map.e++;
			if (map[i][j] == 'P')
				game->map.p++;
			if (map[i][j] == 'P')
				game->player = (t_data){.y = i, .x = j};
			if (map[i][j] == 'C')
				game->map.c++;
			j++;
		}
		i++;
	}
	if (game->map.e == 1 && game->map.p == 1 && game->map.c > 0)
		return (true);
	return (false);
}
// map_border check if map is enclosed in walls.

bool	map_border(char **map, t_game *game)
{
	int	i;

	i = 0;
	game->map.height = 0;
	while (map[i])
	{
		if (game->map.height == 0 || map[i + 1] == NULL)
		{
			if (x_border_check(map[i]) == false)
				return (false);
		}
		else
		{
			if (y_border_check(map[i]) == false)
				return (false);
		}
		game->map.height++;
		i++;
	}
	return (true);
}

// map_form checks if map is rectangular && lines are same lenght;

bool	map_form(char **map, t_game *game)
{
	int	i;

	i = 0;
	game->map.width = line_len(map[i]);
	while (map[i])
	{
		if (line_len(map[i]) != game->map.width)
			return (false);
		i++;
	}
	return (true);
}
// map_parsing runs all the above functions to check if the map is usable.

bool	map_parsing(char **map, t_game *game)
{
	if (map_ecp(map, game) == false)
		return (ft_printf("ERROR: Invalid ECP count.\n"), false);
	if (map_border(map, game) == false)
		return (ft_printf("ERROR: Invalid map border.\n"), false);
	if (map_form(map, game) == false)
		return (ft_printf("ERROR: Map is not rectangular.\n"), false);
	if (map_access(map, game) == false)
		return (ft_printf("ERROR: Exit/Collectibles not accessible.\n"), false);
	return (true);
}
