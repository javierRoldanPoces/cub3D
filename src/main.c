#include "../include/cub3D.h"

int	main(int argc, char **argv)
{
	if (argc > 1 && argv[0] != NULL)
	{
		printf("hola!\n");
		printf("strlen = %d\n", ft_strlen("hola"));
		printf("%s\n", get_next_line(STDIN_FILENO));
	}
	return (0);
}
