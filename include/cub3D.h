/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:51:58 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/11/16 15:52:02 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# define R_SPEED	0.05
# define M_SPEED	0.1
# define SCREEN_W	1024
# define SCREEN_H	1024

typedef struct s_colour
{
	int				r;
	int				g;
	int				b;
}					t_colour;

typedef struct textures
{
	mlx_texture_t	*n;
	mlx_texture_t	*s;
	mlx_texture_t	*w;
	mlx_texture_t	*e;
}					t_textures;

typedef struct s_map
{
	char			*file;
	char			*north_texture;
	char			*south_texture;
	char			*west_texture;
	char			*east_texture;
	t_colour		*floor;
	t_colour		*ceiling;
	uint32_t		f;
	uint32_t		c;
	char			**matrix;
	int				p_x;
	int				p_y;
	int				width;
	int				heigth;
	char			orientation;
	t_textures		*text;
}					t_map;

typedef struct s_player
{
	char		**map;
	double		p_x;
	double		p_y;
	double		d_x;
	double		d_y;
	double		plan_x;
	double		plan_y;
	double		cam;
	double		ray_d_x;
	double		ray_d_y;
	int			tex_x;
	int			map_x;
	int			map_y;
	double		side_d_x;
	double		side_d_y;
	double		delta_d_x;
	double		delta_d_y;
	int			step_x;
	int			step_y;
	double		perp_wall_dist;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	mlx_t		*mlx;
	mlx_image_t	*walls;
	mlx_image_t	*bg;
	t_map		*mapa;
}	t_player;

//src/parse/get_file_content.c
void			get_file_content(t_player *player, char *file);

//src/parse/get_text_and_colours.c
void			get_textures_and_colours(t_map *map, int fd, int *map_pos);
int				allocate_text_and_colour(t_map *map, char *buff, int *counter);
int				get_texture(char **map_texture, char **split, int *counter);
int				get_colour(t_colour **map_colour, char **split, int *counter);

//src/parse/get_map.c
void			get_map(t_map *map, int fd, int *map_pos);
void			count_map_lines(t_map *map, int fd, int *map_pos);
void			get_map_line(t_map *map, int *new_fd, int map_pos);
void			allocate_map(t_map *map, int new_fd);
void			square_up_map(t_map *map);

//src/parse/check_map.c
void			check_map(t_map *map);
void			check_valid_char(char c, int *wall);
void			check_player_position(t_map *map, int n, int i, int *player);
void			check_walls(t_map *map, int n, int i);
void			check_sides(t_map *map, int n, int i);

//src/parse/utils.c
char			*get_line(int fd, int *map_pos);
int				get_tabs(char *buffer);
char			*ft_convert(char *buffer);
void			ft_error(char *message, char *file);
void			ft_free(t_map *map);

//src/gnl/get_next_line.c
char			*get_next_line(int fd);

//src/gnl/get_next_line_utils.c
void			*gnl_calloc(size_t nmemb, size_t size);
char			*gnl_strchr(char *s, int c);
char			*gnl_strdup(char *s);
char			*gnl_strjoin(char *s1, char *s2, int flag);
char			*gnl_substr(char *s, unsigned int start, size_t len, int flag);

//src/init/init.c
void			ft_init_player(t_player *player);
void			ft_init_game(t_player	*player);

//src/raycaster/draw.c
void			ft_draw_bg(t_player *player);
void			ft_draw(t_player *player);
void			ft_draw_wall(mlx_texture_t *texture, int x, t_player *player);


//src/raycaster/raycaster_o.c
void			ft_calc_delta(t_player *player);
void			ft_calc_step_and_initial_sidedist(t_player *player);
void			ft_dda_algorithm(t_player *player);
void			ft_distance_perp_wall(t_player	*player);

//src/raycaster/raycaster_1.c
mlx_texture_t	*ft_load_texture(t_player *player);
void			ft_calc_wallx(t_player *player);

//src/hook/hook.c
void			hook(void *param);

//src/free/free_game.c
void			ft_free_game(t_player *player);

#endif
