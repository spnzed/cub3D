/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 19:34:09 by erosas-c          #+#    #+#             */
/*   Updated: 2024/05/17 19:35:03 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void deg0(int *scr, t_point *pts)
{
	pts[1].x = pts[0].x + 1;
	pts[1].y = pts[0].y;
	while (scr[WIDTH * pts[1].y + pts[1].x] != 0xFFFFFF
		&& WIDTH * pts[1].y + pts[1].x >= 0
		&& WIDTH * pts[1].y + pts[1].x < WIDTH * HEIGHT)
			pts[1].x++;
	if (scr[WIDTH * pts[1].y + pts[1].x] != 0xFFFFFF)
		pts[1].x--;
}
static void deg180(int *scr, t_point *pts)
{
	pts[1].x = pts[0].x - 1;
	pts[1].y = pts[0].y;
	while (scr[WIDTH * pts[1].y + pts[1].x] != 0xFFFFFF
		&& WIDTH * pts[1].y + pts[1].x >= 0
		&& WIDTH * pts[1].y + pts[1].x < WIDTH * HEIGHT)
			pts[1].x--;
	if (scr[WIDTH * pts[1].y + pts[1].x] != 0xFFFFFF)
		pts[1].x++;
}

static void deg90(int *scr, t_point *pts)
{
	pts[1].x = pts[0].x;
	pts[1].y = pts[0].y - 1;
	while (scr[WIDTH * pts[1].y + pts[1].x] != 0xFFFFFF
		&& WIDTH * pts[1].y + pts[1].x >= 0
		&& WIDTH * pts[1].y + pts[1].x < WIDTH * HEIGHT)
			pts[1].y--;
	if (scr[WIDTH * pts[1].y + pts[1].x] != 0xFFFFFF)
		pts[1].y++;
}

static void deg270(int *scr, t_point *pts)
{
	pts[1].x = pts[0].x;
	pts[1].y = pts[0].y + 1;
	while (scr[WIDTH * pts[1].y + pts[1].x] != 0xFFFFFF
		&& WIDTH * pts[1].y + pts[1].x >= 0
		&& WIDTH * pts[1].y + pts[1].x < WIDTH * HEIGHT)
			pts[1].y++;
	if (scr[WIDTH * pts[1].y + pts[1].x] != 0xFFFFFF)
		pts[1].y--;
}

void    ray_end(int *scr, t_point *pts, t_player *pl)
{
	if (pl->dir == 90)
		deg90(scr, pts);
    else if (pl->dir == 270)
		deg270(scr, pts);
	else if (pl->dir == 0)
		deg0(scr, pts);
    else if (pl->dir == 180)
		deg180(scr, pts);
	else
		other_angles(scr, pts, pl);
}

/*void cross_map_rows(t_data *info, int *row)
{
    int     n;
    float   aTan;

    n = -1;
    while (++n < 1)
    {
        row = 0;
        aTan = -1 / tan(deg_to_rad(info->ray->dir));
        if (info->ray->dir > 0 && info->ray->dir < 180)
        {
            info->ray->p[Y] = (((int)info->player.y >> 5) << 5) - 0.0001;
            info->ray->p[X] = (info->player.y - info->ray->p[Y]) * aTan * info->player.x;
            info->ray->off[Y] = -32;
            info->ray->off[X] = -info->ray->off[Y] * aTan;
        }
        else if (info->ray->dir > 180 && info->ray->dir < 360)
        {
            info->ray->p[Y] = (((int)info->player.y >> 5) << 5) + 32;
            info->ray->p[X] = (info->player.y - info->ray->p[Y]) * aTan * info->player.x;
            info->ray->off[Y] = 32;
            info->ray->off[X] = -info->ray->off[Y] * aTan;
        }
        else if (info->ray->dir == 0 || info->ray->dir == 180)
            row == info->map.size[Y];
    }
}

void init_rays(t_data *info)
{
    info->ray = ft_calloc(sizeof(t_ray), 1); // 1 = nombre de rajos que voldrem fer
    if (!info->ray)
    {
		ft_err("Error: Malloc\n");
		exit (1);
	}
    info->ray->p[X] = info->player.x;
    info->ray->p[Y] = info->player.y;
    info->ray->off[X] = 0;
    info->ray->off[Y] = 0;
    info->ray->num = 0;
    info->ray->dir = info->player.dir;
}

void draw_rays(t_data *info)
{
    int row;
    int *mp[2];
    int mpos;

    row = 0;
    mpos = 0;
    init_rays(info);
    cross_map_rows(info, &row);
    while (row < info->map.size[Y])
    {
        mp[X] = (int)info->ray->p[X] >> 5;
        mp[Y] = (int)info->ray->p[Y] >> 5;
        mpos = mp[Y] * info->map.size[X] + mp[X];
        if (mpos < info->map.size[X] * info->map.size[Y] && info->map.arr[mpos] == 1)
            row == info->map.size[Y]; 
    }
}*/
