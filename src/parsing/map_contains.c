/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_contains.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 22:37:03 by oredoine          #+#    #+#             */
/*   Updated: 2023/05/25 20:24:44 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void ft_coin_error(void)
{
	perror("Error : Can't find collectible in your map");
	exit (1);
}

static void ft_exit_error(void)
{
	perror("Error : There is a problem with your exit");
	exit (1);
}

static void ft_player_error(void)
{
	perror("Error : There is a problem with your player");
	exit (1);
}

static void ft_expected_errors(t_data *data, t_count *characters)
{
	if(data->collectible == 0 )
		ft_coin_error();
	else if (characters->exit != 1)
		ft_exit_error();
	else if (characters->player != 1)
		ft_player_error();
}
void ft_validate_map(char **lines, t_data *data)
{
	int i;
	int j;
	t_count characters  = {0,0};
	i = 0;
	data->collectible = 0;
	while(lines[i])
	{
		j = -1;
		while (lines[i][j + 1])
		{	
			j++;
			if(lines[i][j] == 'P')
			{
				data->player.x = j;
				data->player.y = i;
				characters.player++; 
			}	
			else if(lines[i][j] == 'C')
			{
				data->collectible++;
			}
			else if(lines[i][j] == 'E')
			{
				data->e.x = j;
				data->e.y = i; 
				characters.exit++;
			}
			else if(lines[i][j] == '1' || lines[i][j] == '0')
				continue;
			else
				ft_perror();
		}
		i++;
	}
	ft_expected_errors(data, &characters);
}