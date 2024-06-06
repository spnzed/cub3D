/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:31:55 by aaespino          #+#    #+#             */
/*   Updated: 2024/05/27 18:09:53 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	wall_found(float x, float y, t_map *m)
{
	int	mp;
	int	mx;
	int	my;

	mx = (int)(x) / m->cell_w;
	my = (int)(y) / m->cell_w;
	mp = my * m->size[X] + mx;
	if ((m->arr)[mp] == 1)
		return (1);
	return (0);
}

// static int	wall_found(int *scr, float x, float y, t_map *m)
// {
// 	int	pos;
// 	int	pos_x;
// 	int	pos_y;
// 	int	mp;

// 	pos_x = (int)(x);
// 	pos_y = (int)(y);
// 	pos = pos_y * WIDTH + pos_x;
// 	mp = pos_x / m->cell_w * m->size[X] + pos_y / m->cell_w;;
// 	if (mp < m->size[X] * m->size[Y] && (m->arr)[mp] == 1)
// 		return (1);
// 	else if ((pos_x >= 0 && pos_y >= 0) && (pos_x < WIDTH && pos_y < HEIGHT)
// 		&& is_corner(scr, pos) == 1)
// 		return (1);
// 	return (0);
// }

void	move_front(t_data *info)
{
	/*if (!wall_found(info->map2d, info->player.x + info->player.dx * 2,
		info->player.y + info->player.dy * 2))*/
	if (!wall_found(info->player.x + info->player.dx * 2,
		info->player.y + info->player.dy * 2, &(info->map)))
	{
		info->player.x += info->player.dx;
		info->player.y += info->player.dy;
		//printf("px: %f, py: %f, dx: %f, dy: %f\n", info->player.x, info->player.y, info->player.dx, info->player.dy);
		//info->minipl.x += info->minipl.dx;
		//info->minipl.y += info->minipl.dy;
	}
}

void	move_back(t_data *info)
{
	/*if (!wall_found(info->map2d, info->player.x - info->player.dx * 2,
		info->player.y - info->player.dy * 2))*/
	if (!wall_found(info->player.x - info->player.dx * 2,
		info->player.y - info->player.dy * 2, &(info->map)))
	{
		info->player.x -= info->player.dx;
		info->player.y -= info->player.dy;
		//info->minipl.x -= info->minipl.dx;
		//info->minipl.y -= info->minipl.dy;
	}
}

void	move_right(t_data *info)
{
	float	new_dir;
	float	new_dx;
	float	new_dy;

	new_dir = angle_correction(90 - info->player.dir);
	new_dx = cos(deg_to_rad(new_dir));
	new_dy = sin(deg_to_rad(new_dir));
	/*if (!wall_found(info->map2d, info->player.x + new_dx * 3 * 2,
		info->player.y + new_dy * 3 * 2))*/
	if (!wall_found(info->player.x + new_dx * 2,
		info->player.y + new_dy * 2, &(info->map)))
	{
		info->player.x += new_dx;
		info->player.y += new_dy;
		//info->minipl.x += new_dx;
		//info->minipl.y += new_dy;
	}
}

	//CHECKTHIS
	/*int	new_dir; 
	int	new_dir_cor[2];
	new_dir = angle_correction(90 - info->player.dir);
	new_dir_cor[X] = cos(deg_to_rad(new_dir));
	new_dir_cor[Y] = sin(deg_to_rad(new_dir));*/
void	move_left(t_data *info)
{
	float	new_dir;
	float	new_dx;
	float	new_dy;

	new_dir = angle_correction(90 - info->player.dir);
	new_dx = cos(deg_to_rad(new_dir));
	new_dy = sin(deg_to_rad(new_dir));
	/*if (!wall_found(info->map2d, info->player.x - new_dx * 3 * 2,
		info->player.y - new_dy * 3 * 2))*/
	if (!wall_found(info->player.x - new_dx * 2,
		info->player.y - new_dy * 2, &(info->map)))
	{
		info->player.x -= new_dx;
		info->player.y -= new_dy;
	//	info->minipl.x -= new_dx;
	//	info->minipl.y -= new_dy;
	}
}

//CHECKTHIS
/*int	new_dir;
int	new_dir_cor[2];
new_dir = angle_correction(90 - info->player.dir);
new_dir_cor[X] = cos(deg_to_rad(new_dir));
new_dir_cor[Y] = sin(deg_to_rad(new_dir));
if (check_collision(info,
		info->player.x - new_dir_cor[X] * SPEED,
		info->player.y - new_dir_cor[Y] * SPEED))
{
	info->player.x -= new_dir_cor[X] * SPEED;
	info->player.y -= new_dir_cor[Y] * SPEED;
}*/