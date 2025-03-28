/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:56:24 by dicosta-          #+#    #+#             */
/*   Updated: 2025/03/28 18:16:33 by dicosta-         ###   ########.fr       */
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

typedef struct s_map
{
	int	e;
	int	c;
	int	p;
	int	height;
	int	width;
}	t_map;

typedef struct s_data
{
	void	*img;
	char	*path;
	int		width;
	int		height;
	int		x;
	int		y;
	
}	t_data;

typedef struct s_game
{
	t_map	map;
	t_data	player;
	t_data	collect;
	t_data	exit;
	t_data	floor;
	t_data	walls;
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

// MAP ACCESS (map_access.c)

bool	map_access(char **map, t_game *game);
void	flood_fill(char **map, int y, int x, t_game *game);

// MAP ACCESS AUX (map_access_aux.c)

char	**get_full_map(char *map);

#endif