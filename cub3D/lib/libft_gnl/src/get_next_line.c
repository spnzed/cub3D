/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 18:06:21 by aaespino          #+#    #+#             */
/*   Updated: 2024/06/27 00:49:00 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_static(char *save)
{
	int		i;
	int		j;
	int		len;
	char	*str2;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	len = (ft_strlen(save) - i);
	str2 = malloc((len + 1) * sizeof(char));
	j = 0;
	i++;
	while (save[i])
		str2[j++] = save[i++];
	str2[j] = '\0';
	free(save);
	return (str2);
}

static char	*ft_line(char *save)
{
	int		i;
	char	*str;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	str = malloc((i + 2) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		str[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		str[i] = '\n';
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*ft_main(char *save, int fd)
{
	char	*buffer;
	int		numbytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	numbytes = 1;
	while (numbytes && !ft_strchr(save, '\n'))
	{
		numbytes = read(fd, buffer, BUFFER_SIZE);
		if (numbytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[numbytes] = '\0';
		save = ft_strjoin2(save, buffer);
	}
	free(buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (BUFFER_SIZE < 0 || fd < 0)
		return (NULL);
	save = ft_main(save, fd);
	if (!save)
		return (NULL);
	line = ft_line(save);
	save = ft_static(save);
	return (line);
}
