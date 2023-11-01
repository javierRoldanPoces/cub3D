#include "../include/cub3D.h"

// void	get_file_content(char *file, t_map *map)
// {
// 	int	fd;

// 	if (ft_strlen(ft_strnstr(file, ".cub", ft_strlen(file))) != 4)
// 		ft_error("unsupported file extension", file);
// 	else
// 	{
// 		map->file = ft_strdup(file);
// 		fd = open(file, O_RDONLY);
// 		if (fd == -1)
// 			ft_error(strerror(errno), file);
// 		get_struct(fd, map);
// 		get_map(fd, map);
// 	}
// }

int	main(int argc, char **argv)
{
	mlx_t			*mlx;
	mlx_image_t		*g_img;
	t_player		*player;


	uint32_t color_floor = (255 << 24) | (255 << 16) | (255 << 8) | 255;

	(void)argc;
	(void)argv;
	player = ft_calloc(1, sizeof(t_player));
	int matrix[5][6] = {
		{1, 1, 1, 1, 1, 1},
        {1, 0, 0, 1, 0, 1},
        {1, 0, 1, 0, 0, 1},
        {1, 1, 0, 0, 5, 1},
        {1, 1, 1, 1, 1, 1}
    };

	printf("player representado por el numero  %d \n", matrix[3][4]);
	init_player(&player);
	printf("posx posy de t_player contiene el valor  %d \n", matrix[(int)(*player).posx][(int)(*player).posy]);

	mlx = mlx_init(SCREENWIDTH , SCREENHEIGHT, "cub3D", true);
	if (!mlx)
		exit (EXIT_FAILURE);
	g_img = mlx_new_image(mlx, SCREENWIDTH, SCREENHEIGHT);
	memset(g_img->pixels, color_floor, g_img->width * g_img->height * sizeof(int32_t));

	mlx_image_to_window(mlx, g_img,  0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

/*

// Definir un color RGBA en formato uint32_t
uint32_t colorRGBA = 0xFFAABBCC; // Formato: 0xRRGGBBAA

// Descomponer el color en sus componentes
uint8_t red = (colorRGBA >> 24) & 0xFF;   // Componente Rojo
uint8_t green = (colorRGBA >> 16) & 0xFF; // Componente Verde
uint8_t blue = (colorRGBA >> 8) & 0xFF;   // Componente Azul
uint8_t alpha = colorRGBA & 0xFF;        // Componente Alfa

uint32_t color = (0 << 24) | (200 << 16) | (0 << 8) | 255;

	// int i = 256;
	// int j = 0;
	// while (i < 512)
	// {
	// 	j = 0;
	// 	while (j < 512)
	// 	{
	// 		mlx_put_pixel(g_img, i, j, color_wall);
	// 		j++;
	// 	}
	// 	i++;
	// }

		//uint32_t color_wall = (0 << 24) | (200 << 16) | (0 << 8) | 255;




*/