/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:38:09 by erosas-c          #+#    #+#             */
/*   Updated: 2024/04/23 17:40:54 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		init_window(t_data *info)
{
	info->mlx.mlx = mlx_init();
	info->mlx.win = mlx_new_window(info->mlx.mlx, WIDTH, HEIGHT, "cub3D");
	put_images(info);
	//put_position(info);
	return (0);
}