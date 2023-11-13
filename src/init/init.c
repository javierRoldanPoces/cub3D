#include "../../include/cub3D.h"

void	ft_orientation(t_player *player)
{
	player->d_x = 0;
	player->d_y = 0;
	player->plan_x = 0;
	player->plan_y = 0;
	if (player->mapa->orientation == 'N')
	{
		player->d_x = -1.1;
		player->plan_y = 0.66;
	}
	else if (player->mapa->orientation == 'S')
	{
		player->d_x = 1.1;
		player->plan_y = -0.66;
	}
	else if (player->mapa->orientation == 'E')
	{
		player->d_y = 1.1;
		player->plan_x = 0.66;
	}
	else if (player->mapa->orientation == 'W')
	{
		player->d_y = -1.1;
		player->plan_x = -0.66;
	}
}

void	get_textures(t_map *map)
{
	map->text->n = mlx_load_png(map->north_texture);
	map->text->s = mlx_load_png(map->south_texture);
	map->text->w = mlx_load_png(map->west_texture);
	map->text->e = mlx_load_png(map->east_texture);
	if (!map->text->n || !map->text->s || !map->text->w || !map->text->e)
	{
		//ft_free_textures(map);
		exit(-1);
		//printf("Error carga de texturas\n");// Habra q liberar.
	}	
	else
		printf("Texturas cargadas correctamente\n");
}

void	ft_init_game(t_player	*player)
{
	player->map = player->mapa->matrix;
	player->p_x = player->mapa->p_x + 0.5;
	player->p_y = player->mapa->p_y + 0.5;
	ft_orientation(player);
	player->mlx = mlx_init(SCREEN_W, SCREEN_H, "cub3D", false);
	player->bg = mlx_new_image(player->mlx, SCREEN_W, SCREEN_H);
	ft_draw_bg(player);
	player->walls = mlx_new_image(player->mlx, SCREEN_W, SCREEN_H);
	ft_draw(player);
}
