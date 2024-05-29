/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:09:09 by erosas-c          #+#    #+#             */
/*   Updated: 2024/05/27 21:04:15 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	rayend_mappos(t_point hit, char wll_or, int cell_w, int *m_sz)
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
}



static char check_orientation(int *scr, t_point r_end, t_ray *ray, int i)
{
	int	or;
	(void)scr;
	(void)r_end;

	or = 0;
	if (ray[i].ang == 0)
		or = 'W';
	else if (ray[i].ang == 90)
		or = 'S';
	else if (ray[i].ang == 180)
		or = 'E';
	else if (ray[i].ang == 270)
		or = 'N';
	/*else
		or = get_wall_or(scr, r_end, ray, i);*/
	return (or);
}

static void	feed_ray(t_data *info, t_point *ends, int i, float ang)
{
	int	a;
	int	b;

	a = abs(ends[0].x - ends[1].x);
	b = abs(ends[0].y - ends[1].y);
	(info->ray)[i].len = sqrt((a * a + b * b));
//	printf("ang: %f\n", ang);
	(info->ray)[i].ang = ang;
//	printf("(info->ray)[%i].ang: %f\n", i, (info->ray)[i].ang);
	//(info->ray)[i].wall_or = get_wall_or(info->map2d, ends[1]);
	(info->ray)[i].wall_or = check_orientation(info->mlx->img.img_adr, ends[1], info->ray, i);
	(info->ray)[i].map_p = rayend_mappos(ends[1], (info->ray)[i].wall_or,
		info->map.cell_w, info->map.size);
	(info->ray)[i].end[X] = ends[1].x;
	(info->ray)[i].end[Y] = ends[1].y;
	//(info->ray)[i].end[X] = ends[1].x;
	//(info->ray)[i].end[Y] = ends[1].y;
}

void	fill_ray(int *scr, t_data *info, float ang, int i)
{
	t_point	*pts;

	pts = ft_calloc(sizeof(pts), 2);
	if (!pts)
	{
		ft_err("Error: Malloc\n");
		exit (1);
	}
	pts[0].x = info->player.x;
	pts[0].y = info->player.y;
	pts[1].x = 0;
	pts[1].y = 0;
	ray_end(scr, pts, ang);
	draw_line(scr, pts, 0xFFFF00, 1);
	feed_ray(info, pts, i, ang);
//	draw_wall(info, scr, ang, i);
}
