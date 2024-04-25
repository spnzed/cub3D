/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:28:53 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/25 02:06:33 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

float	angle_correction(float ang)
{
	if (ang > 359)
		ang -= 360;
	else if (ang < 0)
		ang += 360;
	return (ang);
}

float	deg_to_rad(float d)
{
	return (d * M_PI / 180.0);
}

int	ft_count_lines(int fd)
{
	int		count;
	char	*buff;

	count = 0;
	buff = get_next_line(fd);
	while (buff)
	{
		count++;
		free(buff);
		buff = get_next_line(fd);
	}
	return (count);
}

int	open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf(RED"Error: Cannot Open File\n"RESET);
		exit(1);
	}
	return (fd);
}

void	close_file(int fd, char **scene, bool arr)
{
	if (close(fd) == -1)
	{
		if (arr)
			ft_arrfree(scene);
		printf(RED"Error: Cannot Close File\n"RESET);
		exit(1);
	}
	return ;
}

int	valid_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	close(fd);
	return (0);
}
