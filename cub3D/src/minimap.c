/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_2d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:03:48 by erosas-c          #+#    #+#             */
/*   Updated: 2024/05/11 21:29:27 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	ft_c(char c, int floor, int *pos)
{
	if (c == '1')
		*pos = 0x743636;
	else
		*pos = floor;
}

static void	fill_map(int *scr, t_data *info, int p, int i)
{
	int	j;
	int	k;
	int	po;

	j = -1;
	k = 0;
	po = p;
	while (++j < info->map.size[1])
	{
		while (i < SCALE / 8 * (j + 1))
		{
			while (info->map.grid[j][k])
			{
				while (p < po + (SCALE / 8 * (k + 1) + (WIDTH * i)))
				{
					ft_c(info->map.grid[j][k], info->parameters.floor, &scr[p]);
					p++;
				}
				k++;
			}
			i++;
			p = po + WIDTH * i;
			k = 0;
		}
	}
}

static void	fill_player(int *scr, t_player *pl, int p, int w)
{
	int	c;
	int	po;
	int	h;
	int	i;

	i = 1;
	po = p;
	h = -1;
	c = 0xffff00;
	while (++h < pl->h)
	{
		while (++w < pl->w)
			scr[p++] = c;
		p = po + WIDTH * i;
		w = -1;
		i++;
	}
}

void	mini_map(t_data *info)
{
	int			cell_w;
	int			p;

	cell_w = 8;
	p = WIDTH * cell_w + cell_w;
	info->minipl.h = 4;
	info->minipl.w = 4;
	info->minipl.x = cell_w + info->map.spawn[0] * cell_w
		+ cell_w / 2 - info->minipl.w / 2;
	info->minipl.y = cell_w + info->map.spawn[1] * cell_w
		+ cell_w / 2 - info->minipl.h / 2;
	fill_map(info->mlx->img.img_adr, info, p, 0);
	fill_player(info->mlx->img.img_adr, &info->minipl,
		(info->minipl.y * WIDTH) + info->minipl.x, -1);
}
