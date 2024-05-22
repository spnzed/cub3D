/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:09:09 by erosas-c          #+#    #+#             */
/*   Updated: 2024/05/21 20:59:56 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*static char	get_wall_or(int *scr, t_point r_end)
{
	int	pos;

	pos = r_end.y * WIDTH + r_end.x;
	if (scr[pos - WIDTH] == 0xFFFFFF && scr[pos - WIDTH + 5] == 0xFFFFFF
		&& scr[pos - WIDTH - 5] == 0xFFFFFF)
		return ('S');
	else if (scr[pos + WIDTH] == 0xFFFFFF && scr[pos + WIDTH + 5] == 0xFFFFFF
		&& scr[pos + WIDTH - 5] == 0xFFFFFF)
		return ('N');
	else if (scr[pos + 1] == 0xFFFFFF)
		return ('W');
	else if (scr[pos - 1] == 0xFFFFFF)
		return ('E');
	return (0);
}

static void	feed_ray(t_data *info, t_point *ends, int i, int ang)
{
	int	a;
	int	b;

	a = abs(ends[0].x - ends[1].x);
	b = abs(ends[0].y - ends[1].y);
	(info->ray)[i].len = sqrt((a * a + b * b));
	if (ang == info->player.dir)
		(info->ray)[i].wall_or = get_wall_or(info->mlx->img.img_adr, ends[1]);
	else
		(info->ray)[i].wall_or = 'r';
//	printf("wall orient: %c, ray->len: %f\n", info->ray->wall_or, info->ray->len);
}*/

void	other_angles(int *scr, t_point *pts, int ang)
{
	int		i;

	i = 0;
	pts[1].x = pts[0].x + cos(deg_to_rad(ang)) * i;
	pts[1].y = pts[0].y - sin(deg_to_rad(ang)) * i;
	while (scr[WIDTH * pts[1].y + pts[1].x] != 0xFFFFFF
		&& WIDTH * pts[1].y + pts[1].x >= 0
		&& WIDTH * pts[1].y + pts[1].x < WIDTH * HEIGHT)
	{
		i++;
		pts[1].x = pts[0].x + cos(deg_to_rad(ang)) * i;
		pts[1].y = pts[0].y - sin(deg_to_rad(ang)) * i;
	}
	if (scr[WIDTH * pts[1].y + pts[1].x] == 0xFFFFFF)
	{
		i--;
		pts[1].x = pts[0].x + cos(deg_to_rad(ang)) * i;
		pts[1].y = pts[0].y - sin(deg_to_rad(ang)) * i;
	}
}

void	fill_ray(int *scr, t_data *info, int ang, int i)
{
	t_point	*pts;

	(void)i;
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
	draw_line(scr, pts, 0xFFFF00);
}
