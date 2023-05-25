/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:51:09 by oredoine          #+#    #+#             */
/*   Updated: 2023/05/25 19:52:42 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_horizontal_wall(char *line)
{
	int i;

	i = 0;
	while (line[i] && line[i] == '1')
		i++;
	return (ft_strlen(line) == i);
}

void ft_vertical_lines(char **map)
{
	int len;
	int i;

	i = 0;
	len = ft_strlen(map[i]);
	while(map[i])
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			ft_perror();
		i++;
	}
}

void ft_check_entourage(char **map)
{
	int j;

	j = 0;
	while (map[j])
		j++;
	if (!ft_horizontal_wall(map[0]) || !ft_horizontal_wall(map[j - 1]))
		ft_perror();
	ft_vertical_lines(map);
}


void ft_is_rectangular(char **lines)
{
	int first;
	int second;
	int i;

	i = 0;
	first = ft_strlen(lines[i]) - 1;
	i++;
	while(lines[i] != NULL)
	{
		second = ft_strlen(lines[i]) - 1;
		if (second != first)
			ft_perror();
		i++;
	}
}
