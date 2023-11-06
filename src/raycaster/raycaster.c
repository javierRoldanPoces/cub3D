#include "../../include/cub3D.h"

//	 Funcion para calcular deltaDistX y deltaDistY que son la distancia que debe recorrer el rayo 
//   para pasar de 1 lado x al siguiente lado x, o de 1 lado y al siguiente lado y.

void	ft_calc_delta(t_player *player)
{
	if (!player->ray_d_x)
		player->delta_d_x = 1e30;
	else
		player->delta_d_x = fabs(1 / player->ray_d_x);
	if (!player->ray_d_y == 0)
		player->delta_d_y = 1e30;
	else
		player->delta_d_y = fabs(1 / player->ray_d_y);
}
