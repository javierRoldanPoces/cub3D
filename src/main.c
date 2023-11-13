#include "../include/cub3D.h"

// static void	print_data_map_arg(t_map *map)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	j = 0;
// 	printf("NO = %s\n", map->north_texture);
// 	printf("SO = %s\n", map->south_texture);
// 	printf("WE = %s\n", map->west_texture);
// 	printf("EA = %s\n\n", map->east_texture);
// 	printf("floor->r = %d\n", map->floor->r);
// 	printf("floor->g = %d\n", map->floor->g);
// 	printf("floor->b = %d\n\n", map->floor->b);
// 	printf("ceiling->r = %d\n", map->ceiling->r);
// 	printf("ceiling->g = %d\n", map->ceiling->g);
// 	printf("ceiling->b = %d\n\n", map->ceiling->b);
// 	while (i < map->heigth)
// 	{
// 		j = 0;
// 		while (j < map->width)
// 		{
// 			printf("%c", map->matrix[i][j]);
// 			j++;
// 		}
// 		printf("\n");
// 		i++;
// 	}
// 	printf("Posicion del jugador en el mapa [%d][%d]\n", map->p_x, map->p_y);
// 	printf("Orientacion del jugador %c\n", map->orientation);
// 	printf("map->height = %d\n", map->heigth);
// 	printf("map->w = %d\n", map->width);
// }

void	ft_init_player(t_player *player)
{
	player->mapa = (t_map *)ft_calloc(sizeof(t_map), 1);
	player->mapa->text = (t_textures *)malloc(sizeof(t_textures));

}

int	main(int argc, char **argv)
{
	t_player		*player;

	player = (t_player *)malloc(sizeof(t_player));
	//Funcion para inicializar las reservas necesarias de t_player
	//player->mapa = (t_map *)ft_calloc(sizeof(t_map), 1);
	ft_init_player(player);
	if (argc == 2)
	{
		get_file_content(player->mapa, argv[1]);
		//print_data_map_arg(player.mapa);
		ft_init_game(player);
		mlx_image_to_window(player->mlx, player->walls, 0, 0);
		mlx_loop_hook(player->mlx, &hook, player);
		mlx_loop(player->mlx);
		mlx_terminate(player->mlx);
	}
	else
		ft_error("invalid number of arguments", NULL);
	return (0);
}
