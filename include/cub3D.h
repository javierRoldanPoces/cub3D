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

typedef struct s_colour
{
	int				r;
	int				g;
	int				b;
}					t_colour;

typedef struct s_map
{
	char			**matrix;
	char			*north_texture;
	char			*south_texture;
	char			*west_texture;
	char			*east_texture;
	t_colour		*floor;
	t_colour		*ceiling;
}					t_map;

//parsing
void		ft_error(char *message, char *file);
void		check_cub_file(char *file, t_map *map);
void		check_file_content(int fd, t_map *map);
int			get_textures_and_colours(char *buffer, int *counter, t_map *map);

//get_next_line
char		*get_next_line(int fd);
void		*gnl_calloc(size_t nmemb, size_t size);
char		*gnl_strchr(char *s, int c);
char		*gnl_strdup(char *s);
char		*gnl_strjoin(char *s1, char *s2, int flag);
char		*gnl_substr(char *s, unsigned int start, size_t len, int flag);

#endif
