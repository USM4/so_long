/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 21:04:29 by oredoine          #+#    #+#             */
/*   Updated: 2023/05/15 23:42:04 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char *ft_map_contains(char **lines)
{
	int i;
	int j;
	int counter_p;
	int counter_c;
	int counter_e;
	
	i = 0;
	counter_c = 0;
	counter_p = 0;
	counter_e = 0;
	while(lines[i] != NULL)
	{
		j = 0;
		while (lines[i][j])
		{	
			if(lines[i][j] == 'P')
				counter_p++;
			else if(lines[i][j] == 'C')
				counter_c++;
			else if(lines[i][j] == 'E')
				counter_e++;
			j++;
		}
	i++;
	} 
	if(counter_c == 0 || counter_e != 1 || counter_p != 1)
		ft_perror();
	return("KHDAMA");
}

void ft_valip_path()
{
	
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