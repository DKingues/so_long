/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:23:07 by dicosta-          #+#    #+#             */
/*   Updated: 2025/03/31 19:03:15 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	load_image(char *path, t_game *game)
{
	t_data	temp;
	
	temp.img = mlx_xpm_file_to_image(game->mlx, path, &temp.width, &temp.height);
	temp.path = mlx_get_data_addr(temp.img, &temp.bits_per_pixel, &temp.line_length, &temp.endian);
	return (temp);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->path + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	my_mlx_pixel_get(t_data *data, int x, int y)
{
	char	*dst;
	int color;

	dst = data->path + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (color);
}

void	draw_img(t_data src, t_data dst, int sx, int sy)
{
	int	x;
	int	y;

	y = 0;
	while (y < 65)
	{
		x = 0;
		while (x < 65)
		{
			my_mlx_pixel_put(&dst, sx + x, sy + y, my_mlx_pixel_get(&src, x, y));
			x++;
		}
		y++;
	}
}

void	ins_map(t_game *game)
{
	int i;
	int	j;
	
	i = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j])
		{

			if (game->map.map[i][j] == '1')
				draw_img(game->walls, game->canvas, j * 64, i * 64);
			else
				draw_img(game->floor, game->canvas, j * 64, i * 64);
			j++;
		}
		ft_printf("%s", game->map.map[i]);
		i++;
	}
}