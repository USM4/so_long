/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:53:41 by oredoine          #+#    #+#             */
/*   Updated: 2023/05/14 22:35:01 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
extern void ft_perror(void);
extern char	*ft_substr(char	*s, unsigned int start, size_t len);
extern int ft_count_line(int file);
extern char **ft_rm_newline(char **lines);

typedef struct counters{
	int counter_p;
	int counter_c;
	int counter_e;
}t_count;
#endif