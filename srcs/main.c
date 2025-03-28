/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:56:09 by dicosta-          #+#    #+#             */
/*   Updated: 2025/03/28 18:15:30 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_stack(char **map, t_game *game)
{
	game->map = (t_map){.e = 0, .c = 0, .p = 0, .height = 0, .width = 0};
	game->player = (t_data){.x = 0, .y = 0};
}

void	init_window(t_game *game)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, game->map.width * 128, game->map.height * 128, "GAME");
	mlx_new_image(mlx, game->map.width, game->map.height);
	mlx_loop(mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;
	char	**map;

	if (argc == 2)
	{
		if (map_exists(argv[1]) == false)
			return (ft_printf("ERROR: Invalid map file.\n"), false);
		else
			map = get_full_map(argv[1]);
		init_stack(map, &game);
		if (map_parsing(map, &game) == false)
			return (0);
		else
		{
			ft_printf("Map loaded\n");
			init_window(&game);
			
		}
	}
	return (free(map), 0);
}
