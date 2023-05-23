/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:53:41 by oredoine          #+#    #+#             */
/*   Updated: 2023/05/23 08:57:01 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
#include<stdio.h>
#include<mlx.h>
#include<stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

typedef enum {TOP, RIGHT, DOWN, LEFT} t_orientation;

typedef struct s_point {
	int x;
	int y;
} t_point;

typedef struct s_exit {
	int x;
	int y;
} t_exit;

typedef struct s_data {
	char 			**lines;
	void 			*mlx_new_window;
	void 			*mlx;
	t_point 		player;
	int				collectible;
	t_exit 			e;
	int				height;
	int				width;
	t_orientation	facing;
} t_data;

typedef struct s_count{
	int player;
	int exit;
}t_count;

extern void ft_perror(void);
extern char	*ft_substr(char	*s, unsigned int start, size_t len);
extern void ft_is_rectangular(char **lines);
extern char *ft_check_fl_lines(char *line);
extern char **ft_check_middle_lines(char **lines);
extern int ft_count_line(int file);
extern char **ft_rm_newline(char **lines);
extern void ft_map_contains(char **lines, t_data *data);
extern char **ft_cpy_map(char **lines, t_data data);
extern void ft_valid_path(char **map ,t_data *data);
extern void ft_push_image(t_data *data, int height, int width);

#endif