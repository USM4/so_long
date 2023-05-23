/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:52:47 by oredoine          #+#    #+#             */
/*   Updated: 2023/05/23 14:53:12 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strnstr(const char *hay, const char *need, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	if ((!hay || !need) && !len)
		return (0);
	if (need[0] == '\0')
		return ((char *)hay);
	while (hay[i] && i < len)
	{
		k = i;
		while (hay[k++] == need[j++])
		{
			if (k > len)
				return (0);
			if (!need[j])
				return ((char *)(hay) + i);
		}
		j = 0;
		i++;
	}
	return (NULL);
}
