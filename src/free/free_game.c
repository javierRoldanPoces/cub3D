#include "../../include/cub3D.h"

static void	ft_free_textures(t_map *map);

static void	ft_free_textures(t_map *map)
{
	if (map->text->n)
		mlx_delete_texture(map->text->n);
	if (map->text->s)
		mlx_delete_texture(map->text->s);
	if (map->text->w)
		mlx_delete_texture(map->text->w);
	if (map->text->e)
		mlx_delete_texture(map->text->e);
}

void	ft_free_game(t_player *player)
{
	ft_free_textures(player->mapa);
	free(player->mapa->text);
	ft_free(player->mapa);
	free(player);
}
