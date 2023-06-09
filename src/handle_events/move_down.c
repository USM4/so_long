/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:28:42 by oredoine          #+#    #+#             */
/*   Updated: 2023/05/26 18:54:52 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_move_player_down(t_data *data, int i, int j)
{
	if (data->lines[i + 1][j] == '0' || \
	data->lines[i + 1][j] == 'C')
	{
		if (data->lines[i + 1][j] == 'C')
			data->collectible--;
		data->player.x = j;
		data->player.y = i + 1;
		data->lines[i + 1][j] = 'P';
		data->lines[i][j] = '0';
	}
	else if (data->lines[i + 1][j] == '1')
		return ;
	else if (data->lines[i + 1][j] == 'E' && data->collectible == 0)
	{
		ft_clean(data->lines);
		exit(0);
	}
}

void	ft_move_down(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->lines[i])
	{
		j = 0;
		while (data->lines[i][j])
		{
			if (data->lines[i][j] == 'P')
			{
				ft_move_player_down(data, i, j);
				return ;
			}
			j++;
		}
		i++;
	}	
}
