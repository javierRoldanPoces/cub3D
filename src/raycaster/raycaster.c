#include "../../include/cub3D.h"

/*
Funcion para calcular deltaDistX y deltaDistY que son la distancia que debe recorrer
el rayo para pasar de 1 lado x al siguiente lado x, o de 1 lado y al siguiente lado y.
*/
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

/*
Si la dirección del rayo tiene un componente x negativo, el stepX es -1, 
si la dirección del rayo tiene un componente x positivo stepX +1. Si el 
componente x es 0, no importa el valor que tenga stepX, ya que entonces  
no se utilizará.Lo mismo ocurre con el componente y.
calculate step and initial sideDist
Para estos valores se utiliza el valor entero mapX y se le resta la posición
real, y en algunos de los casos se suma 1,0 dependiendo de si se utiliza el
lado de la izquierda o de la derecha, de arriba o de abajo. Luego obtienes 
la distancia perpendicular a este lado, así que multiplícala con deltaDistX 
o deltaDistY para obtener la distancia euclidiana real.
*/
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
		player->side_d_y = (player->map_y + 1.0 - player->p_y) * \
		player->delta_d_y;
}

/*
Funcion para calcular pasos y valor inicial sidedist (side_d_x y side_d_y)
*/
void	ft_calculate_step_sidedist(t_player *player)
{
	if (player->ray_d_x < 0)
	{
		player->step_x = -1;
		player->side_d_x = (player->p_x - player->map_x) * player->delta_d_x;
	}
	else
	{
		player->step_x = 1;
		player->side_d_x = (player->map_x + 1.0 - player->p_x) \
		* player->delta_d_x;
	}
	if (player->ray_d_y < 0)
	{
		player->step_y = -1;
		player->side_d_y = (player->p_y - player->map_y) * player->delta_d_y;
	}
	else
	{
		player->step_y = 1;
		player->side_d_y = (player->map_y + 1.0 - player->p_y) \
		* player->delta_d_y;
	}

}

/*
Desarrollo del algorimo DDA
*/
void	ft_dda_algorithm(t_player *player)
{
	while (player->hit == 0)
	{
		//jump to next map square, either in x-direction, or in y-direction
		if (player->side_d_x < player->side_d_y)
		{
			player->side_d_x += player->delta_d_x;
			player->map_x += player->step_x;
			player->side = 0;
		}
		else
		{
			player->side_d_y += player->delta_d_y;
			player->map_y += player->step_y;
			player->side = 1;
		}
        //Check if ray has hit a wall
		if (player->map[player->map_x][player->map_y] == 1)
			player->hit = 1;
	}
}
