#include "../include/cub3D.h"

void	get_file_content(char *file, t_map *map)
{
	int	fd;

	if (ft_strlen(ft_strnstr(file, ".cub", ft_strlen(file))) != 4)
		ft_error("unsupported file extension", file);
	else
	{
		map->file = ft_strdup(file);
		fd = open(file, O_RDONLY);
		if (fd == -1)
			ft_error(strerror(errno), file);
		get_struct(fd, map);
		get_map(fd, map);
	}
}

int	main(int argc, char **argv)
{
	t_map	*map;

	map = init_struct();
	if (argc == 2)
	{
		get_file_content(argv[1], map);
	}
	else
		ft_error("invalid number of arguments", NULL);
	return (0);
}
