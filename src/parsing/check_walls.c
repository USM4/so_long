/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:51:09 by oredoine          #+#    #+#             */
/*   Updated: 2023/05/23 08:17:49 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char *ft_check_fl_lines(char *line)
{
	int i;
	i = 0;

	while(line[i] != '\0' && line[i] != '\n')
	{
		if(line[i] != '1')
		ft_perror();
		i++;
	}
	return(line);
}

char **ft_check_middle_lines(char **lines)
{
	int len;
	int i;

	i = 0;
	len = ft_strlen(lines[i]);
	while(lines[i])
	{
		if (lines[i][0] != '1' || lines[i][len - 2] != '1')
			ft_perror();
		i++;
	}
	return(lines);
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
