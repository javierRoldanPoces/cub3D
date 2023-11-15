#include "../../include/cub3D.h"

void	get_textures_and_colours(t_map *map, int fd, int *map_pos)
{
	char	*buffer;
	int		counter;

	counter = 0;
	while (1)
	{
		buffer = get_line(fd, map_pos);
		if (allocate_text_and_colour(map, buffer, &counter) == 6)
			break ;
	}
}

int	allocate_text_and_colour(t_map *map, char *buff, int *counter)
{
	char	**split;

	split = ft_split(buff, ' ');
	if (split[0] == NULL || split[1] == NULL
		|| (split[2] != NULL && ft_strncmp(split[2], "\n", 2) != 0))
		ft_error("invalid text line", buff);
	free(buff);
	if (map->north_texture == NULL && ft_strncmp(split[0], "NO", 3) == 0)
		return (get_texture(&map->north_texture, split, counter));
	else if (map->south_texture == NULL && ft_strncmp(split[0], "SO", 3) == 0)
		return (get_texture(&map->south_texture, split, counter));
	else if (map->west_texture == NULL && ft_strncmp(split[0], "WE", 3) == 0)
		return (get_texture(&map->west_texture, split, counter));
	else if (map->east_texture == NULL && ft_strncmp(split[0], "EA", 3) == 0)
		return (get_texture(&map->east_texture, split, counter));
	else if (map->floor == NULL && ft_strncmp(split[0], "F", 2) == 0)
		return (get_colour(&map->floor, split, counter));
	else if (map->ceiling == NULL && ft_strncmp(split[0], "C", 2) == 0)
		return (get_colour(&map->ceiling, split, counter));
	return (ft_error("invalid map file", NULL), -1);
}

int	get_texture(char **map_texture, char **split, int *counter)
{
	*map_texture = ft_strtrim(split[1], "\n", 0);
	ft_free_split(split);
	return (++*counter);
}

int	get_colour(t_colour **map_colour, char **split, int *counter)
{
	char	**colours;

	colours = ft_split(split[1], ',');
	if (colours[0] == NULL || colours[1] == NULL
		|| colours[2] == NULL || colours[3] != NULL)
		ft_error("invalid colour arguments", split[1]);
	*map_colour = (t_colour *)ft_calloc(sizeof(t_colour), 1);
	(*map_colour)->r = ft_atoi(colours[0]);
	(*map_colour)->g = ft_atoi(colours[1]);
	(*map_colour)->b = ft_atoi(colours[2]);
	if ((*map_colour)->r < 0 || (*map_colour)->r > 255
		|| (*map_colour)->g < 0 || (*map_colour)->g > 255
		|| (*map_colour)->b < 0 || (*map_colour)->b > 255)
		ft_error("colour value out of range", NULL);
	ft_free_split(colours);
	ft_free_split(split);
	return (++*counter);
}
