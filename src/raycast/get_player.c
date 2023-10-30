#include "../../include/cub3D.h"

void	init_player(t_player **player)
{
	(*player)->posx = 3;
	(*player)->posy = 4;
	(*player)->dirx = -1;
	(*player)->diry = 0;
	(*player)->planex = 0;
	(*player)->planey = 0.66;
}

// 	pl->camerax = 2 * x / (double)WIDTH - 1;
// 	pl->raydirx = pl->dirx + pl->planex * pl->camerax;
// 	pl->raydiry = pl->diry + pl->planey * pl->camerax;
// 	pl->mapx = (int)(pl->x);
// 	pl->mapy = (int)(pl->y);
// 	pl->hit = 0;
// 	if (pl->raydirx == 0)
// 		pl->deltadistx = 1e30;
// 	else
// 		pl->deltadistx = fabs(1 / pl->raydirx);
// 	if (pl->raydiry == 0)
// 		pl->deltadisty = 1e30;
// 	else
// 		pl->deltadisty = fabs(1 / pl->raydiry);

  