#include "../../include/cub3D.h"

t_map	*init_struct(void)
{
	t_map	*map;

	map = (t_map *)ft_calloc(sizeof(t_map), 1);
	map->floor = NULL;
	map->ceiling = NULL;
	return (map);
}

void	ft_error(char *msg, char *origin)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(msg, 2);
	if (origin != NULL)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(origin, 2);
	}
	if (origin == NULL
		|| (origin != NULL && origin[ft_strlen(origin) - 1] != '\n'))
		ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}
