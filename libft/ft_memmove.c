/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:10:23 by oredoine          #+#    #+#             */
/*   Updated: 2022/11/14 23:57:36 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)

{
	unsigned int	i;
	unsigned char	*s;
	unsigned char	*d;

	s = (unsigned char *) src;
	d = (unsigned char *) dst;
	i = 0;
	if (d < s)
	{
		while (i < len)
		{
			*(d + i) = *(s + i);
			i++;
		}
	}
	else if (s < d)
	{
		while (len)
		{
			*(d + len - 1) = *(s + len -1);
			len--;
		}
	}
	return (d);
}
