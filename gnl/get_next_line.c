/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:04:44 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/02/21 10:59:43 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*static_buffer;
	char			*buffer;

	if (fd == -1)
		return (NULL);
	static_buffer = read_fd(fd, static_buffer);
	if (static_buffer == NULL || !static_buffer)
		return (NULL);
	buffer = return_line(static_buffer);
	static_buffer = return_static(static_buffer);
	return (buffer);
}

char	*read_fd(int fd, char *static_buffer)
{
	char		*buffer;
	long int	bytes_read;

	if (static_buffer && gnl_strchr(static_buffer, 10))
		return (static_buffer);
	bytes_read = 1;
	while (bytes_read > 0 && !(gnl_strchr(static_buffer, 10)))
	{
		buffer = gnl_calloc(BUFFER_SIZE + 1, sizeof(char));
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), free(static_buffer), NULL);
		else if (bytes_read == 0)
			return (free(buffer), static_buffer);
		else if (!static_buffer)
			static_buffer = gnl_strdup(buffer);
		else
			static_buffer = gnl_strjoin(static_buffer, buffer, 1);
		free(buffer);
	}
	return (static_buffer);
}

char	*return_line(char *static_buffer)
{
	char	*buffer;
	int		length;

	if (static_buffer && gnl_strchr(static_buffer, 10))
	{
		length = 0;
		while (static_buffer[length] != 10)
			length++;
		length++;
		buffer = gnl_substr(static_buffer, 0, length, 0);
		return (buffer);
	}
	return (static_buffer);
}

char	*return_static(char *static_buffer)
{
	char	*buffer;
	int		n;
	int		length;

	if (static_buffer && gnl_strchr(static_buffer, 10))
	{
		n = 0;
		while (static_buffer[n] != 10)
			n++;
		n++;
		length = 0;
		while (static_buffer[n + length] != '\0')
			length++;
		if (length == 0)
			return (free (static_buffer), NULL);
		buffer = gnl_substr(static_buffer, n, length, 0);
		return (free (static_buffer), buffer);
	}
	return (NULL);
}

void	*gnl_calloc(size_t nmemb, size_t size)
{
	char	*str;
	size_t	i;

	str = (char *) malloc(size * nmemb);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < (size * nmemb))
		str[i++] = '\0';
	return (str);
}
