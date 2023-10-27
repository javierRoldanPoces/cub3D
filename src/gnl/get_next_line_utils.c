/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:04:36 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/02/19 16:24:43 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

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

char	*gnl_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

char	*gnl_strdup(char *s)
{
	char	*str;
	int		i;

	i = 0;
	str = gnl_calloc(ft_strlen(s) + 1, sizeof (char));
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*gnl_strjoin(char *s1, char *s2, int flag)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = gnl_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	if (flag == 1 || flag == 3)
		free(s1);
	if (flag == 2 || flag == 3)
		free(s2);
	return ((char *)str);
}

char	*gnl_substr(char *s, unsigned int start, size_t len, int flag)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if ((size_t)ft_strlen(s) < (size_t)start)
		return (gnl_strdup(""));
	if (len > (ft_strlen(s) - (size_t)start))
		len = ft_strlen(s) - (size_t)start;
	str = (char *) malloc (sizeof (char) * len + 1);
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = 0;
	if (flag == 1)
		free (s);
	return (str);
}
