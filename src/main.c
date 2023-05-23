/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 21:04:29 by oredoine          #+#    #+#             */
/*   Updated: 2023/05/23 09:29:25 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void ft_move_left(int keycode, t_data *data)
{
	(void)keycode;
	int i;
	int j;
	
	i = 0;
	while (data->lines[i])
	{
		j = 0;
		while (data->lines[i][j])
		{
			if (data->lines[i][j] == 'P')
			{
				if(data->lines[i][j - 1] == '0' || data->lines[i][j - 1] == 'C')
				{
					if (data->lines[i][j - 1] == 'C')
						data->collectible--;
					data->player.x = j - 1;
					data->player.y = i;
					data->lines[i][j - 1] = 'P';
					data->lines[i][j] = '0';
				}
				else if(data->lines[i][j - 1] == '1')
					return;
				else if (data->lines[i][j - 1] == 'E' && data->collectible == 0)
					exit(0);
			}
			j++;
		}
		i++;
	}	
}

void ft_move_right(int keycode, t_data *data)
{
	(void)keycode;
	int i;
	int j;

	i = 0;
	while (data->lines[i])
	{
		
		j = 0;
		while (data->lines[i][j])
		{
			if (data->lines[i][j] == 'P')
			{
				if(data->lines[i][j + 1] == '0' || data->lines[i][j + 1] == 'C')
				{
					if (data->lines[i][j + 1] == 'C')
						data->collectible--;
					data->player.x = j + 1;
					data->player.y = i;
					data->lines[i][j + 1] = 'P';
					data->lines[i][j] = '0';
				}
				else if(data->lines[i][j + 1] == '1')
					return;
				else if (data->lines[i][j + 1] == 'E' && data->collectible == 0)
					exit(0);
				break;
			}
			j++;			
		}
		i++;
	}	
}

void ft_move_up(int keycode, t_data *data)
{
	(void)keycode;
	int i;
	int j;
	
	i = 0;
	while (data->lines[i])
	{
		j = 0;
		while (data->lines[i][j])
		{
			if (data->lines[i][j] == 'P')
			{
				if(data->lines[i - 1][j] == '0' || data->lines[i - 1][j] == 'C')
				{
					if (data->lines[i - 1][j] == 'C')
						data->collectible--;
					data->player.x = j;
					data->player.y = i - 1;
					data->lines[i - 1][j] = 'P';
					data->lines[i][j] = '0';
				}
				else if(data->lines[i - 1][j] == '1')
					return;
				else if (data->lines[i - 1][j] == 'E' && data->collectible == 0)
					exit(0);
			}
			j++;			
		}
		i++;
	}	
}
void ft_move_down(int keycode, t_data *data)
{
	(void)keycode;
	int i;
	int j;
	int n;
	
	i = 0;
	n = 0;
	while (data->lines[i])
	{
		j = 0;
		while (data->lines[i][j])
		{
			if (data->lines[i][j] == 'P')
			{
				n = 1;
				if(data->lines[i + 1][j] == '0' || data->lines[i + 1][j] == 'C')
				{
					if (data->lines[i + 1][j] == 'C')
						data->collectible--;
					data->player.x = j;
					data->player.y = i + 1;
					data->lines[i + 1][j] = 'P';
					data->lines[i][j] = '0';
				}
				else if(data->lines[i + 1][j] == '1')
					return;
				else if(data->lines[i + 1][j] == 'E' && data->collectible == 0)
						exit(0);
			}
			if (n == 1)
				break;
			j++;			
		}
		i++;
	}	
}

int ft_destroy(t_data *data)
{
	(void)data;
	exit (0);
}

void ft_close_window(int keycode, t_data *data)
{
	(void)data;
	(void)keycode;
	exit(0);
}

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

int main(int ac, char *argv[])
{
	int fd;
	int i;
	t_data data;

	if ((fd = open(argv[1], O_RDONLY)) == -1)
		puts("fd error");
	if (ac != 2)
	{
		perror("Not enough args");
		exit(1);
	}
	data.height = ft_count_line(fd);
	data.lines = malloc(sizeof(char *) * (data.height + 1));
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		puts("fd error");
	}
	i = 0;
	data.lines[i] = get_next_line(fd);
	if (!data.lines[i])
	{
		perror("empty file");
		exit(1);
	}
	data.width = ft_strlen(data.lines[i]) - 1;
	while (data.lines[i] != NULL)
	{
		i++;
		data.lines[i] = get_next_line(fd);
	}
	data.lines = ft_rm_newline(data.lines);
	ft_is_rectangular(data.lines);
	ft_map_contains(data.lines, &data);
	ft_valid_path(ft_cpy_map(data.lines, data) , &data);
	data.mlx = mlx_init();
	data.mlx_new_window = mlx_new_window(data.mlx, data.width * 55, data.height * 55, "USM4");
	data.facing = LEFT;
	ft_push_image(&data, data.width * 55, data.height * 55);
	mlx_hook(data.mlx_new_window, 2, 0, ft_handle_keys_press, &data);
	mlx_hook(data.mlx_new_window, 17, 0, ft_destroy, &data);
	mlx_loop(data.mlx);
}