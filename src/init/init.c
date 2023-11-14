#include "../../include/cub3D.h"

static void	ft_orientation(t_player *player);

static void	ft_orientation(t_player *player)
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

void	ft_init_player(t_player *player)
{
	player->mapa = (t_map *)ft_calloc(sizeof(t_map), 1);
	player->mapa->text = (t_textures *)malloc(sizeof(t_textures));
}

void	ft_init_game(t_player	*player)
{
	player->map = player->mapa->matrix;
	player->p_x = player->mapa->p_x + 0.5;
	player->p_y = player->mapa->p_y + 0.5;
	ft_orientation(player);
	player->mlx = mlx_init(SCREEN_W, SCREEN_H, "cub3D", false);
	if (!player->mlx)
		exit (EXIT_FAILURE);
	player->bg = mlx_new_image(player->mlx, SCREEN_W, SCREEN_H);
	if (!player->bg)
		exit (EXIT_FAILURE);
	ft_draw_bg(player);
	player->walls = mlx_new_image(player->mlx, SCREEN_W, SCREEN_H);
	if (!player->walls)
		exit(EXIT_FAILURE);
	ft_draw(player);
}
