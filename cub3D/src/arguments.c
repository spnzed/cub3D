/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:46:42 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/19 17:22:05 by aaespino         ###   ########.fr       */
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

static int	check_file(char *file, t_data *info)
{
	get_file(file, info);
	if (check_textures(info->scene, info))
		return (1);
	if (check_map_char(info->scene))
		return (1);
	if (check_map_border(info->scene))
		return (1);
	return (0);
}

int	check_args(int argc, char **argv, t_data *info)
{
	if (argc < 2)
		return (printf(RED"Error: Not Enough Arguments\n"RESET), 1);
	if (argc > 2)
		return (printf(RED"Error: Too Much Arguments\n"RESET), 1);
	if (ft_strlen(argv[1]) <= 4)
		return (printf(RED"Error: Invalid Path\n"RESET), 1);
	if (comprove_extension(argv[1]))
		return (printf(RED"Error: Incorret File Extension\n"RESET), 1);
	if (check_file(argv[1], info))
		return (1);
	return 0;
}
