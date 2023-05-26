/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 21:04:29 by oredoine          #+#    #+#             */
/*   Updated: 2023/05/26 02:37:23 by oredoine         ###   ########.fr       */
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

void	ft_check_map_extension(char *file)
{
	if (ft_strlen(file) > 4)
	{
		if (!ft_strnstr(file + (ft_strlen(file) - 4), ".ber", 4))
		{
			perror("Wrong file extension");
			exit(1);
		}
	}
	else
	{
		perror("Wrong file extension");
		exit(1);
	}	
}

void	ft_check_args(int ac)
{
	if (ac != 2)
	{
		perror("Wrong number of arguments");
		exit(1);
	}
}

void	ft_make_map(t_data *data, char	*filename)
{
	int	i;
	int	fd;

	i = 0;
	fd = ft_open_map(filename);
	data->height = ft_count_line(fd);
	close(fd);
	data->lines = malloc(sizeof(char *) * (data->height + 1));
	if (!data->lines)
	{
		perror("MALLOC FAILURE");
		exit(1);
	}	
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

int	main(int ac, char *argv[])
{
	t_data	data;
	char	**map;

	ft_check_args(ac);
	ft_check_map_extension(argv[1]);
	ft_make_map(&data, argv[1]);
	data.lines = ft_rm_newline(data.lines);
	ft_check_entourage(data.lines);
	ft_is_rectangular(data.lines);
	ft_validate_map(data.lines, &data);
	map = ft_cpy_map(data.lines, data);
	ft_valid_path(map, &data);
	ft_clean(map);
	data.mlx = mlx_init();
	data.mlx_new_window = mlx_new_window(data.mlx, data.width * 55, \
	data.height * 55, "USM4");
	if (!data.mlx_new_window || !data.mlx)
	{
		perror("mlx failure");
		exit(1);
	}
	data.facing = LEFT;
	ft_xpm_files(&data, data.width * 55, data.height * 55);
	ft_push_image(&data);
	mlx_hook(data.mlx_new_window, 2, 0, ft_handle_keys_press, &data);
	mlx_hook(data.mlx_new_window, 17, 0, ft_destroy, &data);
	mlx_loop(data.mlx);
}
