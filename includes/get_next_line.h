/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oredoine <oredoine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:19:01 by oredoine          #+#    #+#             */
/*   Updated: 2023/05/26 01:05:57 by oredoine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include<stdio.h>
# include<fcntl.h>
# include<stdlib.h>
# include<unistd.h>

extern char	*ft_strjoin(char *s1, char *s2);
extern int	bufferlenght(char *str);
extern int	ft_strlen(const char *p);
extern char	*ft_strdup(char *s1);
extern char	*get_next_line(int fd);
extern int	ft_buf_len(const char *p);
extern int	ft_strncmp( const char *s1, const char *s2, size_t n);

#endif