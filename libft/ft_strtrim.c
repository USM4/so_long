/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 23:46:50 by oredoine          #+#    #+#             */
/*   Updated: 2022/11/16 15:03:10 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static	int	check(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
	i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		left;
	int		right;

	left = 0;
	if (!s1)
		return (NULL);
	right = ft_strlen(s1) - 1;
	while (s1[left] && check(set, s1[left]))
	left++;
	while (s1[right] && check(set, s1[right]))
	right--;
	if (right - left < -1)
	{
		str = malloc(1);
		*str = '\0';
		return (str);
	}
	str = ft_substr(s1, left, right - left + 1);
	return (str);
}
