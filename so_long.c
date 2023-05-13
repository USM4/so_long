/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 21:04:29 by oredoine          #+#    #+#             */
/*   Updated: 2023/05/13 22:36:58 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

// char **ft_pass_map(char **arr)

// {
// 	int i;
// 	i = 0;
// 	arr[i] = get_next_line(fd);
// 	while (arr[i] != NULL)
// 	{
// 		i++;
// 		arr[i] = get_next_line(fd);
// 	}
// 	return(arr);
// }

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


char **ft_check_middle_lines(char **line)

{
	int len;
	int i;
	
	i = 0;
	len = ft_strlen(line[i]);
	while(line[i])
	{
		if (line[i][0] != '1' || line[i][len - 2] != '1')
			ft_perror();
		i++;
	}
	return(line);
}

int main(int ac, char *argv[])
{
	// t_dyali game_dyali;
    int fd;
    if((fd = open(argv[1], O_RDONLY)) == -1)
        puts ("fd error");
	if (ac != 2)
	{
		perror("Not enough args");
		exit(1); 
	}
	char **lines;
	lines = malloc(sizeof(char *) * ft_count_line(fd));
    if((fd = open(argv[1], O_RDONLY)) == -1)
        puts ("fd error");
	int i;
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
	
}