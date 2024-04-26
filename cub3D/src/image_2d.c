/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_2d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:03:48 by erosas-c          #+#    #+#             */
/*   Updated: 2024/04/25 21:30:03 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/*static void	fill_map(int *scr, char **grid)
{
	int		i;
	int		j;
	int		k;
	int		p;

	i = 0;
	j = 0;
	k = 0;
	p = 0;
	while (j < 3 && grid[j] && p < HEIGHT * WIDTH)
	{
		while (i < 5)
		{
			while (grid[j][k])
			{
				printf("grid[j][k]: %c\n", grid[j][k]);
				while (p < (5 * (k + 1) + (WIDTH * i))) //crec que es aqui el problema
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
		printf("i: %i, j: %i, k: %i\n", i, j, k);
		p = WIDTH * i * (j + 1);
		j++;
		i = 0;
		printf("p: %i\n", p);
	}
}*/

static void	paint_ceil_floor(int *p)
{
	int	y;
	int	x;
	int	floor;
	int	ceiling;

	x = 0;
	y = 0;
	floor = 0xDC6400;
	ceiling = 0xE11E00;
	//color = 0x0000FF;
	while (y < HEIGHT / 2)
	{
		while (x < WIDTH)
		{
			p[(y * WIDTH) + x] = ceiling;
			x++;
		}
		x = 0;
		y++;
	}
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			p[(y * WIDTH) + x] = floor;
			x++;
		}
		x = 0;
		y++;
	}
}

void	mini_map(t_data *info)
{
//	char *temp[3];

//	temp[0] = "11";
//	temp[1] = "1";
//	temp[2] = "1";
//	printf("info->map->floor: %i, ceiling: %i\n", info->map.floor, info->map.ceiling);
	paint_ceil_floor(info->mlx->img.img_adr);
//	fill_map(info->mlx->img.img_adr, temp/*info->map.grid*/);
	mlx_put_image_to_window(info->mlx->mlx, info->mlx->win, info->mlx->img.img, 0, 0);
}
