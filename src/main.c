/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 21:04:29 by oredoine          #+#    #+#             */
/*   Updated: 2023/05/27 16:07:41 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_check_args(int ac)
{
	if (ac != 2)
	{
		perror("Wrong number of arguments");
		exit(1);
	}
}

static void	ft_check_map_extension(char *file)
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

void	parsing(int ac, char **argv, t_data *data)
{
	char	**map;

	ft_check_args(ac);
	ft_check_map_extension(argv[1]);
	ft_make_map(data, argv[1]);
	data->lines = ft_rm_newline(data);
	ft_check_entourage(data);
	ft_is_rectangular(data);
	ft_validate_map(data);
	map = ft_cpy_map(data);
	ft_valid_path(map, data);
	ft_clean(map);
}

int	main(int ac, char **argv)
{
	t_data	data;

	parsing(ac, argv, &data);
	data.mlx = mlx_init();
	data.mlx_new_window = mlx_new_window(data.mlx, data.width * 55, \
	data.height * 55, "USM4");
	if (!data.mlx_new_window || !data.mlx)
	{
		perror("mlx failure");
		exit(1);
	}
	data.facing = RIGHT;
	ft_xpm_files(&data, data.width * 55, data.height * 55);
	ft_push_image(&data);
	if (!mlx_hook(data.mlx_new_window, 2, 0, ft_handle_keys_press, &data) \
	|| !mlx_hook(data.mlx_new_window, 17, 0, ft_destroy, &data))
	{
		perror("mlx hook failure");
		exit(1);
	}
	mlx_loop(data.mlx);
}
