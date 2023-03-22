/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:08:08 by oredoine          #+#    #+#             */
/*   Updated: 2022/11/16 20:25:53 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (!dst && !src && n)
		return (NULL);
	d = (unsigned char *) dst;
	s = (unsigned char *) src;
	i = 0 ;
	while (i < n)
	{
		*(d + i) = *(s + i);
		i++;
	}
	return (d);
}
