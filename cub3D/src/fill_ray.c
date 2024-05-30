/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:09:09 by erosas-c          #+#    #+#             */
/*   Updated: 2024/05/30 21:00:34 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	get_wall_or(t_data *info, t_ray *ray)
{
	(void)info;
	if (ray->ang > 0 && ray->ang < 90 && ray->end[X] % 48 == 0)
		return ('W');
	else if (ray->ang > 0 && ray->ang < 90 && (HEIGHT - ray->end[Y]) % 48 == 0)
		return ('S');
	else if (ray->ang > 90 && ray->ang < 180 && ray->end[X] % 48 == 0)
		return ('E');
	else if (ray->ang > 90 && ray->ang < 180 && (HEIGHT - ray->end[Y]) % 48 == 0)
		return ('S');
	else if (ray->ang > 180 && ray->ang < 270 && (ray->end[X] % 48) == 0)
		return ('E');
	else if (ray->ang > 180 && ray->ang < 270 && (HEIGHT - ray->end[Y] % 48) == 0)
		return ('N');
	else if (ray->ang > 270 && ray->end[X] % 48 == 0)
		return ('W');
	else if (ray->ang > 270 && (HEIGHT - ray->end[Y] % 48) == 0)
		return ('N');
	/*else
		return(non_exact(info, ray));*/
	return (0);
}

static int	rayend_mappos(t_point hit, char wll_or, int cell_w, int *m_sz)
{
	int	res;
	int	y_off;
	//int	x_off;

	res = 0;
	//x_off = WIDTH / 2 - m_sz[X] * cell_w / 2;
	y_off = HEIGHT - (m_sz[Y] * cell_w);
	//printf("y_off: %i, m_sz[Y]: %i, cell_w: %i\n", y_off, m_sz[Y], cell_w);
	if (wll_or == 'E' || wll_or == 'W')
		res = (hit.y + y_off) / cell_w;
	if (wll_or == 'N' || wll_or == 'S')
		res = hit.x / cell_w;
	//	res = (hit.x + x_off) / cell_w;
	// if (wll_or == 'S')
	// {
	// 	printf("wall_or: %c\n", wll_or);
	// 	printf("wall_or: %i\n", wll_or);
	// 	printf("hit_x: %i, hit_y: %i, y_off: %i, m_sz[Y]: %i, cell_w: %i\n", hit.x, hit.y, y_off, m_sz[Y], cell_w);
	// 	printf("res: %i\n", res);
	// }
	return (res);
}

static char	check_orientation(t_data *info, t_ray *ray)
{
	char	or;

	or = 0;
	if (ray->ang == 0)
		or = 'W';
	else if (ray->ang == 90)
		or = 'S';
	else if (ray->ang == 180)
		or = 'E';
	else if (ray->ang == 270)
		or = 'N';
	else
		or = get_wall_or(info, ray);
	return (or);
}

static void	feed_ray(t_data *info, t_point *ends, int i, float ang)
{
	int	a;
	int	b;

	a = abs(ends[0].x - ends[1].x);
	b = abs(ends[0].y - ends[1].y);
//	printf("ends[1].x: %i, ends[1].y: %i\n", ends[1].x, ends[1].y);
	(info->ray)[i].len = sqrt((a * a + b * b));
	(info->ray)[i].ang = ang;
	(info->ray)[i].end[X] = ends[1].x;
	(info->ray)[i].end[Y] = ends[1].y;
	//(info->ray)[i].wall_or = get_wall_or(info->map2d, ends[1]);
	(info->ray)[i].wall_or = check_orientation(info, &(info->ray)[i]);
	(info->ray)[i].map_p = rayend_mappos(ends[1], (info->ray)[i].wall_or,
	 	info->map.cell_w, info->map.size);
//	printf("(info->ray)[i].map_p: %i\n", (info->ray)[i].map_p);
	
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
	draw_wall(info, scr, ang, i);
}
