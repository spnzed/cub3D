/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 20:53:28 by erosas-c          #+#    #+#             */
/*   Updated: 2024/05/14 18:54:34 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_keys(t_mlx *mlx)
{
	t_keys	*keys;

	keys = ft_calloc(sizeof(t_keys), 1);
	if (!keys)
	{
		ft_err("Error: Malloc\n");
		exit (1);
	}
	keys->w = 0;
	keys->a = 0;
	keys->d = 0;
	keys->s = 0;
	mlx->keys = keys;
}

static t_data	*init_info(void)
{
	t_data	*info;

	info = ft_calloc(1, sizeof(t_data));
	if (!info)
	{
		ft_err("Error: Malloc\n");
		exit (1);
	}
	info->map.grid_pos = -1;
	info->parameters.north = NULL;
	info->parameters.south = NULL;
	info->parameters.west = NULL;
	info->parameters.east = NULL;
	info->parameters.floor = -1;
	info->parameters.ceiling = -1;
	return (info);
}

static int	init_window(t_data *info)
{
	info->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!info->mlx)
		exit (1);
	info->mlx->mlx = mlx_init();
	info->mlx->win = mlx_new_window(info->mlx->mlx, WIDTH, HEIGHT, "cub3D");
	init_keys(info->mlx);
	put_images(info);
	put_position(info);
	return (0);
}

static void	init_loop(t_data *info)
{
	mlx_hook(info->mlx->win, 2, 1L << 0, &ft_press, info->mlx);
	mlx_hook(info->mlx->win, 3, 1L << 1, &ft_release, info->mlx);
	mlx_hook(info->mlx->win, 17, 0, &ft_cross, info->mlx);
	mlx_loop_hook(info->mlx->mlx, &render, info);
	mlx_loop(info->mlx->mlx);
}

int	main(int argc, char **argv)
{
	t_data	*info;

	info = init_info();
	check_args(argc, argv, info);
	init_window(info);
	init_loop(info);
	return (0);
}
