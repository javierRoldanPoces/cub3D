#include "../../include/cub3D.h"

void	check_map(t_map *map)
{
	int	n;
	int	i;
	int	player;
	int	wall;

	n = 0;
	player = 0;
	wall = 0;
	while (n < map->heigth)
	{
		i = 0;
		while (map->matrix[n][i] != '\0')
		{
			check_valid_char(map->matrix[n][i], &wall);
			check_player_position(map, n, i, &player);
			check_walls(map, n, i);
			i++;
		}
		n++;
	}
	if (player == 0 || wall == 0 || map->heigth < 3 || map->width < 3)
		ft_error("invalid map design0", NULL);
}

void	check_valid_char(char c, int *wall)
{
	if (c != ' ' && c != '1' && c != '0'
		&& c != 'N' && c != 'S' && c != 'W' && c != 'E')
		ft_error("invalid map design1", NULL);
	if (c == '1')
		*wall = 1;
}

void	check_player_position(t_map *map, int n, int i, int *player)
{
	if (map->matrix[n][i] == 'N' || map->matrix[n][i] == 'S'
		|| map->matrix[n][i] == 'W' || map->matrix[n][i] == 'E')
	{
		if (*player != 0)
			ft_error("invalid map design2", NULL);
		else
		{
			*player = 1;
			check_sides(map, n, i);
		}
	}
}

void	check_walls(t_map *map, int n, int i)
{
	if (map->matrix[n][i] == '0')
	{
		if (n == 0 || n == map->heigth - 1
			|| i == 0 || i == map->width - 1)
			ft_error("invalid map design7", NULL);
		check_sides(map, n, i);
	}
}

void	check_sides(t_map *map, int n, int i)
{
	if (n > 0)
		if (map->matrix[n - 1][i] == ' ')
			ft_error("invalid map design3", NULL);
	if (n < map->heigth)
		if (map->matrix[n + 1][i] == ' ')
			ft_error("invalid map design4", NULL);
	if (i > 0)
		if (map->matrix[n][i - 1] == ' ')
			ft_error("invalid map design5", NULL);
	if (i < map->width)
		if (map->matrix[n][i + 1] == ' ')
			ft_error("invalid map design6", NULL);
}
