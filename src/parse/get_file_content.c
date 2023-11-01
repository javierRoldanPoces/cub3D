#include "../../include/cub3D.h"

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
//////////////////////////////////////////////////////////////////////////
		printf("NO = %s\n", map->north_texture);
		printf("SO = %s\n", map->south_texture);
		printf("WE = %s\n", map->west_texture);
		printf("EA = %s\n\n", map->east_texture);
		printf("floor->r = %d\n", map->floor->r);
		printf("floor->g = %d\n", map->floor->g);
		printf("floor->b = %d\n\n", map->floor->b);
		printf("ceiling->r = %d\n", map->ceiling->r);
		printf("ceiling->g = %d\n", map->ceiling->g);
		printf("ceiling->b = %d\n\n", map->ceiling->b);
		int i = 0;
		while (i < map->heigth)
		{
			printf("%s\n", map->matrix[i]);
			i++;
		}
	}
	ft_free(map);
//////////////////////////////////////////////////////////////////////////

}
