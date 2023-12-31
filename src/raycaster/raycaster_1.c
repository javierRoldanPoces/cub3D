/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:53:47 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/11/16 15:53:48 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

mlx_texture_t	*ft_load_texture(t_player *player)
{
	if (player->side == 0)
		return (player->mapa->text->n);
	else if (player->side == 1)
		return (player->mapa->text->e);
	else if (player->side == 2)
		return (player->mapa->text->s);
	else
		return (player->mapa->text->w);
}

void	ft_calc_wallx(t_player *player)
{
	double	wallx;

	if (player->side == 0 || player->side == 2)
		wallx = player->p_y + player->perp_wall_dist * player->ray_d_y;
	else
		wallx = player->p_x + player->perp_wall_dist * player->ray_d_x;
	wallx -= floor(wallx);
	player->tex_x = (int)(wallx * (double)player->mapa->text->n->width);
	if ((player->side == 2 || player->side == 1))
		player->tex_x = player->mapa->text->n->width - player->tex_x - 1;
}
