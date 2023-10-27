#include "../../include/cub3D.h"

void	check_cub_file(char *file)
{
	int	fd;

	if (ft_strlen(ft_strnstr(file, ".cub", ft_strlen(file))) != 4)
		error("unsupported file extension", file);
	else
	{
		fd = open(file, O_RDONLY);
		if (fd == -1)
			error(strerror(errno), file);
		// check_file_content(fd);
	}
}

// void	check_file_content(int fd)
// {
	
// }
