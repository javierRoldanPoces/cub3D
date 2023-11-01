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
# define SCREENWIDTH 1024
# define SCREENHEIGHT 512
# define TEXWIDTH 64
# define TEXHEIGHT 64

typedef struct s_colour
{
	int				r;
	int				g;
	int				b;
}					t_colour;

typedef struct s_player
{
	double		posx; //pos player
	double		posy;
	double		dirx; //Direccion del jugador
	double		diry;
	double		planex; //Plano de camara debe ser perpendicular al plano de dirección
	double		planey;
	double		camerax;
	double		raydirx; // Direccion del rayo
	double		raydiry;
	int			mapx; //Coordenadas del mapa donde se encuentra el rayo
	int			mapy;
	int			stepx;
	int			stepy;
	double		sidedisty; // 	hasta el siguiente lado x o y
	double		deltadistx;
	double		deltadisty;
	double		perpwalldist; // la longitud de sideDist ya casi es igual a perpWallDist. Solo necesitamos 
						  			//restarle deltaDist una vez, retrocediendo un paso, porque en los pasos anteriores de 
						 				 //DDA fuimos un paso más para terminar dentro del muro.
	int			hit; // indica si hemos golpeado o no el muro
	int			side;
	int			lineheight;
	int			drawstart;
	int			drawend;
	// int			tex_width;
	// int			tex_height; ?¿?¿ Iran cambiando ?¿?
	int			tex_x;
	int			tex_y;
	uint32_t	color;
	//mlx_texture_t *texture;

}			t_player;
/* 
El algoritmo DDA siempre saltará exactamente un cuadrado en cada bucle, ya sea un cuadrado en la dirección 
x o un cuadrado en la dirección y. Si tiene que ir en la dirección x negativa o positiva, y la dirección y 
negativa o positiva dependerá de la dirección del rayo, y este hecho se almacenará en stepx y stepy. 
Esas variables son siempre -1 o +

NOTA: Si rayDirX o rayDirY son 0, la división por cero se evita configurándola en un valor muy alto 1e30.
Si está utilizando un lenguaje como C++, Java o JS, esto no es realmente necesario, ya que es compatible con el 
estándar de punto flotante IEEE 754, lo que da el resultado Infinity, que funciona correctamente en el código siguiente.
Sin embargo, algunos otros lenguajes, como Python, no permiten la división hasta cero, por lo que arriba se proporciona el
código más genérico que funciona en todas partes. 1e30 es un número suficientemente alto elegido arbitrariamente y se puede 
establecer en Infinito si su lenguaje de programación admite la asignación de ese valor.

Tenemos que meter en algun sitio las Variables de tiempo
	time		-> Hora del fotograma actual
	old_time	-> Hora del fotograma anterior
	
La diferencia de tiempo entre estos dos se puede utilizar para determinar cuánto debes moverte cuando se
presiona una determinada tecla (para moverte a una velocidad constante sin importar cuánto tarde el cálculo de los fotogramas),
y para el contador de FPS.
*/ 

typedef struct s_map
{
	char			*file;
	char			**matrix;
	char			*north_texture; //path de los png
	char			*south_texture;
	char			*west_texture;
	char			*east_texture;
	t_colour		*floor;
	t_colour		*ceiling;
	t_player		*player;
}					t_map;

typedef struct s_args
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_image_t		*back;
	mlx_image_t		*walls;
	mlx_texture_t	*no_text;
	mlx_texture_t	*so_text;
	mlx_texture_t	*we_text;
	mlx_texture_t	*ea_text;
	t_map			*map;
}	t_args;


/*
	DUDA como y donde declaro el FOV o campo de visión 

 * Recuerda que el plano de camara tiene que ser perpendicular al plano de direccion 
 
La relación entre la longitud del vector dirección y el vector del plano de camara determina FOV (Campo de vision), Aqui la
longitud del vector de direccion sera mayor que la longitud del plano de camara por tanto sera menor que 90 grados 
(more precisely, the FOV is 2 * atan(0.66/1.0)=66°)perfecto para wolfenstein_fuck
*/

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
