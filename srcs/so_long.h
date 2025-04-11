/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:56:24 by dicosta-          #+#    #+#             */
/*   Updated: 2025/04/11 17:22:02 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../ft_printf/ft_printf.h"
# include "../gnl/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# define w_key 119
# define a_key 97
# define s_key 115
# define d_key 100
# define esc_key 65307

typedef struct s_map
{
	char	**map;
	int		e;
	int		c;
	int		p;
	int		height;
	int		width;
}	t_map;

typedef struct s_data
{
	void	*img;
	char	*path;
	int		width;
	int		height;
	int		x;
	int		y;
	int		endian;
	int		bits_per_pixel;
	int		line_length;	
}	t_data;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	map;
	t_data	player;
	t_data	collect;
	t_data	exit;
	t_data	floor;
	t_data	walls;
	t_data	canvas;
}	t_game;

// MAP PARSING (map_parsing.c)

bool	map_parsing(char **map, t_game *game);
bool	map_exists(char *map);
bool	map_ecp(char **map, t_game *game);
bool	map_border(char **map, t_game *game);
bool	map_form(char **map, t_game *game);

// MAP PARSING AUX (map_parsing_aux.c)

int		last_line(char *map);
int		line_len(char *line);
bool	x_border_check(char *line);
bool	y_border_check(char *line);
void	big_free(t_game *game);

// MAP ACCESS (map_access.c)

bool	map_access(char **map, t_game *game);
void	flood_fill(char **map, int y, int x, t_game *game);
char	**get_full_map(char *map);

// IMAGE LOAD (draw_image.c)

t_data	load_image(char *path, t_game *game);
void	ins_map(t_game *game);
void	draw_img(t_data src, t_data dst, int sx, int sy);
int		my_mlx_pixel_get(t_data *data, int x, int y);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

// KEY PRESS HANDLING (keys.c)

int		key_management(int keycode, t_game *game);
void	w_move(t_game *game);
void	a_move(t_game *game);
void	s_move(t_game *game);
void	d_move(t_game *game);

// GAME WINDOW MANAGEMENT (game.c)

void	init_window(t_game *game);
int		close_window(t_game *game);
void	put_img(t_game *game, void *img, int width, int height);
void	refresh_sprites(char **map, t_game *game);
void 	find_e(t_game *game);

#endif