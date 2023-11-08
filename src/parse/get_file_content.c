#include "../../include/cub3D.h"

//funcion para almacebnar colores como uint_32
static void	get_color(t_map *map)
{
	map->c = (map->floor->r << 24) | (map->floor->g << 16) \
	| (map->floor->b << 8) | 255;
	map->f = (map->ceiling->r << 24) | (map->ceiling->g << 16) \
	| (map->ceiling->b << 8) | 255;
}

void	get_file_content(t_map *map, char *file)
{
	int	fd;
	int	map_pos;

	if (ft_strlen(ft_strnstr(file, ".cub", ft_strlen(file))) != 4)
		ft_error("unsupported file extension", file);
	else
	{
		map_pos = 0;
		map->file = ft_strdup(file);
		fd = open(map->file, O_RDONLY);
		if (fd == -1)
			ft_error(strerror(errno), map->file);
		get_textures_and_colours(map, fd, &map_pos);
		get_map(map, fd, &map_pos);
		check_map(map);
		get_color(map);
		get_textures(map);
	}
}
