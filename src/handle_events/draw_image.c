/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:28:07 by oredoine          #+#    #+#             */
/*   Updated: 2023/05/23 14:25:05 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int ft_handle_keys_press(int keycode, t_data *data)
{
	mlx_clear_window(data->mlx, data->mlx_new_window);
	if(keycode == 53)
		ft_close_window(keycode, data);
	else if (keycode == 123)
	{
		ft_move_left(keycode, data);
		data->facing = LEFT;
	}
	else if (keycode == 124)
	{
		ft_move_right(keycode, data);
		data->facing = RIGHT;
	}
	else if (keycode == 125)
		ft_move_down(keycode, data);
	else if (keycode == 126)
		ft_move_up(keycode, data);
	ft_push_image(data, data->width*55, data->height*55);
	return 0;
}

void ft_push_image(t_data *data, int height, int width)
{
	int i;
	int j;

	i = 0;
	while (data->lines[i])
	{
		j = 0;
		while (data->lines[i][j])
		{
			if (data->lines[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->mlx_new_window, mlx_xpm_file_to_image(data->mlx, "./assets/wall.xpm", &width, &height), j * 55, i * 55);
			else if (data->lines[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->mlx_new_window, mlx_xpm_file_to_image(data->mlx, "./assets/coin.xpm", &width, &height), j * 55, i * 55);
			else if (data->lines[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->mlx_new_window, mlx_xpm_file_to_image(data->mlx, "./assets/exit.xpm", &width, &height), j * 55, i * 55);
			else if (data->lines[i][j] == 'P')
			{
				if (data->facing == RIGHT)
					mlx_put_image_to_window(data->mlx, data->mlx_new_window, mlx_xpm_file_to_image(data->mlx, "./assets/pright.xpm", &width, &height), j * 55, i * 55);
				if (data->facing == LEFT)
					mlx_put_image_to_window(data->mlx, data->mlx_new_window, mlx_xpm_file_to_image(data->mlx, "./assets/leftp.xpm", &width, &height), j * 55, i * 55);
			}
			j++;
		}
		i++;
	}
}