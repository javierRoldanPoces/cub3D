/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:04:48 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/02/19 15:47:42 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

//get_next_line
char	*get_next_line(int fd);
char	*read_fd(int fd, char *static_buffer);
char	*return_line(char *static_buffer);
char	*return_static(char *static_buffer);
void	*gnl_calloc(size_t nmemb, size_t size);

//get_next_line_utils
int		gnl_strlen(char *s);
char	*gnl_strchr(char *s, int c);
char	*gnl_strdup(char *s);
char	*gnl_strjoin(char *s1, char *s2, int flag);
char	*gnl_substr(char *s, unsigned int start, size_t len, int flag);

#endif
