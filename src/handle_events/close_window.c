/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:31:25 by oredoine          #+#    #+#             */
/*   Updated: 2023/05/25 18:36:56 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_destroy(t_data *data)
{
	(void)data;
	exit (0);
}

void ft_close_window(void)
{
	exit(0);
}

int	ft_strncmp( const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while ((str1[i] && str2[i]) != '\0' && str1[i] == str2[i] && i < n - 1)
		i++;
	return (str1[i] - str2[i]);
}

