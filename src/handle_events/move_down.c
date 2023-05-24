/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:28:42 by oredoine          #+#    #+#             */
/*   Updated: 2023/05/24 17:06:19 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_move_down(int keycode, t_data *data)
{
	(void)keycode;
	int i;
	int j;
	int n;
	
	i = 0;
	n = 0;
	while (data->lines[i])
	{
		j = 0;
		while (data->lines[i][j])
		{
			if (data->lines[i][j] == 'P')
			{
				n = 1;
				if(data->lines[i + 1][j] == '0' || data->lines[i + 1][j] == 'C')
				{
					if (data->lines[i + 1][j] == 'C')
						data->collectible--;
					data->player.x = j;
					data->player.y = i + 1;
					data->lines[i + 1][j] = 'P';
					data->lines[i][j] = '0';
				}
				else if(data->lines[i + 1][j] == '1')
					return;
				else if(data->lines[i + 1][j] == 'E' && data->collectible == 0)
				{
					ft_clean(data->lines);
					exit(0);
				}
			}
			if (n == 1)
				break;
			j++;			
		}
		i++;
	}	
}
