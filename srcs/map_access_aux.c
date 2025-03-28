/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_access_aux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicosta- <dicosta-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:23:07 by dicosta-          #+#    #+#             */
/*   Updated: 2025/03/27 18:21:19 by dicosta-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
