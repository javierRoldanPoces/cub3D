/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jroldan- <jroldan-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:47:05 by jroldan-          #+#    #+#             */
/*   Updated: 2023/05/08 12:08:00 by Jroldan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*clean_reader(char *readed)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (readed[i] && readed[i] != '\n')
		i++;
	if (!readed[i])
	{
		free(readed);
		return (NULL);
	}
	tmp = ft_calloc((ft_strlen(readed) - i + 1), sizeof(char));
	if (!tmp)
		return (NULL);
	i++;
	j = 0;
	while (readed[i])
		tmp[j++] = readed[i++];
	free(readed);
	return (tmp);
}

static char	*cpy_line(char *readed)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	if (!readed[0])
		return (NULL);
	while (readed[i] && readed[i] != '\n')
		i++;
	if (ft_strchr(readed, '\n'))
		line = ft_calloc(i + 2, 1);
	else
		line = ft_calloc(i + 1, 1);
	if (line == NULL)
		return (NULL);
	while (j <= i)
	{
		line[j] = readed[j];
		j++;
	}
	if (!line[0])
		return (free(line), NULL);
	return (line);
}

static char	*read_buffer(int fd, char *readed)
{
	int		len;
	char	*buffer_temp;

	if (readed && (ft_strchr(readed, '\n')))
		return (readed);
	if (!readed)
		readed = ft_calloc (1, sizeof(char));
	buffer_temp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buffer_temp == NULL)
		return (NULL);
	len = 1;
	while ((len > 0) && !(ft_strchr(buffer_temp, '\n')))
	{
		len = read(fd, buffer_temp, BUFFER_SIZE);
		if (len < 0)
			return (free(buffer_temp), free(readed), NULL);
		buffer_temp[len] = '\0';
		readed = ft_strjoin(readed, buffer_temp);
	}
	free(buffer_temp);
	return (readed);
}

char	*get_next_line(int fd)
{
	static char		*readed;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	readed = read_buffer(fd, readed);
	if (!readed)
	{	
		free(readed);
		return (NULL);
	}
	line = cpy_line(readed);
	readed = clean_reader(readed);
	return (line);
}
