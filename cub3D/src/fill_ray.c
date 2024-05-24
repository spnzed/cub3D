/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:09:09 by erosas-c          #+#    #+#             */
/*   Updated: 2024/05/23 19:53:26 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	rayend_mappos(t_point hit, char wll_or, int cell_w, int *m_sz)
{
	int	res;
	int	y_off;
	int	x_off;

	x_off = WIDTH / 2 - m_sz[X] * cell_w / 2;
	y_off = HEIGHT / 2 - m_sz[Y] * cell_w / 2;
	if (wll_or == 'E' || wll_or == 'W')
		res = (hit.y + y_off) / cell_w;
	else
		res = (hit.x + x_off) / cell_w;
	return (res);
}

static char	get_wall_or(int *scr, t_point r_end)
{
	int	pos;

	pos = r_end.y * WIDTH + r_end.x;
	if (scr[pos - WIDTH] == 0xFFFFFF)/* && scr[pos - WIDTH * 5] == 0xFFFFFF
		&& scr[pos - WIDTH - 5] == 0xFFFFFF*/
		return ('S');
	else if (scr[pos + WIDTH] == 0xFFFFFF)/* && scr[pos + WIDTH * 5] == 0xFFFFFF
		&& scr[pos + WIDTH - 5] == 0xFFFFFF*/
		return ('N');
	else if (scr[pos + 1] == 0xFFFFFF)
		return ('W');
	else if (scr[pos - 1] == 0xFFFFFF)
		return ('E');
	return (0);
}

static void	feed_ray(t_data *info, t_point *ends, int i)
{
	int	a;
	int	b;

	a = abs(ends[0].x - ends[1].x);
	b = abs(ends[0].y - ends[1].y);
	(info->ray)[i].len = sqrt((a * a + b * b));
	(info->ray)[i].wall_or = get_wall_or(info->mlx->img.img_adr, ends[1]);
	(info->ray)[i].map_p = rayend_mappos(ends[1], (info->ray)[i].wall_or,
		info->map.cell_w, info->map.size);
}

void	fill_ray(int *scr, t_data *info, float ang, int i)
{
	t_point	*pts;

	//(void)i;
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
//	printf("i: %i, pts[1].pos: %i\n", i, pts[1].y * WIDTH + pts[1].x);
	draw_line(scr, pts, 0xFFFF00, 1);
	feed_ray(info, pts, i);
	//draw_wall(info, scr, ang, i);
}
