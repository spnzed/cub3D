/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 20:53:28 by erosas-c          #+#    #+#             */
/*   Updated: 2024/04/23 00:12:56 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	init_info(t_data *info)
{
	info->parameters.north = NULL;
	info->parameters.south = NULL;
	info->parameters.west = NULL;
	info->parameters.east = NULL;
	info->parameters.floor = -2;
	info->parameters.ceiling = -2;
}

int	main(int argc, char **argv)
{
	t_data	info;

	init_info(&info);
	check_args(argc, argv);
	handle_map(argv[1], &info);
	init_window();
	// init_process(argv[1]);
	return (0);
}
