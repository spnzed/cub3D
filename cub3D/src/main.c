/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 20:53:28 by erosas-c          #+#    #+#             */
/*   Updated: 2024/04/19 19:10:10 by erosas-c         ###   ########.fr       */
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

static int	check_args(int argc, char **argv)
{
	if (argc < 2)
		return (printf(RED"Error: Not Enough Arguments\n"RESET), 1);
	if (argc > 2)
		return (printf(RED"Error: Too Much Arguments\n"RESET), 1);
	if (ft_strlen(argv[1]) <= 4)
		return (printf(RED"Error: Invalid Path\n"RESET), 1);
	if (comprove_extension(argv[1]))
		return (printf(RED"Error: Incorret File Extension\n"RESET), 1);
	// if (check_map(argv[1]))
	// 	return (1);
	return 0;
}

int	main(int argc, char **argv)
{
	t_data	info;

	init_info(&info);
	if (check_args(argc, argv, &info))
		return (1);
	window();
	// init_process(argv[1]);
	return (0);
}
