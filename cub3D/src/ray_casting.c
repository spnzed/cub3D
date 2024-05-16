/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:58:37 by aaronespino       #+#    #+#             */
/*   Updated: 2024/05/16 17:49:51 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_ray(t_data *info)
{
	info->ray.pos[X] = info->player.x;
	info->ray.pos[Y] = info->player.y;
	info->ray.dir[X] = info->player.dir_cor[X];
	info->ray.dir[Y] = info->player.dir_cor[Y];
}

static void	horiz_ray(int *scr, t_point *pts, t_player *pl)
{
	if (pl->dir == 0)
	{
		pts[1].x = pts[0].x + 1;
		pts[1].y = pts[0].y;
		while (scr[WIDTH * pts[1].y + pts[1].x] != 0xFFFFFF
			&& WIDTH * pts[1].y + pts[1].y >= 0
			&& WIDTH * pts[1].y + pts[1].y < WIDTH * HEIGHT)
				pts[1].x++;
		if (scr[WIDTH * pts[1].y + pts[1].y] != 0xFFFFFF)
			pts[1].x--;
	}
	else if (pl->dir == 180)
	{
		pts[1].x = pts[0].x - 1;
		pts[1].y = pts[0].y;
		while (scr[WIDTH * pts[1].y + pts[1].x] != 0xFFFFFF
			&& WIDTH * pts[1].y + pts[1].y >= 0
			&& WIDTH * pts[1].y + pts[1].y < WIDTH * HEIGHT)
				pts[1].x--;
		if (scr[WIDTH * pts[1].y + pts[1].y] != 0xFFFFFF)
			pts[1].x++;
	}

}

static void	vert_ray(int *scr, t_point *pts, t_player *pl)
{
	if (pl->dir == 90)
	{
		pts[1].x = pts[0].x;
		pts[1].y = pts[0].y - 1;
		while (scr[WIDTH * pts[1].y + pts[1].x] != 0xFFFFFF
			&& WIDTH * pts[1].y + pts[1].y >= 0
			&& WIDTH * pts[1].y + pts[1].y < WIDTH * HEIGHT)
				pts[1].y--;
		if (scr[WIDTH * pts[1].y + pts[1].y] != 0xFFFFFF)
			pts[1].y++;
	}
	else if (pl->dir == 270)
	{
		pts[1].x = pts[0].x;
		pts[1].y = pts[0].y + 1;
		while (scr[WIDTH * pts[1].y + pts[1].x] != 0xFFFFFF
			&& WIDTH * pts[1].y + pts[1].y >= 0
			&& WIDTH * pts[1].y + pts[1].y < WIDTH * HEIGHT)
				pts[1].y++;
		if (scr[WIDTH * pts[1].y + pts[1].y] != 0xFFFFFF)
			pts[1].y--;
	}

}

static void	other_angles(int *scr, t_point *pts, t_player *pl)
{
	int	i;

	i = 0;
	pts[1].x = pts[0].x + cos(deg_to_rad(pl->dir)) * i;
	pts[1].y = pts[0].y - sin(deg_to_rad(pl->dir)) * i;
	while (scr[WIDTH * pts[1].y + pts[1].x] != 0xFFFFFF
		&& WIDTH * pts[1].y + pts[1].y >= 0
		&& WIDTH * pts[1].y + pts[1].y < WIDTH * HEIGHT)
	{
		i++;
		pts[1].x = pts[0].x + cos(deg_to_rad(pl->dir)) * i;
		pts[1].y = pts[0].y - sin(deg_to_rad(pl->dir)) * i;
	}
	if (scr[WIDTH * pts[1].y + pts[1].y] != 0xFFFFFF)
	{
		i--;
		pts[1].x = pts[0].x + cos(deg_to_rad(pl->dir)) * i;
		pts[1].y = pts[0].y - sin(deg_to_rad(pl->dir)) * i;
	}
}

static void	check_lines(int *scr, t_player *pl)
{
	t_point	*pts;

	pts = ft_calloc(sizeof(pts), 2);
	if (!pts)
	{
		ft_err("Error: Malloc\n");
		exit (1);
	}
	pts[0].x = pl->x;
	pts[0].y = pl->y;
	pts[1].x = 0;
	pts[1].y = 0;
	if (pl->dir == 90 || pl->dir == 270)
		vert_ray(scr, pts, pl);
	else if (pl->dir == 0 || pl->dir == 180)
		horiz_ray(scr, pts, pl);
	else
		other_angles(scr, pts, pl);
}

void	ray_casting(t_data *info)
{
	int		 i;

	i = 0;
	info->ray.plane[X] = 0;
	info->ray.plane[Y] = 0.66;
	while (i < WIDTH)
	{
		init_ray(info);
		check_lines(info->mlx->img.img_adr, &info->player);
		draw_walls(info, i);
	}
}
