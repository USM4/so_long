/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 21:04:29 by oredoine          #+#    #+#             */
/*   Updated: 2023/05/22 02:17:59 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_push_image(char **map, void *mlx, int height, int width)
{
	int i;
	int j;
	void *mlx_window;

	mlx_window = mlx_new_window(mlx, width, height, "usm");
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(mlx, mlx_window, mlx_xpm_file_to_image(mlx, "./xpm/wall.xpm", &width, &height), j * 55, i * 55);
			else if (map[i][j] == 'C')
				mlx_put_image_to_window(mlx, mlx_window, mlx_xpm_file_to_image(mlx, "./xpm/coin.xpm", &width, &height), j * 55, i * 55);
			else if (map[i][j] == 'E')
				mlx_put_image_to_window(mlx, mlx_window, mlx_xpm_file_to_image(mlx, "./xpm/exit.xpm", &width, &height), j * 55, i * 55);
			else if (map[i][j] == 'P')
				mlx_put_image_to_window(mlx, mlx_window, mlx_xpm_file_to_image(mlx, "./xpm/leftp.xpm", &width, &height), j * 55, i * 55);
			j++;
		}
		i++;
	}
}

int main(int ac, char *argv[])
{
	int fd;
	int i;
	t_data data;
	char **lines;
	void *mlx;
	// void *mlx_window;
	// void *mlx_image;

	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		puts("fd error");
	}
	if (ac != 2)
	{
		perror("Not enough args");
		exit(1);
	}

	data.height = ft_count_line(fd);
	lines = malloc(sizeof(char *) * (data.height + 1));
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		puts("fd error");
	}
	i = 0;
	lines[i] = get_next_line(fd);
	if (!lines[i])
	{
		perror("empty file");
		exit(1);
	}
	data.width = ft_strlen(lines[i]) - 1;
	while (lines[i] != NULL)
	{
		i++;
		lines[i] = get_next_line(fd);
	}
	// lines = ft_rm_newline(lines);
	// int h = ft_is_rectangular(lines);
	// ft_map_contains(lines, &data);
	char **map = ft_cpy_map(lines, data);
	//  ft_valid_path(map , &data);
	// i = 0;
	// while (map[i])
	// {
	//     printf("%s\n",map[i]);
	// 	i++;
	// }
	int width = data.width * 55 ;
	int height = data.height * 55;
	mlx = mlx_init();
	ft_push_image(map, mlx, height, width);
	// mlx_key_hook()
	mlx_loop(mlx);
}
