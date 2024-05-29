/*static char	get_wall_or(int *scr, t_point r_end, t_ray *ray, int i)
{
	int		pos;
	char	res;

	res = 0;
	pos = r_end.y * WIDTH + r_end.x;
	if (ray[i].ang < 90 && scr[pos - WIDTH] == 0xFFFFFF)// && scr[pos + 1] != 0xFFFFFF) && ray[i].ang > 0 
		res = 'S';
	else if (ray[i].ang < 90)
		res = 'W';
	else if (ray[i].ang < 180 && scr[pos - WIDTH] == 0xFFFFFF)// && scr[pos - 1] != 0xFFFFFF)
		res = 'S';
	else if (ray[i].ang < 180)
		res = 'E';
	else if (ray[i].ang < 270 && scr[pos + WIDTH] == 0xFFFFFF)// || (scr[pos + WIDTH - 40] != 0xFFFFFF && scr[pos - WIDTH - 40] != 0xFFFFFF)))
		res = 'N';
	else if (ray[i].ang < 270)
		res = 'E';
	else if (scr[pos + WIDTH] == 0xFFFFFF)// && scr[pos + 1] != 0xFFFFFF)
		res = 'N';
	else
		res = 'W';
	return (res);
}*/

/*static char	get_wall_or(int *scr, t_point r_end, t_ray *ray, int i)
{
	int		pos;
	char	res;

	res = 0;
	pos = r_end.y * WIDTH + r_end.x;
	if (ray[i].ang < 90)
	{
		if (scr[pos - WIDTH] == 0xFFFFFF)// && scr[pos + 1] != 0xFFFFFF) && ray[i].ang > 0 
			res = 'S';
		else if (scr[pos + 1] == 0xFFFFFF)
			res = 'W';
	}
	else if (ray[i].ang < 180)
	{
		if (scr[pos - WIDTH] == 0xFFFFFF)// && scr[pos - 1] != 0xFFFFFF)
			res = 'S';
		else if (scr[pos - 1] == 0xFFFFFF)
		res = 'E';
	}
	else if (ray[i].ang < 270)
	{ 
		if (scr[pos + WIDTH] == 0xFFFFFF)// || (scr[pos + WIDTH - 40] != 0xFFFFFF && scr[pos - WIDTH - 40] != 0xFFFFFF)))
			res = 'N';
		else if (scr[pos - 1] == 0xFFFFFF)
			res = 'E';
	}
	else
	{
		if (scr[pos + WIDTH] == 0xFFFFFF)// && scr[pos + 1] != 0xFFFFFF)
			res = 'N';
		else if (scr[pos + 1] == 0xFFFFFF)
			res = 'W';
	}
	return (res);
}*/

/*static char check_orientation(int *scr, t_point r_end, t_ray *ray, int i)
{
	int	or;

	or = 0;
	if (ray[i].ang == 0)
		or = 'W';
	else if (ray[i].ang == 90)
		or = 'S';
	else if (ray[i].ang == 180)
		or = 'E';
	else if (ray[i].ang == 270)
		or = 'N';
	else
		or = get_wall_or(scr,r_end, ray, i);
	return (or);
}*/