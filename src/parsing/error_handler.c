/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 20:03:00 by oredoine          #+#    #+#             */
/*   Updated: 2023/05/26 20:28:48 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_coin_error(void)
{
	perror("Error : Can't find collectible in your map");
	exit (1);
}

void	ft_exit_error(void)
{
	perror("Error : There is a problem with your exit");
	exit (1);
}

void	ft_player_error(void)
{
	perror("Error : There is a problem with your player");
	exit (1);
}

void	ft_expected_errors(t_data *data, t_count *characters)
{
	if (data->collectible == 0)
		ft_coin_error();
	else if (characters->exit != 1)
		ft_exit_error();
	else if (characters->player != 1)
		ft_player_error();
}

void	ft_perror(void)
{
	perror("INVALID MAP");
	exit(1);
}
