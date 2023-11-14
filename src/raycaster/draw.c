#include "../../include/cub3D.h"

static uint32_t	ft_get_uin32(uint8_t *conv, int n);
static void		ft_loop_draw(t_player *player);

static uint32_t	ft_get_uin32(uint8_t *conv, int n)
{
	uint32_t	u;

	u = conv[n] << 24;
	u += conv[n + 1] << 16;
	u += conv[n + 2] << 8;
	u += conv[n + 3];
	return (u);
}

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
	if (mlx_image_to_window(player->mlx, player->bg, 0, 0) < 0)
		exit (EXIT_FAILURE);
}

static void	ft_loop_draw(t_player *player)
{
	int				x;
	mlx_texture_t	*texture;

	x = 0;
	while (x < SCREEN_W)
	{
		player->cam = 2 * x / (double)SCREEN_W - 1;
		player->ray_d_x = player->d_x + player->plan_x * player->cam;
		player->ray_d_y = player->d_y + player->plan_y * player->cam;
		player->map_x = (int)player->p_x;
		player->map_y = (int)player->p_y;
		ft_calc_delta(player);
		player->hit = 0;
		ft_calc_step_and_initial_sidedist(player);
		ft_dda_algorithm(player);
		texture = ft_load_texture(player);
		ft_calc_wallx(player);
		ft_draw_wall(texture, x, player);
		x++;
	}
}

void	ft_draw(t_player *player)
{
	if (player->walls)
	{
		mlx_delete_image(player->mlx, player->walls);
		player->walls = mlx_new_image(player->mlx, SCREEN_W, SCREEN_H);
	}
	ft_loop_draw(player);
	if (mlx_image_to_window(player->mlx, player->walls, 0, 0) < 0)
		exit (EXIT_FAILURE);
}

void	ft_draw_wall(mlx_texture_t *texture, int x, t_player *player)
{
	double		step;
	double		tex_pos;
	uint32_t	color;
	int			y;

	step = (double)texture->height / player->line_height;
	tex_pos = (player->draw_start - SCREEN_H / 2 + player->line_height / 2) \
				* step;
	y = player->draw_start;
	while (y < player->draw_end)
	{
		color = ft_get_uin32(texture->pixels, texture->width * (int)tex_pos \
				* 4 + (int)player->tex_x * 4);
		mlx_put_pixel(player->walls, x, y, color);
		tex_pos += step;
		y++;
	}
}
