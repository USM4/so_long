/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 21:04:29 by oredoine          #+#    #+#             */
/*   Updated: 2023/05/19 00:32:16 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



int main(int ac, char *argv[])
{
    int fd;
	int i;
	t_data data;
	char **lines;

    if((fd = open(argv[1], O_RDONLY)) == -1)
      {  puts ("fd error");}
	if (ac != 2)
	{
		perror("Not enough args");
		exit(1);
	}
	data.height = ft_count_line(fd);
	lines = malloc(sizeof(char *) * data.height);
    if((fd = open(argv[1], O_RDONLY)) == -1)
       { puts ("fd error");}
	i = 0;
	lines[i] = get_next_line(fd);
	if(!lines[i])
	{
		perror("empty file");
		exit(1);
	}
	data.width = ft_strlen(lines[i]);
	while (lines[i] != NULL)
	{
		i++;
		lines[i] = get_next_line(fd);
	}
	// lines = ft_rm_newline(lines);
	// int h = ft_is_rectangular(lines);
	
	ft_map_contains(lines, &data);
	i = 0;
	char **map = ft_cpy_map(lines,data);
	 ft_valid_path(map , &data);
	i = 0;
    while (map[i])
    {
        printf("%s\n",map[i]);
		i++;
    }
}