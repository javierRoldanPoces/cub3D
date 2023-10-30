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
# define WIDTH 1024
# define HEIGHT 512

typedef struct s_player
{
	double	posx; //pos player
	double	posy;
	double	dirx; //Direccion del jugador
	double	diry;
	double	planex; //Plano de camara debe ser perpendicular al plano de dirección
	double	planey;
	double	camerax;
	double	raydirx;
	double 	raydiry;
	int		mapx;
	int		mapy;
}			t_player;


// typedef struct s_args
// {
// 	mlx_t			*mlx;
// 	mlx_image_t		*img;
// 	//mlx_image_t para las texturas ?¿
// 	t_map			*map;
// }	t_args;

/*
	DUDA como y donde declaro el FOV o campo de visión 

 * Recuerda que el plano de camara tiene que ser perpendicular al plano de direccion 
 
 La  relación entre la longitud del vector dirección y el vector del plano de camara determina FOV (Campo de vision), Aqui la longitud del vector de direccioin 
 sera mayor que la longitud del plano de camara por tanto sera menor que 90 grados (more precisely, the FOV is 2 * atan(0.66/1.0)=66°)perfecto para wolfenstein_fuck
*/


typedef struct s_colour
{
	int				r;
	int				g;
	int				b;
}					t_colour;

typedef struct s_map
{
	char			*file;
	char			**matrix;
	char			*north_texture;
	char			*south_texture;
	char			*west_texture;
	char			*east_texture;
	t_colour		*floor;
	t_colour		*ceiling;
}					t_map;

//main
void		get_file_content(char *file, t_map *map);

//parse/get_map
void		get_map(int fd, t_map *map);

//parse/get_struct
void		get_struct(int fd, t_map *map);
int			get_texture(char **map_texture, char **split, int *counter);
int			get_colour(t_colour **map_colour, char **split, int *counter);
int			get_textures_and_colours(char *buffer, int *counter, t_map *map);

//parse/utils
t_map		*init_struct();
void		ft_error(char *message, char *file);

//get_next_line
char		*get_next_line(int fd);
void		*gnl_calloc(size_t nmemb, size_t size);
char		*gnl_strchr(char *s, int c);
char		*gnl_strdup(char *s);
char		*gnl_strjoin(char *s1, char *s2, int flag);
char		*gnl_substr(char *s, unsigned int start, size_t len, int flag);

//raycast
void		init_player(t_player **player);

#endif
