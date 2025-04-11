/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 12:38:05 by dicosta-          #+#    #+#             */
/*   Updated: 2025/04/11 16:42:43 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// key_management will check which key was pressed and change the map
// accordingly

int	key_management(int keycode, t_game *game)
{
	if (keycode == esc_key)
		close_window(game);
	if (keycode == w_key && game->map.map[game->player.y - 1][game->player.x] != '1')
		w_move(game);
	if (keycode == a_key && game->map.map[game->player.y][game->player.x - 1] != '1')
		a_move(game);
	if (keycode == s_key && game->map.map[game->player.y + 1][game->player.x] != '1')
		s_move(game);
	if (keycode == d_key && game->map.map[game->player.y][game->player.x + 1] != '1')
		d_move(game);
	ft_printf("Collect :[%d]\n", game->map.c);
	ft_printf("X :[%d]\n", game->exit.x);
	ft_printf("Y :[%d]\n", game->exit.y);
	refresh_sprites(game->map.map, game);
	if (game->map.c == 0)
		put_img(game, game->exit.img, game->exit.x * 64, game->exit.y * 64);
	if ((game->player.x == game->exit.x && game->player.y == game->exit.y) && game->map.c == 0)
		close_window(game);
	return (0);
}

void w_move(t_game *game)
{
	game->map.map[game->player.y][game->player.x] = '0';
	game->player.y--;
	if (game->map.map[game->player.y][game->player.x] == 'C')
		game->map.c--;
	// if (game->map.c == 0 && game[game->player.y][game->player.x] == 'E')
	// 	put_img()
	game->map.map[game->player.y][game->player.x] = 'P';
}
void a_move(t_game *game)
{
	game->map.map[game->player.y][game->player.x] = '0';
	game->player.x--;
	if (game->map.map[game->player.y][game->player.x] == 'C')
		game->map.c--;
	game->map.map[game->player.y][game->player.x] = 'P';	
}
void s_move(t_game *game)
{
	game->map.map[game->player.y][game->player.x] = '0';
	game->player.y++;
	if (game->map.map[game->player.y][game->player.x] == 'C')
		game->map.c--;
	game->map.map[game->player.y][game->player.x] = 'P';
}
void d_move(t_game *game)
{
	game->map.map[game->player.y][game->player.x] = '0';
	game->player.x++;
	if (game->map.map[game->player.y][game->player.x] == 'C')
		game->map.c--;
	game->map.map[game->player.y][game->player.x] = 'P';
}
