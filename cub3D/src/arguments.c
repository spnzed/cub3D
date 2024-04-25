/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:46:42 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/25 17:26:53 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_extension(char *file)
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
		err = ft_err("Error: Not Enough Arguments\n");
	else if (argc > 2)
		err = ft_err("Error: Too Many Arguments\n");
	else if (ft_strlen(argv[1]) <= 4)
		err = ft_err("Error: Invalid Path\n");
	else if (check_extension(argv[1]))
		err = ft_err("Error: Incorrect File Extension\n");
	if (err)
		exit(1);
	else
		handle_map(argv[1], info);
	return (0);
}
