/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_temp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 19:00:01 by erosas-c          #+#    #+#             */
/*   Updated: 2024/05/08 19:04:58 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_bigpl(t_data *info)
{
	t_sq	*bigpl;
	int	t = 64;
//	t = t / 2; //MacBook erosas
	bigpl = ft_calloc(sizeof(t_sq), 1);
	if (!bigpl)
	{
		ft_err("Error: Malloc\n");
		exit (1);
	}
	bigpl->ang = 2.0943951024; //120 graus
	bigpl->len = t / 2;
	bigpl->w = t / 8;
	bigpl->h = t / 8;
	bigpl->x = WIDTH / 2 + (t * 3 / 2) - (bigpl->w / 2); //6 NOMBRE COLUMNES MAP, 64 (t) = mida passadissos d'una unitat (utilitzada a fill_map)
	bigpl->y = HEIGHT / 2 + t - (bigpl->h / 2);
	info->bigpl = bigpl;
}

void	init_temp(t_data *info)
{
	t_sq	*minipl;
	int		t = 32;
//	t = t / 2; // MacBook erosas
	minipl = (t_sq *)ft_calloc(sizeof(t_sq), 1);
	if (!minipl)
	{
		ft_err("Error: Malloc\n");
		exit (1);
	}
	minipl->w = t / 8;
	minipl->h = t / 8;
	minipl->x = (4 * t) + (t / 2) - (minipl->w / 2); // t 32 = mida passadissos d'una unitat (utilitzada a fill_map)
	minipl->y = (3 * t) + (t / 2) - (minipl->h / 2);
	info->minipl = minipl;
	init_bigpl(info);
}