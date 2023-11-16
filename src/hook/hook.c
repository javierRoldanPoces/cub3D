/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:52:54 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/11/16 15:52:56 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static void	ft_orientation_left_hook(t_player	*player);
static void	ft_orientation_right_hook(t_player *player);
static void	ft_move_right_left_hook(t_player *player);
static void	ft_move_front_back_hook(t_player *player);

/*
both camera direction and camera plane must be rotated 
rotated to the left
*/
static void	ft_orientation_left_hook(t_player	*player)
{
	double		olddirx;
	double		oldplanex;

	olddirx = player->d_x;
	oldplanex = player->plan_x;
	if (mlx_is_key_down(player->mlx, MLX_KEY_LEFT))
	{
		player->d_x = player->d_x * cos(R_SPEED) - player->d_y * sin(R_SPEED);
		player->d_y = olddirx * sin(R_SPEED) + player->d_y * cos(R_SPEED);
		player->plan_x = player->plan_x * cos(R_SPEED) - player->plan_y \
		* sin(R_SPEED);
		player->plan_y = oldplanex * sin(R_SPEED) + player->plan_y \
		* cos(R_SPEED);
	}
}

/*
both camera direction and camera plane must be rotated 
rotated to the right
*/
static void	ft_orientation_right_hook(t_player *player)
{
	double		olddirx;
	double		oldplanex;

	olddirx = player->d_x;
	oldplanex = player->plan_x;
	if (mlx_is_key_down(player->mlx, MLX_KEY_RIGHT))
	{
		player->d_x = player->d_x * cos(-R_SPEED) - player->d_y \
		* sin(-R_SPEED);
		player->d_y = olddirx * sin(-R_SPEED) + player->d_y * cos(-R_SPEED);
		player->plan_x = player->plan_x * cos(-R_SPEED) - player->plan_y \
		* sin(-R_SPEED);
		player->plan_y = oldplanex * sin(-R_SPEED) + player->plan_y \
		* cos(-R_SPEED);
	}
}

static void	ft_move_right_left_hook(t_player *player)
{
	if (mlx_is_key_down(player->mlx, MLX_KEY_D))
	{
		if (player->map[(int)(player->p_x + player->plan_x * M_SPEED)] \
		[(int)player->p_y] != '1')
			player->p_x += player->plan_x * M_SPEED;
		if (player->map[(int)player->p_x] \
		[(int)(player->p_y + player->plan_y * M_SPEED)] != '1')
			player->p_y += player->plan_y * M_SPEED;
	}
	if (mlx_is_key_down(player->mlx, MLX_KEY_A))
	{
		if (player->map[(int)(player->p_x - player->plan_x * M_SPEED)] \
		[(int)player->p_y] != '1')
			player->p_x -= player->plan_x * M_SPEED;
		if (player->map[(int)player->p_x] \
		[(int)(player->p_y - player->plan_y * M_SPEED)] != '1')
			player->p_y -= player->plan_y * M_SPEED;
	}
}

static void	ft_move_front_back_hook(t_player *player)
{
	if (mlx_is_key_down(player->mlx, MLX_KEY_W))
	{
		if (player->map[(int)(player->p_x + player->d_x * M_SPEED)] \
		[(int)player->p_y] != '1')
			player->p_x += player->d_x * M_SPEED;
		if (player->map[(int)player->p_x] \
		[(int)(player->p_y + player->d_y * M_SPEED)] != '1')
			player->p_y += player->d_y * M_SPEED;
	}
	if (mlx_is_key_down(player->mlx, MLX_KEY_S))
	{
		if (player->map[(int)(player->p_x - player->d_x * M_SPEED)] \
		[(int)player->p_y] != '1')
			player->p_x -= player->d_x * M_SPEED;
		if (player->map[(int)player->p_x] \
		[(int)(player->p_y - player->d_y * M_SPEED)] != '1')
			player->p_y -= player->d_y * M_SPEED;
	}
}

void	hook(void *param)
{
	t_player	*player;

	player = param;
	if (mlx_is_key_down(player->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(player->mlx);
		ft_free_game(player);
		exit (EXIT_SUCCESS);
	}	
	ft_move_front_back_hook(player);
	ft_move_right_left_hook(player);
	ft_orientation_left_hook(player);
	ft_orientation_right_hook(player);
	ft_draw(player);
}
