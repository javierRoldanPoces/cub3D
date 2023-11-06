#include "../../include/cub3D.h"

void	ft_orientation(t_player *player)
{
	player->d_x = 0;
	player->d_y = 0;
	player->plan_x = 0;
	player->plan_y = 0;
	printf("La orientacion guardada es %c\n", player->mapa->orientation);
	if (player->mapa->orientation == 'N')
	{
		player->d_x = -1;
		player->plan_y = 0.66;
	}
	else if (player->mapa->orientation == 'S')
	{
		player->d_x = 1;
		player->plan_y = -0.66;
	}
	else if (player->mapa->orientation == 'E')
	{
		player->d_y = 1;
		player->plan_x = 0.66;
	}
	else if (player->mapa->orientation == 'W')
	{
		player->d_y = -1;
		player->plan_x = -0.66;
	}
	printf("Valores almacenados en d_x = %lf\n", player->d_x);
	printf("Valores almacenados en d_y = %lf\n", player->d_y);
	printf("Valores almacenados en plan_x = %lf\n", player->plan_x);
	printf("Valores almacenados en plan_y = %lf\n", player->plan_y);
}

void	get_textures(t_map *map)
{
	map->text.n = mlx_load_png(map->north_texture);
	map->text.s = mlx_load_png(map->south_texture);
	map->text.w = mlx_load_png(map->west_texture);
	map->text.e = mlx_load_png(map->east_texture);
	if (!map->text.n || !map->text.s || !map->text.w || !map->text.e)
		printf("Error carga de texturas\n");
	else
		printf("Texturas cargadas correctamente\n");
}

void	ft_init_game(t_player	*player)
{
	player->map = player->mapa->matrix;
	player->p_x = player->mapa->p_x + 0.5;
	player->p_y = player->mapa->p_y + 0.5;
	printf("El valor de p_x es: %lf\n", player->p_x);
	printf("El valor de p_y es: %lf\n", player->p_y);
	ft_orientation(player);
	// printf("La orientacion guardada es %c\n", player->mapa->orientation);
	//funcion orientation
}
