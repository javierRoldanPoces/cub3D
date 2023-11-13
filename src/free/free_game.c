#include "../../include/cub3D.h"

void	ft_free_textures(t_map *map)
{
	if (map->text->n != NULL)
		mlx_delete_texture(map->text->n);
	if (map->text->s != NULL)
		mlx_delete_texture(map->text->s);
	if (map->text->w != NULL)
		mlx_delete_texture(map->text->w);
	if (map->text->n != NULL)
		mlx_delete_texture(map->text->e);
}


void	ft_free_game(t_player *player)
{
	ft_free_textures(player->mapa);
	free(player->mapa->text);
	ft_free(player->mapa);
	//free(player);
}
