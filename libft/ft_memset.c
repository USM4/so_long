/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:22:37 by oredoine          #+#    #+#             */
/*   Updated: 2022/11/17 23:31:29 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	val;
	size_t			i;
	unsigned char	*buc;

	buc = (unsigned char *) b;
	val = (unsigned char) c;
	i = 0;
	while (i < len)
	{
		buc[i] = val;
		i++;
	}
	return (buc);
}
