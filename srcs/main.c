/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:56:09 by dicosta-          #+#    #+#             */
/*   Updated: 2025/04/11 17:30:10 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// init_stack initializes the stack

void	init_stack(char **map, t_game *game)
{
	game->map = (t_map){.map = map, .e = 0, .c = 0, .p = 0, .height = 0, .width = 0};
	game->player = (t_data){.x = 0, .y = 0};
	game->exit = (t_data){.x = 0, .y = 0};
}

// main is where the magic happens

int	main(int argc, char **argv)
{
	t_game	game;
	char	**map;

	map = NULL;
	if (argc == 2)
	{
		if (map_exists(argv[1]) == false)
			return (ft_printf("ERROR: Invalid map file.\n"), false);
		else
			map = get_full_map(argv[1]);
		init_stack(map, &game);
		if (map_parsing(map, &game) == false)
			return (free(map), 0);
		else
		{
			game.map.map = get_full_map(argv[1]);
			ft_printf("Map loaded\n");
			init_window(&game);
		}
	}
	return (free(map), 0);
}
