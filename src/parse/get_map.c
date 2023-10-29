#include "../../include/cub3D.h"

void	get_map(int fd, t_map *map)
{
	char	*buffer;

	buffer = get_next_line(fd);
	map = map;
	while (ft_strncmp(buffer, "\n", 2) == 0)
	{
		free(buffer);
		buffer = get_next_line(fd);
	}
	printf("buffer = %s\n", buffer);
}
