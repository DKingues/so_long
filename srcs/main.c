/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:56:09 by dicosta-          #+#    #+#             */
/*   Updated: 2025/03/31 19:03:22 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_stack(char **map, t_game *game)
{
	game->map = (t_map){.map = map, .e = 0, .c = 0, .p = 0, .height = 0, .width = 0};
	game->player = (t_data){.x = 0, .y = 0};
}

void	init_window(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map.width * 64, game->map.height * 64, "GAME");
	game->player = load_image("textures/player.xpm", game);
	game->floor = load_image("textures/floor.xpm", game);
	game->walls = load_image("textures/walls.xpm", game);
	game->canvas.img = mlx_new_image(game->mlx, game->map.width * 64, game->map.height * 64);
	game->canvas.path = mlx_get_data_addr(game->canvas.img, &game->canvas.bits_per_pixel, &game->canvas.line_length, &game->canvas.endian);
	ins_map(game);
	mlx_put_image_to_window(game->mlx, game->win, game->canvas.img, 0, 0);
	//mlx_new_image(mlx, game->map.width, game->map.height);
	mlx_loop(game->mlx);
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
