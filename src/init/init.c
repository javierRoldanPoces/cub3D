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

void	get_textures(t_player *player)
{
	player->mapa->text->n = mlx_load_png(player->mapa->north_texture);
	player->mapa->text->s = mlx_load_png(player->mapa->south_texture);
	player->mapa->text->w = mlx_load_png(player->mapa->west_texture);
	player->mapa->text->e = mlx_load_png(player->mapa->east_texture);
	if (!player->mapa->text->n || !player->mapa->text->s
		|| !player->mapa->text->w || !player->mapa->text->e)
	{
		ft_free_game(player);
		exit(-1);
	}
}

void	ft_init_game(t_player	*player)
{
	player->map = player->mapa->matrix;
	player->p_x = player->mapa->p_x + 0.5;
	player->p_y = player->mapa->p_y + 0.5;
	ft_orientation(player);
	player->mlx = mlx_init(SCREEN_W, SCREEN_H, "cub3D", false);
	if (!player->mlx)
		exit (-1);
	player->bg = mlx_new_image(player->mlx, SCREEN_W, SCREEN_H);
	if (!player->bg)
		exit (-1);
	ft_draw_bg(player);
	player->walls = mlx_new_image(player->mlx, SCREEN_W, SCREEN_H);
	if (!player->walls)
		exit(-1);
	ft_draw(player);
}
