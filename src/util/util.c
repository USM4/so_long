/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:34:02 by oredoine          #+#    #+#             */
/*   Updated: 2023/05/26 20:43:01 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_clean(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	ft_count_line(int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (i == 0)
			free(line);
		line = get_next_line(fd);
		free(line);
		i++;
	}
	return (i);
}

char	**ft_rm_newline(t_data *data)
{
	int	i;
	int	length;

	i = 0;
	while (data->lines[i] != NULL)
	{
		length = ft_strlen(data->lines[i]);
		if (data->lines[i][length - 1] == '\n')
			data->lines[i][length - 1] = '\0';
		i++;
	}
	return (data->lines);
}

static char	**ft_allocate_for_new_map(t_data *data)
{
	char	**cpy;
	int		i;

	i = 0;
	cpy = malloc(sizeof(char *) * (data->height + 1));
	if (!cpy)
	{
		perror("MALLOC FAILURE");
		exit(1);
	}
	while (i < data->height)
	{
		cpy[i] = malloc(sizeof(char ) * (data->width + 1));
		if (!cpy[i])
		{
			perror("MALLOC FAILURE");
			exit(1);
		}
		i++;
	}
	return (cpy);
}

char	**ft_cpy_map(t_data *data)
{
	char	**cpy ;
	int		i;
	int		j;

	i = 0;
	j = 0;
	cpy = ft_allocate_for_new_map(data);
	while (data->lines[i])
	{
		j = 0;
		while (data->lines[i][j] != '\0')
		{
			cpy[i][j] = data->lines[i][j];
			j++;
		}
		cpy[i][j] = '\0';
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}
