/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 17:56:16 by oredoine          #+#    #+#             */
/*   Updated: 2023/03/19 23:16:47 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)

{
	char			*str;
	size_t			i;
	unsigned int	ls;

	i = 0;
	if (!s)
		return (NULL);
	ls = ft_strlen(s);
	if (start >= ls)
	{
		str = malloc(1);
		*str = '\0';
		return (str);
	}
	if (len > ls - start)
		len = ls - start;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (s[start] && i < len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
// int main()
// {
// 	char *str = "i just want this part #############";
//         size_t size = 10;
//         int ret_size;
// 		printf("%s",ft_substr(str, 5, size));
// }