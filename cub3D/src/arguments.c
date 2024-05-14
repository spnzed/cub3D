/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:46:42 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/25 00:30:23 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	comprove_extension(char *file)
{
	int	i;

	i = ft_strlen(file);
	if (i > 2 && file[i - 4] == '.' && file[i - 3] == 'c'
		&& file[i - 2] == 'u' && file[i - 1] == 'b')
		return (0);
	else
		return (1);
}

int	check_args(int argc, char **argv, t_data *info)
{
	int	err;

	err = 0;
	if (argc < 2)
		err = printf(RED"Error: Not Enough Arguments\n"RESET);
	if (argc > 2)
		err = printf(RED"Error: Too Many Arguments\n"RESET);
	if (ft_strlen(argv[1]) <= 4)
		err = printf(RED"Error: Invalid Path\n"RESET);
	if (comprove_extension(argv[1]))
		err = printf(RED"Error: Incorrect File Extension\n"RESET);
	if (err)
		exit(1);
	else
		handle_map(argv[1], info);
	return (0);
}
