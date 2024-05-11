/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_2d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:03:48 by erosas-c          #+#    #+#             */
/*   Updated: 2024/05/11 19:15:51 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	fill_map(int *scr, t_data *info, int p, int i)
{
	int	j;
	int	k;
	int	po;
	//t = t / 2;  // MacBook Ester
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
					if (info->map.grid[j][k] == '1')
						scr[p] = 0x743636;
					else
						scr[p] = info->parameters.floor;
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
	t_player	*minipl;
	int			cell_w;
	int			p;

	cell_w = 8;
	p = WIDTH * cell_w + cell_w;
	minipl = ft_calloc(sizeof(t_player), 1);
	if (!minipl)
	{
		ft_err("Error: Malloc\n");
		exit (1);
	}
	minipl->h = 4;
	minipl->w = 4;
	minipl->x = info->map.spawn[0] * cell_w + cell_w / 2;
	minipl->y = info->map.spawn[1] * cell_w + cell_w / 2;
	fill_map(info->mlx->img.img_adr, info, p, 0);
	fill_player(info->mlx->img.img_adr, minipl, p + (minipl->y * WIDTH) + minipl->x, -1);
}
