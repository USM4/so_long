/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 20:10:15 by oredoine          #+#    #+#             */
/*   Updated: 2023/05/26 20:47:54 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_open_map(t_data *data, char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY, 0777);
	if (fd == -1)
	{
		perror("failed to open");
		exit(1);
	}
	data->height = ft_count_line(fd);
	close(fd);
	data->lines = malloc(sizeof(char *) * (data->height + 1));
	if (!data->lines)
	{
		perror("MALLOC FAILURE");
		exit(1);
	}
	fd = open(filename, O_RDONLY, 0777);
	return (fd);
}

void	ft_make_map(t_data *data, char	*filename)
{
	int	i;
	int	fd;

	i = 0;
	fd = ft_open_map(data, filename);
	data->lines[i] = get_next_line(fd);
	if (!data->lines[i])
	{
		perror("empty file");
		exit(1);
	}
	data->width = ft_strlen(data->lines[i]) - 1;
	while (data->lines[i] != NULL)
	{
		i++;
		data->lines[i] = get_next_line(fd);
	}
	close(fd);
}
