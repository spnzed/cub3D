/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parameters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:04:46 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/22 19:05:25 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	*check_texture_element(char *line, char *param)
{
	if (param != NULL)
	{
		printf(RED"Error: Parameters: Repeated Element Found\n"RESET);
		exit(1);
	}
	line = ft_strnchr(line + 2, ' ');
	if (ft_strrcmp(line, ".xpm") != 0)
	{
		printf(RED"Error: Parameters: Incorrect Format\n"RESET);
		exit(1);
	}
	param = ft_strdup(line);
	return (param);
}

static int	check_color_element(char *line, int *color)
{
	int	line_end;
	char	*red;
	char	*green;
	char	*blue;

	if (*color > 0)
		return (printf(RED"Error: Parameters: Repeated Element Found\n"RESET), 1);
	line_end = ft_strlen(line);
	line = ft_strnchr(line + 1, ' ');
	red = get_color(line, 'R');
	green = get_color(line, 'G');
	blue = get_color(line, 'B');
	if (rgb_check(red) || rgb_check(green) || rgb_check(blue))
		return (printf(RED"Error: Parameters: Incorrect Format\n"RESET), 1);
	return (0);
}

static void	check_parameters(t_data *info, char *line, int i)
{
	if (!ft_strncmp(line, "NO", 2) && i == 0)
		info->parameters.north = check_texture_element(line, info->parameters.north);
	else if (!ft_strncmp(line, "SO", 2) && i == 1)
		info->parameters.south = check_texture_element(line, info->parameters.south);
	else if (!ft_strncmp(line, "WE", 2) && i == 2)
		info->parameters.west = check_texture_element(line, info->parameters.west);
	else if (!ft_strncmp(line, "EA", 2) && i == 3)
		info->parameters.east = check_texture_element(line, info->parameters.east);
	else if (!ft_strncmp(line, "F", 1) && i == 4)
		check_color_element(line, &info->parameters.floor);
	else if (!ft_strncmp(line, "C", 1) && i == 5)
		check_color_element(line, &info->parameters.ceiling);
	else if (line[0] != '\0')
	{
		printf(RED"Error: Parameters: Doesn't Folow Guidelines\n"RESET);
		exit (1);
	}
}

static int	open_textures(t_data *info)
{
	if (valid_file(info->parameters.north) 
		|| valid_file(info->parameters.south)
		|| valid_file(info->parameters.west)
		|| valid_file(info->parameters.east))
	{
		printf(RED"Error: Parameters: Can't Open Textures\n"RESET);
		return (1);
	}
	return (0);
}

int	check_textures(char **scene, t_data *info)
{
	int i = -1;
	int count = 0;

	while (scene[++i])
	{
		if (ft_strlen(scene[i]) > 1)
		{
			if (count < 6)
				check_parameters(info, scene[i], count);
			count++;
		}
	}
	if (open_textures(info))
		return (1);
	return (0);
}
