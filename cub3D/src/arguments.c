/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:46:42 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/22 14:43:26 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

int	check_args(int argc, char **argv)
{
	int	err;

	err = 0;
	if (argc < 2)
		err = printf(RED"Error: Not Enough Arguments\n"RESET);
	if (argc > 2)
		err = printf(RED"Error: Too Much Arguments\n"RESET);
	if (ft_strlen(argv[1]) <= 4)
		err = printf(RED"Error: Invalid Path\n"RESET);
	if (comprove_extension(argv[1]))
		err = printf(RED"Error: Incorret File Extension\n"RESET);
	if (err)
		exit(1);
	return 0;
}
