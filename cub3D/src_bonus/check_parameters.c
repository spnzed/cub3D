/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parameters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:04:46 by aaespino          #+#    #+#             */
/*   Updated: 2024/07/04 18:44:00 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	*check_texture_element(char *line, char *param)
{
	if (ft_strlen(param) != 0)
		ft_err("Error: Parameters: Repeated Element Found\n");
	line = ft_strnchr(line + 2, '/');
	while (ft_isspace(*line))
		line++;
	if (ft_strrcmp(line, ".xpm") != 0)
		ft_err("Error: Parameters: Incorrect Format\n");
	param = ft_strtrim(line, "\t");
	return (param);
}

static int	check_color_element(char *line, int color)
{
	int		ret;
	char	*red;
	char	*green;
	char	*blue;

	ret = 0;
	if (color > 0)
		ret = ft_err("Error: Parameters: Repeated Element Found\n");
	line = ft_strnchr(line + 1, ' ');
	red = get_color(line, 'R');
	green = get_color(line, 'G');
	blue = get_color(line, 'B');
	if (rgb_check(red) || rgb_check(green) || rgb_check(blue))
		ret = ft_err("Error: Parameters: Incorrect Format\n");
	else
		ret = gen_color(ft_atoi(red), ft_atoi(green), ft_atoi(blue));
	free(red);
	free(green);
	free(blue);
	return (ret);
}

static void	check_parameters(t_data *info, char *line)
{
	while (ft_isspace(*line))
		line++;
	if (!ft_strncmp(line, "NO", 2))
		info->parameters.north = check_texture_element(line, \
			info->parameters.north);
	else if (!ft_strncmp(line, "SO", 2))
		info->parameters.south = check_texture_element(line, \
			info->parameters.south);
	else if (!ft_strncmp(line, "WE", 2))
		info->parameters.west = check_texture_element(line, \
			info->parameters.west);
	else if (!ft_strncmp(line, "EA", 2))
		info->parameters.east = check_texture_element(line, \
			info->parameters.east);
	else if (!ft_strncmp(line, "F", 1))
		info->parameters.floor = check_color_element(line, \
			info->parameters.floor);
	else if (!ft_strncmp(line, "C", 1))
		info->parameters.ceiling = check_color_element(line, \
			info->parameters.ceiling);
	else
		ft_err("Error: Parameters: Doesn't Follow Guidelines\n");
}

static int	open_textures(t_data *info)
{
	if (valid_file(info->parameters.north)
		|| valid_file(info->parameters.south)
		|| valid_file(info->parameters.west)
		|| valid_file(info->parameters.east))
		ft_err("Error: Parameters: Can't Open Textures\n");
	return (0);
}

int	check_textures(char **scene, t_data *info)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (scene[++i])
	{
		if (ft_strlen(scene[i]) > 0 && !ft_strisspace(scene[i]))
		{
			if (count < 6)
				check_parameters(info, scene[i]);
			count++;
		}
	}
	duplicated_texture_file(info);
	if (open_textures(info))
		return (1);
	return (0);
}
