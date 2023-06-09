/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:28:07 by oredoine          #+#    #+#             */
/*   Updated: 2023/05/27 15:55:40 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	helper(int keycode, t_data *data)
{
	if (keycode == 53)
		ft_close_window();
	else if (keycode == 123)
	{
		ft_move_left(data);
		data->facing = LEFT;
		data->counter++;
	}
	else if (keycode == 124)
	{
		ft_move_right(data);
		data->facing = RIGHT;
		data->counter++;
	}
	else if (keycode == 125)
	{
		ft_move_down(data);
		data->counter++;
	}
	else if (keycode == 126)
	{
		ft_move_up(data);
		data->counter++;
	}
}

int	ft_handle_keys_press(int keycode, t_data *data)
{
	mlx_clear_window(data->mlx, data->mlx_new_window);
	helper(keycode, data);
	ft_push_image(data);
	ft_putnbr_fd(data->counter, 1);
	write(1, "\n", 1);
	return (0);
}

void	ft_xpm_files(t_data *data, int height, int width)
{
	data->imgs.wall_ptr = mlx_xpm_file_to_image(data->mlx, \
	"./assets/wall.xpm", &width, &height);
	data->imgs.coin_ptr = mlx_xpm_file_to_image(data->mlx, \
	"./assets/coin.xpm", &width, &height);
	data->imgs.lplayer_ptr = mlx_xpm_file_to_image(data->mlx, \
	"./assets/leftp.xpm", &width, &height);
	data->imgs.rplayer_ptr = mlx_xpm_file_to_image(data->mlx, \
	"./assets/pright.xpm", &width, &height);
	data->imgs.exit_ptr = mlx_xpm_file_to_image(data->mlx, \
	"./assets/exit.xpm", &width, &height);
	if (!data->imgs.wall_ptr || !data->imgs.coin_ptr || !data->imgs.lplayer_ptr \
	|| !data->imgs.rplayer_ptr || !data->imgs.exit_ptr)
	{
		perror("there is some problems in your xpm file");
		exit(1);
	}
}

void	ft_player_img(t_data *data, int i, int j)
{
	if (data->facing == RIGHT)
		mlx_put_image_to_window(data->mlx, data->mlx_new_window, \
		data->imgs.rplayer_ptr, j * 55, i * 55);
	if (data->facing == LEFT)
		mlx_put_image_to_window(data->mlx, data->mlx_new_window, \
		data->imgs.lplayer_ptr, j * 55, i * 55);
}

void	ft_push_image(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->lines[i])
	{
		j = 0;
		while (data->lines[i][j])
		{
			if (data->lines[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->mlx_new_window, \
				data->imgs.wall_ptr, j * 55, i * 55);
			else if (data->lines[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->mlx_new_window, \
				data->imgs.coin_ptr, j * 55, i * 55);
			else if (data->lines[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->mlx_new_window, \
				data->imgs.exit_ptr, j * 55, i * 55);
			else if (data->lines[i][j] == 'P')
				ft_player_img(data, i, j);
			j++;
		}
		i++;
	}
}
