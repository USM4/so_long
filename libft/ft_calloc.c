/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 18:45:58 by oredoine          #+#    #+#             */
/*   Updated: 2022/11/15 20:33:17 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)

{
	unsigned char	*p;
	size_t			i;

	i = 0;
	p = malloc(count * size);
	if (!p)
		return (0);
	while (i < count * size)
	{
		*(p + i) = 0;
		i++;
	}
	return (p);
}
