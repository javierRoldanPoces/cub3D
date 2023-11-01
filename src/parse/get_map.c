#include "../../include/cub3D.h"

void	get_map(t_map *map, int fd, int *map_pos)
{
	int	new_fd;

	new_fd = 0;
	count_map_lines(map, fd, map_pos);
	get_map_line(map, &new_fd, *map_pos);
	allocate_map(map, new_fd);
	square_up_map(map);
	close(fd);
	close(new_fd);
}

void	count_map_lines(t_map *map, int fd, int *map_pos)
{
	char	*buffer;

	buffer = get_line(fd, map_pos);
	while (buffer != NULL && ft_strncmp(buffer, "\n", 2) != 0)
	{
		map->heigth++;
		free(buffer);
		buffer = get_next_line(fd);
	}
	if (buffer != NULL)
		free(buffer);
	while (buffer != NULL)
	{
		buffer = get_next_line(fd);
		if (buffer != NULL && ft_strncmp(buffer, "\n", 2) != 0)
			ft_error("invalid line", buffer);
		free(buffer);
	}
}

void	get_map_line(t_map *map, int *new_fd, int map_pos)
{
	char	*buffer;

	*new_fd = open(map->file, O_RDONLY);
	if (*new_fd == -1)
		ft_error(strerror(errno), map->file);
	while (--map_pos)
	{
		buffer = get_next_line(*new_fd);
		free(buffer);
	}
}

void	allocate_map(t_map *map, int new_fd)
{
	int		n;
	char	*buffer;

	n = 0;
	map->matrix = (char **)ft_calloc(sizeof(char *), map->heigth + 1);
	while (n < map->heigth)
	{
		buffer = get_next_line(new_fd);
		map->matrix[n] = ft_convert(buffer);
		free(buffer);
		if (ft_strlen(map->matrix[n]) > map->width)
			map->width = ft_strlen(map->matrix[n]);
		n++;
	}
	map->matrix[n] = NULL;
}

void	square_up_map(t_map *map)
{
	char	*str;
	int		i;
	int		n;

	n = 0;
	while (map->matrix[n] != NULL)
	{
		if (ft_strlen(map->matrix[n]) < map->width)
		{
			i = -1;
			str = (char *)ft_calloc(sizeof(char), map->width + 1);
			while (map->matrix[n][++i] != '\0')
				str[i] = map->matrix[n][i];
			while (i < map->width)
				str[i++] = ' ';
			free(map->matrix[n]);
			map->matrix[n] = str;
		}
		n++;
	}
}
