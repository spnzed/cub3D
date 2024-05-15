/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:46:42 by aaespino          #+#    #+#             */
/*   Updated: 2024/05/15 12:59:36 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_extension(char *file)
{
	int	i;

	i = ft_strlen(file);
	if (i > 2 && file[i - 4] == '.' && file[i - 3] == 'c'
		&& file[i - 2] == 'u' && file[i - 1] == 'b')
		return (0);
	else
		return (1);
}

// static void	upd_vars(t_data *info)
// {

// 	info->ray.plane[X] = 0;
// 	info->ray.plane[Y] = 0.66;
// 	info->ray.pos[X] = info->player.x;
// 	info->ray.pos[Y] = info->player.y;
// 	info->ray.dir[X] = info->player.p_dir_cor[X];
// 	info->ray.dir[Y] = info->player.p_dir_cor[Y];

// 	info->player.x = info->map.spawn[Y] + 0.5;
// 	info->player.y = info->map.spawn[X] + 0.5;
// 	info->player.p_plane_x = fabs(info->player.p_dir_cor[Y]) * 0.66;
// 	info->player.p_plane_y = fabs(info->player.p_dir_cor[X]) * 0.66;
// 	if (info->player.p_dir_cor[X] == -1 || info->map.player_dir[Y] == 1)
// 	{
// 		info->player.plane[X] *= -1;
// 		info->player.plane[Y] *= -1;
// 	}
// }

int	check_args(int argc, char **argv, t_data *info)
{
	int	err;

	err = 0;
	if (argc < 2)
		err = ft_err("Error: Not Enough Arguments\n");
	else if (argc > 2)
		err = ft_err("Error: Too Many Arguments\n");
	else if (ft_strlen(argv[1]) <= 4)
		err = ft_err("Error: Invalid Path\n");
	else if (check_extension(argv[1]))
		err = ft_err("Error: Incorrect File Extension\n");
	if (err)
		exit(1);
	else
		handle_map(argv[1], info);
	// upd_vars(info);
	return (0);
}
