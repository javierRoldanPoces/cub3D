/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jroldan- <jroldan-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:47:02 by jroldan-          #+#    #+#             */
/*   Updated: 2023/02/09 18:56:24 by Jroldan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 18
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>

char	*ft_strjoin(char *readed, char *buffer);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
char	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
#endif