#include "../../include/cub3D.h"

char	*get_line(int fd, int *map_line)
{
	char	*buffer;

	buffer = get_next_line(fd);
	(*map_line)++;
	while (ft_strncmp(buffer, "\n", 2) == 0)
	{
		free(buffer);
		buffer = get_next_line(fd);
		(*map_line)++;
	}
	return (buffer);
}

int	get_tabs(char *buffer)
{
	int		tabs;
	int		i;

	i = 0;
	tabs = 1;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\t')
			tabs = tabs + 8;
		i++;
	}
	return (tabs);
}

char	*ft_convert(char *buffer)
{
	char	*new_buffer;
	int		tabs;
	int		i;
	int		j;

	tabs = get_tabs(buffer);
	i = 0;
	j = 0;
	new_buffer = (char *)ft_calloc(sizeof(char), ft_strlen(buffer) + tabs);
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\t')
			while (--tabs % 8 != 0)
				new_buffer[j++] = ' ';
		else
			new_buffer[j++] = buffer[i];
		i++;
	}
	return (ft_strtrim(new_buffer, "\n", 1));
}

void	ft_error(char *msg, char *origin)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(msg, 2);
	if (origin != NULL)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(origin, 2);
	}
	if (origin == NULL
		|| (origin != NULL && origin[ft_strlen(origin) - 1] != '\n'))
		ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

void	ft_free(t_map *map)
{
	if (map->file != NULL)
		free(map->file);
	if (map->north_texture != NULL)
		free(map->north_texture);
	if (map->south_texture != NULL)
		free(map->south_texture);
	if (map->west_texture != NULL)
		free(map->west_texture);
	if (map->east_texture != NULL)
		free(map->east_texture);
	if (map->floor != NULL)
		free(map->floor);
	if (map->ceiling != NULL)
		free(map->ceiling);
	if (map->matrix != NULL)
		ft_free_split(map->matrix);
	if (map != NULL)
		free(map);
}
