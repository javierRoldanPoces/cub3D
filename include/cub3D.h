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

//Eliminar esta estructura y guardar directamente como uint32
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
	t_colour		*floor; // pasarlo y guardarlo a uint32
	t_colour		*ceiling;
	uint32_t		f;//Añadidas para eliminar t_color
	uint32_t		c;
	char			**matrix;
	int				p_x; //Posicion del jugador
	int				p_y;
	int				width; //Tamaño del mapa
	int				heigth;
	char			orientation; //Orientacion
	t_textures		*text; //tambien lo podria haber guaraddo en un array como en la documentación
}					t_map;

typedef struct s_player
{
	char		**map;
	double		p_x;
	double		p_y;
	double		d_x; //posicion inicial vector de direccion
	double		d_y;
	double		plan_x;
	double		plan_y;
	double		cam;
	double		ray_d_x;
	double		ray_d_y;
	int		tex_x; // o double?¿?  manual es int
	int			map_x;
	int			map_y;
	double		side_d_x;
	double		side_d_y;
	double		delta_d_x;
	double		delta_d_y;
	int			step_x;//what direction to step in x or y-direction (either +1 or -1)
	int			step_y;
	double		perp_wall_dist;
	int			hit; // Controla si se ha golpeado una pared
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	//uint32_t	color;
	mlx_t		*mlx;
	mlx_image_t	*walls;
	mlx_image_t	*bg;
	t_map		*mapa;
}	t_player;

//get_file_content
void			get_file_content(t_map *map, char *file);

//parse/get_text_and_colours
void			get_textures_and_colours(t_map *map, int fd, int *map_pos);
int				allocate_text_and_colour(t_map *map, char *buff, int *counter);
int				get_texture(char **map_texture, char **split, int *counter);
int				get_colour(t_colour **map_colour, char **split, int *counter);

//parse/get_map
void			get_map(t_map *map, int fd, int *map_pos);
void			count_map_lines(t_map *map, int fd, int *map_pos);
void			get_map_line(t_map *map, int *new_fd, int map_pos);
void			allocate_map(t_map *map, int new_fd);
void			square_up_map(t_map *map);

//parse/check_map
void			check_map(t_map *map);
void			check_valid_char(char c, int *wall);
void			check_player_position(t_map *map, int n, int i, int *player);
void			check_walls(t_map *map, int n, int i);
void			check_sides(t_map *map, int n, int i);

//parse/utils
char			*get_line(int fd, int *map_pos);
int				get_tabs(char *buffer);
char			*ft_convert(char *buffer);
void			ft_error(char *message, char *file);
void			ft_free(t_map *map);

//get_next_line
char			*get_next_line(int fd);
void			*gnl_calloc(size_t nmemb, size_t size);
char			*gnl_strchr(char *s, int c);
char			*gnl_strdup(char *s);
char			*gnl_strjoin(char *s1, char *s2, int flag);
char			*gnl_substr(char *s, unsigned int start, size_t len, int flag);

//init
void			get_textures(t_map *map);
void			ft_init_game(t_player	*player);
void			ft_orientation(t_player *player);

//draw
void			ft_draw_bg(t_player *player);
void			ft_draw(t_player *player);
void			ft_draw_wall(mlx_texture_t *texture, int x, t_player *player);


//raycasting
void			ft_calc_delta(t_player *player);
void			ft_calc_step_and_initial_sidedist(t_player *player);
void			ft_dda_algorithm(t_player *player);
void			ft_distance_perp_wall(t_player	*player);
mlx_texture_t	*ft_load_texture(t_player *player);
void			ft_calc_wallx(t_player *player);

//hook
void			hook(void *param);

//free
void			ft_free_game(t_player *player);
void			ft_free_textures(t_map *map);


#endif
