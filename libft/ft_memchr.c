/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:02:29 by oredoine          #+#    #+#             */
/*   Updated: 2022/11/15 20:33:42 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)

{
	unsigned char	o;
	size_t			i;
	unsigned char	*s_iter;

	o = (unsigned char)c;
	s_iter = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*(s_iter + i) == o)
			return ((s_iter) + i);
			i++;
	}
	return (0);
}
