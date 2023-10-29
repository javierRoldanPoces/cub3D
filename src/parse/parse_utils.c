#include "../../include/cub3D.h"

void	ft_error(char *msg, char *origin)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(msg, 2);
	if (origin != NULL)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(origin, 2);
	}
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}
