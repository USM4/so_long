/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:24:52 by oredoine          #+#    #+#             */
/*   Updated: 2023/05/25 19:21:07 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void ft_move_left(t_data *data)
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
				if(data->lines[i][j - 1] == '0' || data->lines[i][j - 1] == 'C')
				{
					if (data->lines[i][j - 1] == 'C')
						data->collectible--;
					data->player.x = j - 1;
					data->player.y = i;
					data->lines[i][j - 1] = 'P';
					data->lines[i][j] = '0';
				}
				else if(data->lines[i][j - 1] == '1')
					return;
				else if (data->lines[i][j - 1] == 'E' && data->collectible == 0)
				{
					ft_clean(data->lines);
					exit(0);
				}
				return ;
			}
			j++;
		}
		i++;
	}	
}