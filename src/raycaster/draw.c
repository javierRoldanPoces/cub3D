#include "../../include/cub3D.h"

void	ft_draw_bg(t_player *player)
{
	int	i;
	int	j;

	i = 0;
	while (i < SCREEN_W)
	{
		j = 0;
		while (j < SCREEN_H)
		{
			if (j < SCREEN_H / 2)
				mlx_put_pixel(player->bg, i, j, player->mapa->f);
			else
				mlx_put_pixel(player->bg, i, j, player->mapa->c);
			j++;
		}
		i++;
	}
	mlx_image_to_window(player->mlx, player->bg, 0, 0);

}
void	ft_draw(t_player *player)
{
	int	x;

	x = 0;
	while (x < SCREEN_W)
	{
		//calculate ray position and direction
		player->cam = 2 * x / (double)SCREEN_W -1;
		player->ray_d_x = player->p_x + player->plan_x * player->cam;
		player->ray_d_y = player->p_y + player->plan_y * player->cam;
		//which box of the map we're in
		player->map_x = (int)player->p_x;
		player->map_y = (int)player->p_y;
		////length of ray from one x or y-side to next x or y-side
		ft_calc_delta(player);
		ft_calc_step_and_initial_sidedist(player);
		player->side = 0; //Hubo golpe en pared
		//funcion para calcular pasos y valor inicial de sidedist (side_d_x y side_d_y)
		ft_calculate_step_sidedist(player);
		ft_dda_algorithm(player);
		x++;
	}
	// printf("************** Calculos obtenidos con funcion calc_delta***\n");
	// printf("player->delta_d_x = %lf\n", player->delta_d_x);
	// printf("player->delta_d_y = %lf\n", player->delta_d_y);
	// printf("************** Calculos obtenidos con funcion calc_step_and_initial_sidedist***\n");
	// printf("player->step_x = %d\n", player->step_x);
	// printf("player->side_d_x = %lf\n", player->side_d_x);
	// printf("player->step_y = %d\n", player->step_y);
	// printf("player->side_d_y = %lf\n", player->side_d_y);

}