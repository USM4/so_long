/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:36:20 by oredoine          #+#    #+#             */
/*   Updated: 2022/11/14 23:45:11 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)

{
	size_t	i;
	size_t	lend;
	size_t	lens;
	size_t	j;

	lens = ft_strlen(src);
	lend = ft_strlen(dst);
	if (lend >= dstsize)
		return (lens + dstsize);
	i = 0;
	j = lend;
	while (src[i] && j < dstsize - 1)
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (lend + lens);
}
