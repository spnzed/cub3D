/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 20:53:28 by erosas-c          #+#    #+#             */
/*   Updated: 2024/04/23 19:56:43 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	init_info(t_data *info)
{
	info = ft_calloc(1, sizeof(t_data));
	if (!info)
	{
		printf(RED"Error: Malloc\n"RESET);
		exit (1);
	}
	// info->parameters.north = NULL;
	// info->parameters.south = NULL;
	// info->parameters.west = NULL;
	// info->parameters.east = NULL;
	// info->parameters.floor = -2;
	// info->parameters.ceiling = -2;
}

int	ft_esc(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
	{
		mlx_destroy_image(mlx->mlx, mlx->img.img);
		mlx_destroy_window(mlx->mlx, mlx->win);
		free(mlx);
		exit(1);
	}
	return (0);
}

int	ft_cross(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img.img);
	mlx_destroy_window(mlx->mlx, mlx->win);
	free(mlx);
	exit(1);
	return (0);
}

// Key hooks
// mlx_hook(master->mlx.mlx_win, 2, 1L << 0, &key_down, master);
// mlx_hook(master->mlx.mlx_win, 3, 1L << 0, &key_up, master);
static void init_loop(t_data *info)
{
	mlx_hook(info->mlx->win, 17, 0, ft_cross, info->mlx);
	mlx_key_hook(info->mlx->win, ft_esc, info->mlx);
	mlx_loop(info->mlx->mlx);
	// mlx_loop_hook(info->mlx.img_ptr, &render, master);
}

static int		init_window(t_data *info)
{
	info->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!info->mlx)
		exit (1);
	info->mlx->mlx = mlx_init();
	info->mlx->win = mlx_new_window(info->mlx->mlx, WIDTH, HEIGHT, "cub3D");
	put_images(info);
	// put_position(info);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	info;

	init_info(&info);
	check_args(argc, argv, &info);
	init_window(&info);
	// init_graphics(&info);
	init_loop(&info);
	return (0);
}
