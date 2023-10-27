#include "../../include/cub3D.h"

void	error(char *message, char *file)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(message, 2);
	if (file != NULL)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(file, 2);
	}
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}
