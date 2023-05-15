/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 21:04:29 by oredoine          #+#    #+#             */
/*   Updated: 2023/05/15 01:19:25 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char *ft_map_contains(char **lines)
{
	int i;
	int j;
	int counter;
	
	i = 0;
	j = 0;
	counter = 0; 
		
		while(lines[i] != NULL)
		{
			if(lines[i][j] == 'P' || lines[i][j] == 'C' || lines[i][j] == 'E')
			{
				counter++;
				j++;
			}
			i++;
		}

	printf("%d", j);	
	if(counter != 3)
	{
		ft_perror();
	}
	return("KHDAMA");
}

int main(int ac, char *argv[])
{
	// t_dyali game_dyali;
    int fd;
	int i;
	char **lines;

    if((fd = open(argv[1], O_RDONLY)) == -1)
        puts ("fd error");
	if (ac != 2)
	{
		perror("Not enough args");
		exit(1);
	}
	lines = malloc(sizeof(char *) * ft_count_line(fd));
    if((fd = open(argv[1], O_RDONLY)) == -1)
        puts ("fd error");
	i = 0;
	lines[i] = get_next_line(fd);

	if(!lines[i])
	{
		perror("empty file");
		exit(1);
	}
	while (lines[i] != NULL)
	{
		i++;
		lines[i] = get_next_line(fd);
	}	
	lines = ft_rm_newline(lines);
	// int h = ft_is_rectangular(lines);
	
	printf("%s",ft_map_contains(lines));
	
}