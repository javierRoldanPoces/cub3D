#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <stdio.h>


//get_next_line
char		*get_next_line(int fd);
void		*gnl_calloc(size_t nmemb, size_t size);
char		*gnl_strchr(char *s, int c);
char		*gnl_strdup(char *s);
char		*gnl_strjoin(char *s1, char *s2, int flag);
char		*gnl_substr(char *s, unsigned int start, size_t len, int flag);

#endif
