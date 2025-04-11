/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:39:36 by dicosta-          #+#    #+#             */
/*   Updated: 2025/04/11 19:17:06 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// init_window will create a window with the correct dimensions
// load all images to each t_data and loop for the game to be played

void	init_window(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map.width * 64, game->map.height * 64, "GAME");
	game->player.img = mlx_xpm_file_to_image(game->mlx, "textures/64Player.xpm", &game->map.width, &game->map.height);
	game->player.path = mlx_get_data_addr(game->player.img, &game->player.bits_per_pixel, &game->player.line_length, &game->player.endian);
	game->floor = load_image("textures/64Floor.xpm", game);
	game->walls = load_image("textures/64Walls.xpm", game);
	game->collect = load_image("textures/64Collect.xpm", game);
	game->exit = load_image("textures/64Exit.xpm", game);
	find_e(game);
	game->canvas = load_image(NULL, game);	
	ins_map(game);
	mlx_put_image_to_window(game->mlx, game->win, game->canvas.img, 0, 0);
	refresh_sprites(game->map.map, game);
	mlx_hook(game->win, 01, 1l >> 0, key_management, game);
	mlx_key_hook(game->win, key_management, game);
	mlx_hook(game->win, 17, 0, close_window, game);
	mlx_loop(game->mlx);
}

// close_window will close the window and free all allocated memory

int	close_window(t_game *game)
{
	mlx_destroy_image(game->mlx, game->player.img);
	mlx_destroy_image(game->mlx, game->floor.img);
	mlx_destroy_image(game->mlx, game->collect.img);
	mlx_destroy_image(game->mlx, game->exit.img);
	mlx_destroy_image(game->mlx, game->canvas.img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	big_free(game);
	exit(0);
}

// refresh_sprites will run after each movement so change sprite locations

void	refresh_sprites(char **map, t_game *game)
{
	int y;
	int x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P' )
				put_img(game, game->player.img, x * 64, y * 64);
			if (map[y][x] == 'C')
				put_img(game, game->collect.img, x * 64, y * 64);
			if (map[y][x] == '0')
				put_img(game, game->floor.img, x * 64, y * 64);	
			x++;
		}
		y++;
	}	
}

void find_e(t_game *game)
{
	while (game->map.map[game->exit.y])
	{
		game->exit.x = 0;
		while (game->map.map[game->exit.y][game->exit.x])
		{
			if (game->map.map[game->exit.y][game->exit.x] == 'E')
				return ;
			game->exit.x++;
		}
		game->exit.y++;
	}
}

// put_img

void	put_img(t_game *game, void *img, int width, int height)
{
	mlx_put_image_to_window(game->mlx, game->win, img, width, height );
}