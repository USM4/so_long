/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:42:58 by oredoine          #+#    #+#             */
/*   Updated: 2022/11/17 23:10:49 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	cp;
	char	*p;

	p = (char *)s;
	cp = (char) c;
	len = ft_strlen(p);
	if (!cp)
		return (p + len);
	while (len >= 0)
	{
		if (p[len] == cp)
			return (&p[len]);
			len--;
	}
	return (0);
}
