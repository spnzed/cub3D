/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:28:53 by aaespino          #+#    #+#             */
/*   Updated: 2024/06/21 22:28:44 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	gen_color(int R, int G, int B)
{
	int	color;

	color = (R << 16) | (G << 8) | B;
	return (color);
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
	free(buff);
	return (count);
}

int	open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_err("Error: Cannot Open File\n");
	return (fd);
}

void	close_file(int fd, char **scene, bool arr)
{
	if (close(fd) == -1)
	{
		if (arr)
			ft_arrfree(scene);
		ft_err("Error: Cannot Close File\n");
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
