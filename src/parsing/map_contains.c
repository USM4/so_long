/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_contains.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 22:37:03 by oredoine          #+#    #+#             */
/*   Updated: 2023/05/26 20:03:45 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_is_val(t_data *data, int i, int j, t_count *characters)
{
	if (data->lines[i][j] == 'P')
	{
		data->player.x = j;
		data->player.y = i;
		characters->player++;
	}
	else if (data->lines[i][j] == 'C')
		data->collectible++;
	else if (data->lines[i][j] == 'E')
	{
		data->e.x = j;
		data->e.y = i;
		characters->exit++;
	}
}

void	ft_validate_map(t_data *data)
{
	int		i;
	int		j;
	t_count	characters;

	characters = (t_count){0, 0};
	i = 0;
	data->collectible = 0;
	while (data->lines[i])
	{
		j = -1;
		while (data->lines[i][j + 1])
		{	
			j++;
			ft_is_val(data, i, j, &characters);
			if (data->lines[i][j] == '1' || data->lines[i][j] == '0')
				continue ;
			else if (data->lines[i][j] != 'P'
				&& data->lines[i][j] != 'C' && data->lines[i][j] != 'E')
				ft_perror();
		}
		i++;
	}
	ft_expected_errors(data, &characters);
}
