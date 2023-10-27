#include "../include/cub3D.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
		check_cub_file(argv[1]);
	else
		error("invalid number of arguments", NULL);
	return (0);
}
