/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_contains.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 22:37:03 by oredoine          #+#    #+#             */
/*   Updated: 2023/05/18 23:54:40 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_map_contains(char **lines, t_data *data)
{
	int i;
	int j;
	t_count characters  = {0,0,0};
	i = 0;
	while(lines[i])
	{
		j = 0;
		while (lines[i][j])
		{	
			if(lines[i][j] == 'P')
			{
				data->player.x = j;
				data->player.y = i;
				characters.player++; 
			}	
			else if(lines[i][j] == 'C')
				characters.collectible++;
			else if(lines[i][j] == 'E')
			{
				data->e.x = j;
				data->e.y = i; 
				characters.exit++;
			}
			j++;
		}
	i++;
	}
	if(characters.collectible == 0 || characters.exit != 1 || characters.player != 1)
		{ft_perror();}
}
