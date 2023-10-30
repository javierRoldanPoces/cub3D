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
	// t_map	*map;

	// map = init_struct();
	// if (argc == 2)
	// {
	// 	get_file_content(argv[1], map);
	// }
	// else
	// 	ft_error("invalid number of arguments", NULL);
	// return (0);
	
	mlx_t		*mlx;
	mlx_image_t *g_img;
	(void)argc;
	(void)argv;
	uint32_t color = (0 << 24) | (200 << 16) | (0 << 8) | 255;

	mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	if (!mlx)
		exit (EXIT_FAILURE);
	g_img = mlx_new_image(mlx, 1024, 512);
	memset(g_img->pixels, 150, g_img->width * g_img->height *BPP);
	int i = 256;
	int j = 0;
	while (i < 512)
	{
		j = 0;
		while (j < 512)
		{
			mlx_put_pixel(g_img, i, j, color);
			j++;
		}
		i++;
	}
	while (i < 1024)
	{
		j = 256;
		while (j < 400)
		{
			mlx_put_pixel(g_img, i, j, color);
			j++;
		}
		i++;
	}
	mlx_image_to_window(mlx, g_img, 512, 256);
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



*/