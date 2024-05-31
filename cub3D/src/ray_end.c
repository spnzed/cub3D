/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_end.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 19:34:09 by erosas-c          #+#    #+#             */
/*   Updated: 2024/05/31 20:18:07 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// static void	deg0(int *scr, t_point *pts)
// {
// 	pts[1].x = pts[0].x + 1;
// 	pts[1].y = pts[0].y;
// 	while (scr[WIDTH * pts[1].y + pts[1].x] != 0xFFFFFF
// 		&& pts[1].y >= 0 && pts[1].x >= 0
// 		&& pts[1].x < WIDTH && pts[1].y < HEIGHT
// 		&& scr[WIDTH * pts[1].y + pts[1].x + 1] != 0xFFFFFF)
// 		pts[1].x++;
// 	if (scr[WIDTH * pts[1].y + pts[1].x] == 0xFFFFFF)
// 		pts[1].x -= 1;
// 	//printf("p1.x: %i, pt1.y: %i\n", pts[1].x, pts[1].y);
// }

// static void	deg180(int *scr, t_point *pts)
// {
// 	pts[1].x = pts[0].x - 1;
// 	pts[1].y = pts[0].y;
// 	while (scr[WIDTH * pts[1].y + pts[1].x] != 0xFFFFFF
// 		&& pts[1].y >= 0 && pts[1].x >= 0
// 		&& pts[1].x < WIDTH && pts[1].y < HEIGHT
// 		&& scr[WIDTH * pts[1].y + pts[1].x - 1] != 0xFFFFFF)
// 		pts[1].x--;
// 	if (scr[WIDTH * pts[1].y + pts[1].x] == 0xFFFFFF)
// 		pts[1].x += 1;
// }

// static void	deg90(int *scr, t_point *pts)
// {
// 	pts[1].x = pts[0].x;
// 	pts[1].y = pts[0].y - 1;
// 	while (scr[WIDTH * pts[1].y + pts[1].x] != 0xFFFFFF
// 		&& pts[1].y >= 0 && pts[1].x >= 0
// 		&& pts[1].x < WIDTH && pts[1].y < HEIGHT
// 		&& scr[WIDTH * pts[1].y + pts[1].x - WIDTH] != 0xFFFFFF)
// 		pts[1].y--;
// 	if (scr[WIDTH * pts[1].y + pts[1].x] == 0xFFFFFF)
// 		pts[1].y += 1;
// }

// static void	deg270(int *scr, t_point *pts)
// {
// 	pts[1].x = pts[0].x;
// 	pts[1].y = pts[0].y + 1;
// 	while (scr[WIDTH * pts[1].y + pts[1].x] != 0xFFFFFF
// 		&& pts[1].y >= 0 && pts[1].x >= 0
// 		&& pts[1].x < WIDTH && pts[1].y < HEIGHT
// 		&& scr[WIDTH * pts[1].y + pts[1].x + WIDTH] != 0xFFFFFF)
// 		pts[1].y++;
// 	if (scr[WIDTH * pts[1].y + pts[1].x] == 0xFFFFFF)
// 		pts[1].y -= 1;
// }

// void	ray_end(int *scr, t_point *pts, float ang)
// {
// 	if (ang == 90)
// 		deg90(scr, pts);
// 	else if (ang == 270)
// 		deg270(scr, pts);
// 	else if (ang == 0)
// 		deg0(scr, pts);
// 	else if (ang == 180)
// 		deg180(scr, pts);
// 	else
// 		other_angles(scr, pts, ang);
// }
