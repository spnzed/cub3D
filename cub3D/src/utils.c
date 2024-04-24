/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erosas-c <erosas-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:28:53 by aaespino          #+#    #+#             */
/*   Updated: 2024/04/24 13:56:27 by erosas-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
		ft_err("Error: Cannot Open File\n");
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
		ft_err("Error: Cannot Close File\n");
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
