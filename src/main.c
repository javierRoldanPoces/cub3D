#include "../include/cub3D.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	map = (t_map *)ft_calloc(sizeof(t_map), 1);
	if (argc == 2)
		check_cub_file(argv[1], map);
	else
		ft_error("invalid number of arguments", NULL);
	return (0);
}
