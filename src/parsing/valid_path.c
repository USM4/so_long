/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:40:47 by oredoine          #+#    #+#             */
/*   Updated: 2023/05/27 16:24:05 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	fill(char **map, t_count *count, int x, int y)
{
	if (x < 0 || y < 0)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'U' || map[y][x] == 'E')
		return ;
	map[y][x] = 'U';
	fill(map, count, x - 1, y);
	fill(map, count, x + 1, y);
	fill(map, count, x, y - 1);
	fill(map, count, x, y + 1);
}

static void	flood_fill(char **map, t_count *count, t_data *data)
{
	fill(map, count, data->player.x, data->player.y);
}

static void	ft_is_surrounded(char **map, int x, int y)
{	
	if (map[y + 1][x] != 'U' && map[y - 1][x] != 'U' && \
	map[y][x + 1] != 'U' && map[y][x - 1] != 'U')
	{
		perror("Can't access exit");
		exit(1);
	}
}

void	ft_valid_path(char **map, t_data *data)
{
	int		i;
	int		j;
	t_count	count;

	i = 0;
	flood_fill(map, &count, data);
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'E')
				ft_is_surrounded(map, data->e.x, data->e.y);
			else if (map[i][j] == 'C')
			{	
				perror("Can't access collectible");
				exit(1);
			}
			j++;
		}
		i++;
	}
}
