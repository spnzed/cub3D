/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 20:53:28 by erosas-c          #+#    #+#             */
/*   Updated: 2024/04/23 18:03:19 by aaespino         ###   ########.fr       */
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

// int	ft_esc(int keycode, t_vars *vars)
// {
// 	if (keycode == 53)
// 	{
// 		mlx_destroy_image(vars->mlx, vars->image);
// 		mlx_destroy_window(vars->mlx, vars->win);
// 		free(vars);
// 		exit(1);
// 	}
// 	return (0);
// }

// int	ft_cross(t_vars *vars)
// {
// 	mlx_destroy_image(vars->mlx, vars->image);
// 	mlx_destroy_window(vars->mlx, vars->win);
// 	free(vars);
// 	exit(1);
// 	return (0);
// }

// static void init_loop(t_data *info)
// {

// 	int		*buff;
// 	int		pxl_bits;
// 	int		ln_bytes;
// 	int		endian;
// 	endian = 0;

// 	pxl_bits = 32;
// 	ln_bytes = WIDTH;
// 	mlx_loop(info->mlx.mlx);

// 	// Key hooks
// 	mlx_hook(master->mlx.mlx_win, 2, 1L << 0, &key_down, master);
// 	mlx_hook(master->mlx.mlx_win, 3, 1L << 0, &key_up, master);
// 	// Red cross hook
// 	mlx_hook(vars->win, 17, 0, ft_cross, vars);
// 	mlx_key_hook(vars->win, ft_esc, vars);
// 	// Changes on image
// 	mlx_loop_hook(master->mlx.mlx_ptr, &render, master);
// 	// Maintain window open 
// 	mlx_loop(master->mlx.mlx_ptr);
// }

static int		init_window(t_data *info)
{
	info->mlx.mlx = mlx_init();
	info->mlx.win = mlx_new_window(info->mlx.mlx, WIDTH, HEIGHT, "cub3D");
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
	// init_loop(&info);
	return (0);
}
