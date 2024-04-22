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

static int comprove_extension(char *file)
{
	int	i;

	i = ft_strlen(file);
	if (i > 2 && file[i - 4] == '.' && file[i - 3] == 'c'
		&& file[i - 2] == 'u' && file[i - 1] == 'b')
		return (0);
	else
		return (1);
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
	(void)argc;
	(void)argv;
	window();
	(void)check_args;
	/*if (check_args(argc, argv))
		return (1);*/
	// init_process(argv[1]);
	return (0);
}
