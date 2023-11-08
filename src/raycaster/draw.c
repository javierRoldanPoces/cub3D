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
	//mlx_image_to_window(player->mlx, player->bg, 0, 0);
}

void	ft_draw(t_player *player)
{
	int				x;
	mlx_texture_t	*texture;

	if (player->walls)
	{
		mlx_delete_image(player->mlx, player->walls);
		player->walls = mlx_new_image(player->mlx, SCREEN_W, SCREEN_H);
	}
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
		player->hit = 0;
		ft_calc_step_and_initial_sidedist(player);
		//player->side = 0; //Hubo golpe en pared
		//funcion para calcular pasos y valor inicial de sidedist (side_d_x y side_d_y)
		//ft_calculate_step_sidedist(player);
		ft_dda_algorithm(player);
		//cargar textura correcta dependiendo del valor de side(lado que golpea el rayo)
		texture = ft_load_texture(player);
		ft_calc_wallx(player);
		//(void)texture;
		ft_drwaw_wall(texture, x, player);

		//queda pintar el puto muro y a ver q pasa y los hook
		x++;
	}
	mlx_image_to_window(player->mlx, player->walls, 0, 0);

	// printf("************** Calculos obtenidos con funcion calc_delta***\n");
	// printf("player->delta_d_x = %lf\n", player->delta_d_x);
	// printf("player->delta_d_y = %lf\n", player->delta_d_y);
	// printf("************** Calculos obtenidos con funcion calc_step_and_initial_sidedist***\n");
	// printf("player->step_x = %d\n", player->step_x);
	// printf("player->side_d_x = %lf\n", player->side_d_x);
	// printf("player->step_y = %d\n", player->step_y);
	// printf("player->side_d_y = %lf\n", player->side_d_y);
}

uint32_t	ft_get_uin32(uint8_t *conv, int n)
{
	uint32_t	u;

	u = conv[n] << 24;
	u += conv[n + 1] << 16;
	u += conv[n + 2] << 8;
	u += conv[n + 3];
	return (u);
}

void	ft_drwaw_wall(mlx_texture_t *texture, int x, t_player *player)
{
	double		step;
	double		tex_pos;
	uint32_t	color;
	int			y;

	step = (double)texture->height / player->line_height;
	tex_pos = (player->draw_start - SCREEN_H / 2 + player->line_height / 2) * step;
	y = player->draw_start;
	while (y < player->draw_end)
	{
		color = ft_get_uin32(texture->pixels, texture->width * (int)tex_pos * 4 + (int)player->tex_x * 4);
		mlx_put_pixel(player->walls,x, y, color);
		tex_pos += step;
		y++;
	}
}

/*
Finally, the current buffer pixel is set to this color, and we move on to the next y.

     // How much to increase the texture coordinate per screen pixel
      double step = 1.0 * texHeight / lineHeight;
     // Starting texture coordinate
      double texPos = (drawStart - h / 2 + lineHeight / 2) * step;
      for(int y = drawStart; y<drawEnd; y++)
      {
        // Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
        int texY = (int)texPos & (texHeight - 1);
        texPos += step;
        Uint32 color = texture[texNum][texHeight * texY + texX];
        //make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
        if(side == 1) color = (color >> 1) & 8355711;
        buffer[y][x] = color;
      }
    }



*/