/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_2d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:03:48 by erosas-c          #+#    #+#             */
/*   Updated: 2024/05/10 20:40:37 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	fill_map(int *scr, t_map *map, int p, int i)
{
	int	j;
	int	k;
	int	t;
	t = 16;
//	t = t / 2;  // MacBook erosas
	j = -1;
	k = 0;
	//printf("map->size[1]: %i should be 5\n", map->size[1]);
	while (++j < map->size[1])// j < altura del map quan la tinguem a l'estructura amb la xifra ja parsejada
	{
		while (i < t * (j + 1))
		{
			while (map->grid[j][k])
			{
				while (p < (t * (k + 1) + (WIDTH * i)))
				{
					if (map->grid[j][k] == '1')
					{
						scr[p] = 0xffffff;
//						printf("should print minimap\n");
					}
					p++;
				}
				k++;
			}
			i++;
			p = WIDTH * i;
			k = 0;
		}
	}
}

/*static void	fill_player(int *scr, t_sq *pl, int p, int w)
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

void	mini_map(t_data *info)
{
	char	*temp[5];

	temp[0] = "111111";
	temp[1] = "100001";
	temp[2] = "100101";
	temp[3] = "1001N1";
	temp[4] = "111111";
	//player->ptr = mlx_xpm_file_to_image(info->mlx->mlx, "img/sq.xpm", &player->w, &player->h);
	//player->ang = info->player->ang;  cadra igualar quan el tinguem del parseig pq sera el mateix, i a cada moviment amb qualsevol de les 6 tecles redefinir juntament amb el del jugadr gran/principal
//	printf("info->parameters.floor: %i, ceiling: %i\n", info->parameters.floor, info->parameters.ceiling);
	fill_map(info->mlx->img.img_adr, &info->map, 0, 0);
//	fill_player(info->mlx->img.img_adr, info->minipl, (info->minipl->y * WIDTH) + info->minipl->x, -1);
}
