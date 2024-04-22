/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 20:53:28 by erosas-c          #+#    #+#             */
/*   Updated: 2024/04/22 17:39:34 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

static void	init_info(t_data *info)
{
	info->parameters.north = NULL;
	info->parameters.south = NULL;
	info->parameters.west = NULL;
	info->parameters.east = NULL;
	info->parameters.sprite = NULL;
	info->parameters.door = NULL;
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
