/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_temp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:00:01 by erosas-c          #+#    #+#             */
/*   Updated: 2024/05/10 19:02:32 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_bigpl(t_data *info)
{
	int	t = 64;
//	t = t / 2; //MacBook erosas
	//pl->ang = info->player.dir; //PI / 2;//2.0943951024; //120 graus
	info->player.len = t / 2;
	info->player.w = t / 8;
	info->player.h = t / 8;
	info->player.x = WIDTH / 2 + (t * 3 / 2) - (info->player.w / 2); //6 NOMBRE COLUMNES MAP, 64 (t) = mida passadissos d'una unitat (utilitzada a fill_map)
	info->player.y = HEIGHT / 2 + t - (info->player.h / 2);
	//init_offsets(bigpl, 2);
}

void	init_temp(t_data *info)
{
/*	t_sq	*minipl;
	int		t = 32;
//	t = t / 2; // MacBook erosas
	minipl = (t_sq *)ft_calloc(sizeof(t_sq), 1);
	if (!minipl)
	{
		ft_err("Error: Malloc\n");
		exit (1);
	}
	minipl->ang = M_PI / 2;//2.0943951024; //120 graus
	minipl->w = t / 8;
	minipl->h = t / 8;
	minipl->x = (4 * t) + (t / 2) - (minipl->w / 2); // t 32 = mida passadissos d'una unitat (utilitzada a fill_map)
	minipl->y = (3 * t) + (t / 2) - (minipl->h / 2);
	//init_offsets(minipl, 1);
	info->minipl = minipl;*/
	init_bigpl(info);
}
