#include "../../include/cub3D.h"

void	hook(void *param)
{
	t_player	*player;
	double		olddirx;
	double		oldplanex;

	player = param;
	olddirx = player->d_x;
	oldplanex = player->plan_x;
	if (mlx_is_key_down(player->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(player->mlx);//Liberar todo antes de llamar a mlx_cose_windows
	if (mlx_is_key_down(player->mlx, MLX_KEY_LEFT))
	{
		//both camera direction and camera plane must be rotated rotated to the left
		player->d_x = player->d_x * cos(SPEED_R) - player->d_y * sin(SPEED_R);
		player->d_y = olddirx * sin(SPEED_R) + player->d_y * cos(SPEED_R);
		player->plan_x = player->plan_x * cos(SPEED_R) - player->plan_y * sin(SPEED_R);
		player->plan_y = oldplanex * sin(SPEED_R) + player->plan_y * cos(SPEED_R);
	}
	if (mlx_is_key_down(player->mlx, MLX_KEY_RIGHT))
	{
		//both camera direction and camera plane must be rotated rotated to the left
		player->d_x = player->d_x * cos(- SPEED_R) - player->d_y * sin(-SPEED_R);
		player->d_y = olddirx * sin(- SPEED_R) + player->d_y * cos(- SPEED_R);
		player->plan_x = player->plan_x * cos(-SPEED_R) - player->plan_y * sin(-SPEED_R);
		player->plan_y = oldplanex * sin(-SPEED_R) + player->plan_y * cos(-SPEED_R);	
	
	}
	ft_draw(player);
}
