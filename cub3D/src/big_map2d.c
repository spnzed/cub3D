/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_map2d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 20:11:18 by erosas-c          #+#    #+#             */
/*   Updated: 2024/05/07 21:05:59 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	fill_player(int	*scr, t_player *pl)
{
	t_point *pts;
	float	tolerance;

	pts = ft_calloc(sizeof(pts), 2);
	if (!pts)
	{
		ft_err("Error: Malloc\n");
		exit (1);
	}
	tolerance = 0.00001;
	pts[0].x = pl->x;
	pts[0].y = pl->y;
	pts[1].x = 0;
	pts[1].y = 0;
//	printf("pts[0].x: %i, pts[0].y: %i\n", pts[0].x, pts[0].y);
//	printf("angle: %f, sinus: %f, cos: %f, len: %f\n", pl->ang, sin(pl->ang), cos(pl->ang), pl->len);
	if (pl->ang >= 0 && pl->ang <= (PI) + tolerance)
	{
		printf("cos(pl->an: %f\n", cos(pl->len));
		pts[1].x = pts[0].x + cos(pl->ang) * pl->len;
		pts[1].y = pts[0].y - sin(pl->ang) * pl->len;
		//printf("arctan(2.0943951024 radians): %f\n", atan(2.0943951024));
		//printf("arctan(2.0943951024 radians): %f\n", -1 / tan(2.0943951024)); >> AQUESTA ES LA FORMULA BONA
	//	printf("000 pts[1].x: %i, pts[1].y: %i\n", pts[1].x, pts[1].y);
	}
//	printf("111 pts[1].x: %i, pts[1].y: %i\n", pts[1].x, pts[1].y);
	draw_line(scr, pts, 0xFFFF00);
}

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
	t_player	*player;
	t_sq		*bigsq;
	int	w = 8;
	int	h = 8;
	int	p = ((HEIGHT / 2 - 160) * WIDTH) + (WIDTH / 2 - 192);

	player = ft_calloc(sizeof(t_player), 1);
	if (!player)
	{
		ft_err("Error: Malloc\n");
		exit (1);
	}
	bigsq = ft_calloc(sizeof(t_sq), 1);
	if (!bigsq)
	{
		ft_err("Error: Malloc\n");
		exit (1);
	}
	temp[0] = "111111";
	temp[1] = "100001";
	temp[2] = "100101";
	temp[3] = "1001E1";
	temp[4] = "111111";
	player->x = WIDTH / 2 + (64 * 3 / 2); //64 = mida passadissos d'una unitat (utilitzada a fill_map) 3/2 per situar-se just enmig de la columna passadis 2a des del centre del mapa 2D (= WIDTH / 2)
	player->y = HEIGHT / 2 + 64; // Li sumem 64 pq des del centre de les files (5 files), ens volem posar junt enmig de la 4a fila i la posicio del mig del mapa = HEIGHT / 2
	player->ang = 2.0943951024; //120 graus
	player->len = 32;
	bigsq->x = WIDTH / 2 + (64 * 3 / 2) - (8 / 2); //6 NOMBRE COLUMNES MAP, 64 = mida passadissos d'una unitat (utilitzada a fill_map)
	bigsq->y = HEIGHT / 2 + 64 - (8 / 2);
	bigsq->ptr = mlx_xpm_file_to_image(info->mlx->mlx, "img/bigmap_player.xpm", &w, &h);
	fill_bigmap(info->mlx->img.img_adr, temp, p, 0);
	fill_player(info->mlx->img.img_adr, player);
	info->bigpl = bigsq;
}
