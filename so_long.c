/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:52:53 by oredoine          #+#    #+#             */
/*   Updated: 2023/03/21 16:30:01 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main()
{
    int fd;
	// char **arr;
    if((fd = open("mymap.ber", O_RDONLY)) == -1)
        puts ("fd error");
    char *line=NULL;
	int count_lines = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s",line);
		line = get_next_line(fd);
		count_lines++;
	}
	printf("\n%d",count_lines);
	
}