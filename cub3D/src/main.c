/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 20:53:28 by erosas-c          #+#    #+#             */
/*   Updated: 2024/04/24 18:29:35 by aaespino         ###   ########.fr       */
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
}

static int		init_window(t_data *info)
{
	info->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!info->mlx)
		exit (1);
	info->mlx->mlx = mlx_init();
	info->mlx->win = mlx_new_window(info->mlx->mlx, WIDTH, HEIGHT, "cub3D");
	put_images(info);
	put_position(info);
	return (0);
}

static void init_loop(t_data *info)
{
	mlx_hook(info->mlx->win, 2, 1L << 0, &ft_press, info->mlx);
	mlx_hook(info->mlx->win, 3, 1L << 0, &ft_release, info->mlx);
	mlx_key_hook(info->mlx->win, ft_esc, info->mlx);
	mlx_hook(info->mlx->win, 17, 0, &ft_cross, info->mlx);
	// mlx_loop_hook(info->mlx.img_ptr, &render, master);
	mlx_loop(info->mlx->mlx);
}

int	main(int argc, char **argv)
{
	t_data	info;

	init_info(&info);
	check_args(argc, argv, &info);
	init_window(&info);
	init_loop(&info);
	return (0);
}
