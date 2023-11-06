#include "../include/cub3D.h"

void	print_data_map_arg(t_map *map)
{
	int	i;

	i = 0;
	printf("NO = %s\n", map->north_texture);
	printf("SO = %s\n", map->south_texture);
	printf("WE = %s\n", map->west_texture);
	printf("EA = %s\n\n", map->east_texture);
	printf("floor->r = %d\n", map->floor->r);
	printf("floor->g = %d\n", map->floor->g);
	printf("floor->b = %d\n\n", map->floor->b);
	printf("ceiling->r = %d\n", map->ceiling->r);
	printf("ceiling->g = %d\n", map->ceiling->g);
	printf("ceiling->b = %d\n\n", map->ceiling->b);
	while (i < map->heigth)
	{
		printf("%s\n", map->matrix[i]);
		i++;
	}

	printf("Posicion del jugador en el mapa [%d][%d]\n", map->p_x, map->p_y);
	printf("Orientacion del jugador %c\n", map->orientation);
}



int	main(int argc, char **argv)
{
	t_player		player;

	player.mapa = (t_map *)ft_calloc(sizeof(t_map), 1);
	if (argc == 2)
	{
		get_file_content(player.mapa, argv[1]);
		print_data_map_arg(player.mapa);

		get_textures(player.mapa);
		ft_init_game(&player);
		mlx_loop(player.mlx);
		// mlx_terminate(player.mlx);
	}
	else
		ft_error("invalid number of arguments", NULL);
	return (0);
}
/*
 Main de prueba

 		// mlx = mlx_init(SCREEN_W , SCREEN_H, "cub3D", true);
		// if (!mlx)
		// 	exit (EXIT_FAILURE);
		// g_img = mlx_new_image(mlx, SCREEN_W, SCREEN_H);
		// //memset(g_img->pixels, map->f, g_img->width * g_img->height * sizeof(int32_t));
		// mlx_image_to_window(mlx, g_img,  0, 0);
		// int	i = 256;
		// int j = 0;
		// while (i < 512)
		// {
		// 	j = 0;
		// 	while (j < 512)
		// 	{
		// 		mlx_put_pixel(g_img, i, j, map->c);
		// 		j++;
		// 	}
		// 	i++;
		// }





*/