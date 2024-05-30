/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_ray_OLD_.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:09:09 by erosas-c          #+#    #+#             */
/*   Updated: 2024/05/30 21:16:03 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*static int	rayend_mappos(t_point hit, char wll_or, int cell_w, int *m_sz)
{
	int	res;
	int	y_off;
	int	x_off;

	res = 0;
	x_off = WIDTH / 2 - m_sz[X] * cell_w / 2;
	y_off = HEIGHT / 2 - m_sz[Y] * cell_w / 2;
	if (wll_or == 'E' || wll_or == 'W')
		res = (hit.y + y_off) / cell_w;
	if (wll_or == 'N' || wll_or == 'S')
		res = (hit.x + x_off) / cell_w;
	return (res);
}*/

/*static char	get_wall_or(int *scr, t_point r_end)//, t_ray *ray, int i)
{
	int	pos;

	pos = r_end.y * WIDTH + r_end.x;*/
	/*if (i > 0)
	{
		if ((ray[i - 1].wall_or == 'N' || ray[i - 1].wall_or == 'S')
			&& ray[i].end[Y] == ray[i - 1].end[Y])
			return (ray[i - 1].wall_or);
		else if ((ray[i - 1].wall_or == 'E' || ray[i - 1].wall_or == 'W')
			&& ray[i].end[X] == ray[i - 1].end[X])
			return (ray[i - 1].wall_or);
	}*/
	//if (scr[pos - WIDTH] == 0xFFFFFF)/* && scr[pos - WIDTH * 5] == 0xFFFFFF
	//	&& scr[pos - WIDTH - 5] == 0xFFFFFF*/
	//	return ('S');
	//else if (scr[pos + WIDTH] == 0xFFFFFF)/* && scr[pos + WIDTH * 5] == 0xFFFFFF
	//	&& scr[pos + WIDTH - 5] == 0xFFFFFF*/
	/*	return ('N');
	else if (scr[pos + 1] == 0xFFFFFF)
		return ('W');
	else if (scr[pos - 1] == 0xFFFFFF)
		return ('E');
	return (0);
}*/

/*static void	feed_ray(t_data *info, t_point *ends, int i)
{
	int	a;
	int	b;

	a = abs(ends[0].x - ends[1].x);
	b = abs(ends[0].y - ends[1].y);
	(info->ray)[i].len = sqrt((a * a + b * b));*/
	//(info->ray)[i].wall_or = get_wall_or(info->map2d, ends[1]);
	/*(info->ray)[i].wall_or = get_wall_or(info->mlx->img.img_adr, ends[1]);
		//, info->ray, i);
	(info->ray)[i].map_p = rayend_mappos(ends[1], (info->ray)[i].wall_or,
		info->map.cell_w, info->map.size);
	(info->ray)[i].end[X] = ends[1].x;
	(info->ray)[i].end[Y] = ends[1].y;
}*/

static void	horiz_maplines(int *scr, t_data *info, float ang)
{
	float	rpos[2];
	float	rd[2];
	float	atan;
	int		dof;
	int		mpos[2];
	int		mp;
	t_point	pts[2];

	pts[0].x = info->player.x;
	pts[0].y = info->player.y;
	pts[1].x = info->player.x;
	pts[1].y = info->player.y;
	atan = -1 / tan(deg_to_rad(ang));
	printf("atan: %f\n", atan);
	dof = -1;
	if (ang == 0 || ang == 180)
	{
		rpos[X] = info->player.x;
		rpos[Y] = info->player.y;
		dof = info->map.size[Y];
	}
	else if (ang < 180)
	{
		rpos[Y] = (((int)info->player.y / 48) * 48) - 0.0001;
		rpos[X] = (info->player.y - rpos[Y] * atan + info->player.x);
		rd[Y] = -48;
		rd[X] = -rd[Y] * atan;
	}
	else
	{
		rpos[Y] = (((int)info->player.y / 48) * 48) + 48;
		rpos[X] = (info->player.y - rpos[Y] * atan + info->player.x);
		rd[Y] = 48;
		rd[X] = -rd[Y] * atan;
	}
	while (++dof < info->map.size[Y])
	{
		mpos[X] = (int)(rpos[X]) / 48;
		mpos[Y] = (int)(rpos[Y] - (HEIGHT - info->map.size[Y])) / 48;
		mp = mpos[Y] * info->map.size[Y] + mpos[X];
		if (mp < info->map.size[X] * info->map.size[Y] && (info->map.arr)[mp] == 1) //we hit a wall
			dof = info->map.size[Y]; //finish the loop
		else
		{
			rpos[X] += rd[X];
			rpos[Y] += rd[Y];
		}	
	}
	pts[1].x = rpos[X];
	pts[1].y = rpos[Y];
	//printf("pts[0].x: %i, pts[0].y: %i, pts[1].x: %i, pts[1].y: %i\n", pts[0].x, pts[0].y, pts[1].x, pts[1].y);
	draw_line(scr, pts, 0xFFFF00, 1);
}

void	fill_ray(int *scr, t_data *info, float ang, int i)
{
	(void)i;
	horiz_maplines(scr, info, ang);
	//vert_maplines(info, ang);
	//feed_ray(info, pts, i);
	//draw_wall(info, scr, ang, i);
}
