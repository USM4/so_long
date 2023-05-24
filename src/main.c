/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 21:04:29 by oredoine          #+#    #+#             */
/*   Updated: 2023/05/24 15:53:26 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_open_map(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY, 0777);
	if (fd == -1)
	{
		perror("failed to open");
		exit(1);
	}
	return (fd);
}

void ft_check_map_extension(char *file)
{
	char *str = ".ber";
	int len = ft_strlen(file);
	int i = 3;
	while (i >= 0)
	{
		if (file[len - 1] != str[i])
		{
			perror("Your file has to be end with .ber");
			exit(1);
		}
		i--;
		len--;
	}
}

void ft_check_args(int ac)
{
	if (ac != 2)
	{
		perror("Not enough args");
		exit(1);
	}
}
void ft_fill_allocated(t_data *data , char	*filename)
{
	int i;
	int	fd;
	
	i = 0;
	fd = ft_open_map(filename);
	data->height = ft_count_line(fd);
	close(fd);
	data->lines = malloc(sizeof(char *) * (data->height + 1));
	fd = ft_open_map(filename);
	data->lines[i] = get_next_line(fd);
	if (!data->lines[i])
	{
		perror("empty file");
		exit(1);
	}
	data->width = ft_strlen(data->lines[i]) - 1;
	while (data->lines[i] != NULL)
	{
		i++;
		data->lines[i] = get_next_line(fd);
	}
	
}


int main(int ac, char *argv[])
{
	t_data data;

	ft_check_map_extension(argv[1]);
	ft_check_args(ac);
	ft_fill_allocated(&data, argv[1]);
	data.lines = ft_rm_newline(data.lines);
	ft_is_rectangular(data.lines);
	ft_map_contains(data.lines, &data);
	char **map = ft_cpy_map(data.lines, data);
	ft_valid_path( map, &data);
	ft_clean(map);
	data.mlx = mlx_init();
	data.mlx_new_window = mlx_new_window(data.mlx, data.width * 55, data.height * 55, "USM4");
	data.facing = LEFT;
	ft_push_image(&data, data.width * 55, data.height * 55);
	mlx_hook(data.mlx_new_window, 2, 0, ft_handle_keys_press, &data);
	mlx_hook(data.mlx_new_window, 17, 0, ft_destroy, &data);
	mlx_loop(data.mlx);
}