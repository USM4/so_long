/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:28:20 by oredoine          #+#    #+#             */
/*   Updated: 2022/11/16 19:57:46 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)

{
	char	o;
	int		i;
	char	*p;

	p = (char *)s;
	o = (char)c;
	i = 0;
	if (*(p + i) == o)
		return (p + i);
	while (*(p + i))
	{
		if (*(p + i + 1) == o)
			return (p + i + 1);
		i++;
	}
	return (0);
}
