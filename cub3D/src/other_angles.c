
#include "cub3D.h"

static void	first_quadr(int *scr, t_point *pts, float ang)
{
	int	i;

	i = 0;
	pts[1].x = pts[0].x + cos(deg_to_rad(ang)) * i;
	pts[1].y = pts[0].y - sin(deg_to_rad(ang)) * i;
	while (scr[WIDTH * pts[1].y + pts[1].x] != 0xFFFFFF
		&& pts[1].y >= 0 && pts[1].x >= 0
		&& pts[1].x < WIDTH && pts[1].y < HEIGHT
		&& scr[WIDTH * pts[1].y + pts[1].x + 1] != 0xFFFFFF
		&& scr[WIDTH * pts[1].y + pts[1].x - WIDTH] != 0xFFFFFF)
	{
		i++;
		pts[1].x = pts[0].x + cos(deg_to_rad(ang)) * i;
		pts[1].y = pts[0].y - sin(deg_to_rad(ang)) * i;
	}
	/*if (scr[WIDTH * pts[1].y + pts[1].x] == 0xFFFFFF
		|| (scr[WIDTH * pts[1].y + pts[1].x - 1] == 0xFFFFFF
			&& scr[WIDTH * pts[1].y + pts[1].x + WIDTH] == 0xFFFFFF))
	{
		i -= 1;
		pts[1].x = pts[0].x + cos(deg_to_rad(ang)) * i;
		pts[1].y = pts[0].y - sin(deg_to_rad(ang)) * i;
	}*/
}

void	other_angles(int *scr, t_point *pts, float ang)
{
	first_quadr(scr, pts, ang);
	
}