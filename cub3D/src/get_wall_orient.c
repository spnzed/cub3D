#include "cub3D.h"

char get_wall_or(int *scr, t_point r_end, t_ray *ray)
{
    char    res;

    res = 0;
    if (ray->ang > 0 && ray->ang < 90)
		res = first(scr, ray->end, ray->ang);
	else if (ray->ang > 90 && ray->ang < 180)
		res = second(scr, ray->end, ray->ang);
	else if (ray->ang > 180 && ray->ang < 270)
		third(scr, ray->end, ray->ang);
	else if (ray->ang > 270 && ray->ang < 360)
		fourth(scr, ray->end, ray->ang);    
}