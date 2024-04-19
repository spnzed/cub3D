/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:38:09 by erosas-c          #+#    #+#             */
/*   Updated: 2024/04/19 17:58:53 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	*fill_black(int *p)
{
	int	color;
	int	y;
	int	x;

	color = 0x000000;
	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			p[(y * WIDTH) + x] = color;
			x++;
		}
		x = 0;
		y++;
	}
	return (p);
}

int	ft_esc(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_image(vars->mlx, vars->image);
		mlx_destroy_window(vars->mlx, vars->win);
		free(vars);
		exit(1);
	}
	return (0);
}

int	ft_cross(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->image);
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars);
	exit(1);
	return (0);
}

int	window(void)
{
	t_vars	*vars;
	int		*buff;
	int		pxl_bits;
	int		ln_bytes;
	int		endian;

	pxl_bits = 32;
	ln_bytes = WIDTH;
	endian = 0;
	vars = (t_vars *)malloc(sizeof(t_vars));
	if (!vars)
		return (0);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, WIDTH, HEIGHT, "Cub3D");
	vars->image = mlx_new_image(vars->mlx, WIDTH, HEIGHT);
	buff = (int *)mlx_get_data_addr(vars->image, &pxl_bits, &ln_bytes, &endian);
	buff = fill_black(buff);
//	buff = feed_buff(fd, map, sc, buff);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->image, 0, 0);
	mlx_key_hook(vars->win, ft_esc, vars);
	mlx_hook(vars->win, 17, 0, ft_cross, vars);
	mlx_loop(vars->mlx);
	return (0);
}