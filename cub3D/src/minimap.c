/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:03:48 by erosas-c          #+#    #+#             */
/*   Updated: 2024/05/21 19:50:32 by erosas-c         ###   ########.fr       */
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

/*static void	fill_player(int *scr, t_player *pl, int p, int w)
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
}*/

static void	draw_minipl(int *scr, int xpl, int ypl, int color)
{
	int	x;
	int	y;

	x = xpl - 2;
	y = ypl - 2;
	while (++y <= ypl + 1)
	{
		while (++x <= xpl + 1)
			scr[y * WIDTH + x] = color;
		x = xpl - 2;
	}
}

void	mini_map(t_data *info)
{
	int	p;
	int	cell_w;

	cell_w = 8; //pixels amplada cada cel.la del minimap == marge esquerre i superior mapa respecte límits de la finestra/imatge
	p = WIDTH * cell_w + cell_w; //posisió a la pantalla punt superior esquerre del minimap
	fill_map(info->mlx->img.img_adr, info, p, 0);
	draw_minipl(info->mlx->img.img_adr, info->minipl.x, info->minipl.y, 0xFFFF00);
/*	fill_player(info->mlx->img.img_adr, &info->minipl,
		((info->minipl.y - info->minipl.h / 2) * WIDTH) + (info->minipl.x - info->minipl.w / 2), -1);*/
}
