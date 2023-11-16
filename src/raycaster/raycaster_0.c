/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:53:41 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/11/16 15:53:42 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	ft_calc_delta(t_player *player)
{
	if (!player->ray_d_x)
		player->delta_d_x = 1e30;
	else
		player->delta_d_x = fabs(1 / player->ray_d_x);
	if (!player->ray_d_y)
		player->delta_d_y = 1e30;
	else
		player->delta_d_y = fabs(1 / player->ray_d_y);
}

void	ft_calc_step_and_initial_sidedist(t_player *player)
{
	if (player->ray_d_x < 0)
	{
		player->step_x = -1;
		player->side_d_x = (player->p_x - player->map_x) * player->delta_d_x;
	}
	else
	{
		player->step_x = 1;
		player->side_d_x = (player->map_x + 1.0 - player->p_x) * \
		player->delta_d_x;
	}
	if (player->ray_d_y < 0)
	{
		player->step_y = -1;
		player->side_d_y = (player->p_y - player->map_y) * player->delta_d_y;
	}
	else
	{
		player->step_y = 1;
		player->side_d_y = (player->map_y + 1.0 - player->p_y) * \
		player->delta_d_y;
	}
}

void	ft_dda_algorithm(t_player *player)
{
	while (player->hit == 0)
	{
		if (player->side_d_x < player->side_d_y)
		{
			player->side_d_x += player->delta_d_x;
			player->map_x += player->step_x;
			if ((player->map_x - player->p_x) >= 0)
				player->side = 2;
			else
				player->side = 0;
		}
		else
		{
			player->side_d_y += player->delta_d_y;
			player->map_y += player->step_y;
			if ((player->map_y - player->p_y >= 0))
				player->side = 1;
			else
				player->side = 3;
		}
		if (player->map[player->map_x][player->map_y] == '1')
			player->hit = 1;
	}
	ft_distance_perp_wall(player);
}

void	ft_distance_perp_wall(t_player	*player)
{
	if (player->side == 0 || player->side == 2)
		player->perp_wall_dist = player->side_d_x - player->delta_d_x;
	else
		player->perp_wall_dist = player->side_d_y - player->delta_d_y;
	player->line_height = (int)(SCREEN_W / player->perp_wall_dist);
	player->draw_start = -player->line_height / 2 + SCREEN_H / 2;
	if (player->draw_start < 0)
		player->draw_start = 0;
	player->draw_end = player->line_height / 2 + SCREEN_H / 2;
	if (player->draw_end >= SCREEN_H)
		player->draw_end = SCREEN_H - 1;
}
