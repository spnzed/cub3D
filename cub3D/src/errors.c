/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:17:34 by erosas-c          #+#    #+#             */
/*   Updated: 2024/04/24 13:48:32 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_err(char *str)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(RESET, 2);
	exit (1);
}

void	duplicated_texture_file(t_data *info)
{
	char	*n;
	char	*s;
	char	*e;
	char	*w;

	n = info->parameters.north;
	s = info->parameters.south;
	e = info->parameters.east;
	w = info->parameters.west;
	if (!ft_strncmp(n, s, ft_strlen(n)) || !ft_strncmp(n, e, ft_strlen(n))
		|| !ft_strncmp(n, w, ft_strlen(n)) || !ft_strncmp(s, e, ft_strlen(s))
		|| !ft_strncmp(s, w, ft_strlen(s)) || !ft_strncmp(e, w, ft_strlen(e)))
		ft_err("Error: Parameters: Repeated Texture Found\n");
}
