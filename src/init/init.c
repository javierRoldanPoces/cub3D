#include "../../include/cub3D.h"

void    get_textures(t_map  *map)
{
	map->text.n =mlx_load_png(map->north_texture);
	map->text.s =mlx_load_png(map->south_texture);
	map->text.w =mlx_load_png(map->west_texture);
	map->text.e =mlx_load_png(map->east_texture);
	if(!map->text.n || !map->text.s || !map->text.w || !map->text.e)
		printf("error carga de texturas\n");
}