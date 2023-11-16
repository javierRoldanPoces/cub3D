/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:53:14 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/11/16 15:53:14 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	get_color(t_map *map)
{
	map->c = (map->floor->r << 24) | (map->floor->g << 16) \
	| (map->floor->b << 8) | 255;
	map->f = (map->ceiling->r << 24) | (map->ceiling->g << 16) \
	| (map->ceiling->b << 8) | 255;
}

static void	get_textures(t_player *player)
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

void	get_file_content(t_player *player, char *file)
{
	int	fd;
	int	map_pos;

	if (ft_strlen(ft_strnstr(file, ".cub", ft_strlen(file))) != 4)
		ft_error("unsupported file extension", file);
	else
	{
		map_pos = 0;
		player->mapa->file = ft_strdup(file);
		fd = open(player->mapa->file, O_RDONLY);
		if (fd == -1)
			ft_error(strerror(errno), player->mapa->file);
		get_textures_and_colours(player->mapa, fd, &map_pos);
		get_map(player->mapa, fd, &map_pos);
		check_map(player->mapa);
		get_color(player->mapa);
		get_textures(player);
	}
}
