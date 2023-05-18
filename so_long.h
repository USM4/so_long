/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:53:41 by oredoine          #+#    #+#             */
/*   Updated: 2023/05/19 00:26:39 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

typedef struct s_point {
	int x;
	int y;
} t_point;

typedef struct s_exit {
	int x;
	int y;
} t_exit;

typedef struct s_data {
	t_point player;
	t_exit 	e;
	int height;
	int width;
} t_data;

typedef struct s_count{
	int player;
	int collectible;
	int exit;
}t_count;

extern void ft_perror(void);
extern char	*ft_substr(char	*s, unsigned int start, size_t len);
extern int ft_count_line(int file);
extern char **ft_rm_newline(char **lines);
extern void ft_map_contains(char **lines, t_data *data);
extern char **ft_cpy_map(char **lines, t_data data);
extern void ft_valid_path(char **map ,t_data *data);

#endif