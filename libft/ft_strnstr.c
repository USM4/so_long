/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:40:44 by oredoine          #+#    #+#             */
/*   Updated: 2022/11/16 17:08:30 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
