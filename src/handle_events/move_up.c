/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:25:52 by oredoine          #+#    #+#             */
/*   Updated: 2023/05/25 18:36:07 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_move_up(t_data *data)
{
	int i;
	int j;
	
	i = 0;
	while (data->lines[i])
	{
		j = 0;
		while (data->lines[i][j])
		{
			if (data->lines[i][j] == 'P')
			{
				if(data->lines[i - 1][j] == '0' || data->lines[i - 1][j] == 'C')
				{
					if (data->lines[i - 1][j] == 'C')
						data->collectible--;
					data->player.x = j;
					data->player.y = i - 1;
					data->lines[i - 1][j] = 'P';
					data->lines[i][j] = '0';
				}
				else if(data->lines[i - 1][j] == '1')
					return;
				else if (data->lines[i - 1][j] == 'E' && data->collectible == 0)
				{
					ft_clean(data->lines);
					exit(0);
				}
			}
			}
			j++;			
		}
		i++;
}	