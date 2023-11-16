/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:53:51 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/11/16 15:53:52 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	leaks(void)
{
	system("leaks -q cub3D");
}

int	main(int argc, char **argv)
{
	t_player		*player;

	atexit(leaks);
	player = (t_player *)malloc(sizeof(t_player));
	ft_init_player(player);
	if (argc == 2)
	{
		get_file_content(player, argv[1]);
		ft_init_game(player);
		if (mlx_image_to_window(player->mlx, player->walls, 0, 0) < 0)
			exit (EXIT_FAILURE);
		mlx_loop_hook(player->mlx, &hook, player);
		mlx_loop(player->mlx);
		mlx_terminate(player->mlx);
	}
	else
		ft_error("invalid number of arguments", NULL);
	return (0);
}
