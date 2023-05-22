/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 21:34:02 by oredoine          #+#    #+#             */
/*   Updated: 2023/05/21 23:56:41 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void ft_perror(void)
{
	perror("INVALID MAP");
	exit(1);
}

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

int ft_count_line(int file)
{
	int i;
	i = 0;
	char *line = get_next_line(file);
	while (line != NULL)
	{
		line = get_next_line(file);
		i++;
	}
	return(i);
}

char **ft_rm_newline(char **lines)
{
	int i;
	int length;

	i = 0;
	// printf("%d",length);
	while(lines[i] != NULL)
	{
		length = ft_strlen(lines[i]);
		if (lines[i][length - 1] == '\n')
			lines[i][length - 1] = '\0';
		i++;
	}
	return(lines);
}

char **ft_cpy_map(char **lines, t_data data)
{
    char **cpy;
    int i;
	int j;

    cpy = malloc(sizeof(char *) * (data.height + 1));
    i = 0;
	j = 0;
	while (i < data.height)
	{
    	cpy[i] = malloc(sizeof(char ) * (data.width + 1));
		i++;
	}
	i = 0;
	while (lines[i])
    {
		j = 0;
		while (lines[i][j] != '\0')
		{
			cpy[i][j] = lines[i][j];
			j++;
		}
		cpy[i][j] = '\0';
		i++;
	}
	cpy[i] = NULL;
    return(cpy);
}
