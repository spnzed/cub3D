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

void	init_temp(t_data *info)
{
	t_sq	*minipl;
	minipl = ft_calloc(sizeof(t_sq), 1);
	if (!minipl)
	{
		ft_err("Error: Malloc\n");
		exit (1);
	}
	minipl->w = 4;
	minipl->h = 4;
	minipl->x = (4 * 32) + (32 / 2) - (minipl->w / 2); //32 = mida passadissos d'una unitat (utilitzada a fill_map)
	minipl->y = (3 * 32) + (32 / 2) - (minipl->h / 2);
	info->minipl = minipl;
}