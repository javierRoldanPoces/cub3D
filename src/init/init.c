#include "../../include/cub3D.h"

void	ft_draw_bg(t_player *player)
{
	int	i;
	int	j;

	i = 0;
	while (i < SCREEN_W)
	{
		j = 0;
		while (j < SCREEN_H)
		{
			if (j < SCREEN_H / 2)
				mlx_put_pixel(player->bg, i, j, player->mapa->c);
			else
				mlx_put_pixel(player->bg, i, j, player->mapa->f);
			j++;
		}
		i++;
	}
}

// void	ft_draw_walls(t_player *player)
// {
// 	int	x;

// }

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
		printf("Error carga de texturas\n");// Habra q liberrar.
	else
		printf("Texturas cargadas correctamente\n");
}

void	ft_init_game(t_player	*player)
{
	player->map = player->mapa->matrix;
	player->p_x = player->mapa->p_x + 0.5;
	player->p_y = player->mapa->p_y + 0.5;
	ft_orientation(player);
	//Creamos enlace a libreria MLX
	player->mlx = mlx_init(SCREEN_W, SCREEN_H, "cub3D", false);
	//Crea buffer para nueva imagen dl fondo bg, mismo tamaño que pantalla
	player->bg = mlx_new_image(player->mlx, SCREEN_W, SCREEN_H);
	// Pintamos los pixeles en la imagen creada bg usando para ello la mitad de SCREEN_H
	ft_draw_bg(player);
	mlx_image_to_window(player->mlx, player->bg, 0, 0);
	// Crear buffer para nueva imagen Muros
	player->walls = mlx_new_image(player->mlx, SCREEN_W, SCREEN_H);
	// A ver como cojones pinto los putos muros.....
}
