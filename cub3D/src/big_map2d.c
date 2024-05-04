/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_map2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 20:11:18 by erosas-c          #+#    #+#             */
/*   Updated: 2024/05/04 13:03:48 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	fill_bigmap(int *scr, char **grid, int p, int i)
{
	int	j;
	int	k;
	int	po;
	j = -1;
	k = 0;
	po = p;
	while (++j < 5)// j < altura del map quan la tinguem a l'estructura amb la xifra ja parsejada
	{
		while (i < 64 * (j + 1))
		{
			while (grid[j][k])
			{
				while (p < po + (64 * (k + 1) + (WIDTH * i)))
				{
					if (grid[j][k] == '1')
						scr[p] = 0xffffff;
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

void	get_bigmap2d(t_data *info)
{
	char		*temp[5];
	t_sq		*player;
	int	w = 32;
	int	h = 24;
	int	p = ((HEIGHT / 2 - 160) * WIDTH) + (WIDTH / 2 - 192);

	player = ft_calloc(sizeof(t_sq), 1);
	if (!player)
	{
		ft_err("Error: Malloc\n");
		exit (1);
	}
	temp[0] = "111111";
	temp[1] = "100001";
	temp[2] = "100101";
	temp[3] = "1001E1";
	temp[4] = "111111";
	player->x = WIDTH / 2 + (64 * 3 / 2) - (32 / 2); //6 NOMBRE COLUMNES MAP, 64 = mida passadissos d'una unitat (utilitzada a fill_map)
	player->y = HEIGHT / 2 + 64 - (24 / 2);
	player->ptr = mlx_xpm_file_to_image(info->mlx->mlx, "img/bigmap_player.xpm", &w, &h);
	fill_bigmap(info->mlx->img.img_adr, temp, p, 0);
	info->bigpl = player;
}
