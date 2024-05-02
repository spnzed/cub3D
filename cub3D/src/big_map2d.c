/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_map2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 20:11:18 by erosas-c          #+#    #+#             */
/*   Updated: 2024/05/02 20:42:27 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	fill_bigmap(int *scr, char **grid, int p, int i)
{
	int	j;
	int	k;

	j = -1;
	k = 0;
	while (++j < 5)// j < altura del map quan la tinguem a l'estructura amb la xifra ja parsejada
	{
		while (i < 32 * (j + 1))
		{
			while (grid[j][k])
			{
				while (p < (32 * (k + 1) + (WIDTH * i)))
				{
					if (grid[j][k] == '1')
						scr[p] = 0xffffff;
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



void	get_bigmap2d(t_data *info)
{
	char		*temp[5];
	t_player	*player;
	int	w = 8;
	int	h = 8;

	player = ft_calloc(sizeof(t_player), 1);
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
	player->x = WIDTH / 2 + (1,5 * 64) - (8 / 2); //6 NOMBRE COLUMNES MAP, 64 = mida passadissos d'una unitat (utilitzada a fill_map)
	player->y = HEIGHT / 2 + 64 - (8 / 2);
	player->ptr = mlx_xpm_file_to_image(info->mlx->mlx, "img/player.xpm", &w, &h);
//	printf("info->map->floor: %i, ceiling: %i\n", info->map.floor, info->map.ceiling);
	fill_map(info->mlx->img.img_adr, temp/*info->map.grid*/, TO CALCULATE, 0);

	fill_bigmap(info->mlx->img.img_adr, temp, 0, 0);


	
}