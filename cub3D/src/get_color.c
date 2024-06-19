/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:44:19 by aaespino          #+#    #+#             */
/*   Updated: 2024/06/18 20:02:02 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	rgb_check(char *rgb)
{
	char	*trim;

	if (!rgb)
		return (1);
	trim = ft_strtrim(rgb, " ");
	while (ft_isspace(*trim))
		trim++;
	if (!ft_istype_iter(trim, ft_isdigit))
		return (free(trim), 1);
	if (!ft_isint(trim))
		return (free(trim), 1);
	return (0);
}

char	*get_red(char *str)
{
	int		i;
	char	*ret;

	i = 0;
	ret = NULL;
	while (str[i])
	{
		if (str[i] == ',')
		{
			ret = ft_substr(str, 0, i);
			break ;
		}
		i++;
	}
	return (ret);
}

char	*get_green(char *str)
{
	int		i;
	int		start;
	int		count;
	char	*ret;

	i = 0;
	start = 0;
	count = 0;
	ret = NULL;
	while (str[i])
	{
		if (str[i] == ',')
		{
			count++;
			if (count == 1)
				start = i;
			if (count == 2)
			{
				ret = ft_substr(str, start + 1, i - start - 1);
				break ;
			}
		}
		i++;
	}
	return (ret);
}

char	*get_blue(char *str)
{
	int		i;
	char	*ret;

	i = ft_strlen(str) - 1;
	ret = NULL;
	while (str[i])
	{
		if (str[i] == ',')
		{
			ret = ft_substr(str, i + 1, ft_strlen(str) - 1);
			break ;
		}
		i--;
	}
	return (ret);
}

char	*get_color(char *str, char rgb)
{
	if (rgb == 'R')
		return (get_red(str));
	if (rgb == 'G')
		return (get_green(str));
	if (rgb == 'B')
		return (get_blue(str));
	return (0);
}
