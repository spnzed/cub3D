/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_2d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:03:48 by erosas-c          #+#    #+#             */
/*   Updated: 2024/04/27 13:15:45 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	fill_map(int *scr, char **grid, int p, int i)
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

void	mini_map(t_data *info)
{
	/*char *temp[2];

	temp[0] = "11";
	temp[1] = "1";*/
	char	*temp[5];
	t_sq	*player;

	player = ft_calloc(sizeof(t_sq), 1);
	if (!player)
	{
		ft_err("Error: Malloc\n");
		exit (1);
	}

	temp[0] = "111111";
	temp[1] = "100001";
	temp[2] = "100101";
	temp[3] = "1001P1";
	temp[4] = "111111";
	player->w = 4;
	player->h = 4;
	player->x = (4 * 32) + (32 / 2) - (player->w / 2); //32 = mida passadissos d'una unitat (utilitzada a fill_map)
	player->y = (3 * 32) + (32 / 2) - (player->h / 2);
	player->ptr = mlx_xpm_file_to_image(info->mlx->mlx, "img/sq.xpm", &player->w, &player->h);
//	printf("info->map->floor: %i, ceiling: %i\n", info->map.floor, info->map.ceiling);
	fill_map(info->mlx->img.img_adr, temp/*info->map.grid*/, 0, 0);
	//mlx_put_image_to_window(info->mlx->mlx, info->mlx->win, info->mlx->img.img, 0, 0);
	info->minipl = player;
//	mlx_hook(info->mlx->win, 2, 1L<<0, handle_key_press, player);
//	mlx_do_sync(info->mlx->mlx);
}
