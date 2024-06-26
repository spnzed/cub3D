/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaronespinosa <aaronespinosa@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:53:44 by apresas-          #+#    #+#             */
/*   Updated: 2024/06/21 22:37:43 by aaronespino      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	gnl_strlen(char *str)
{
	size_t		n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

char	*gnl_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (0);
	s_len = gnl_strlen(s);
	i = 0;
	if (len > s_len)
		len = s_len + 1;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	if (start < s_len)
		while (i < len)
			str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

char	*gnl_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[gnl_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*gnl_strjoin(char *left_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		left_str[0] = '\0';
	}
	if (!left_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((gnl_strlen(left_str) + \
	gnl_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (left_str)
		while (left_str[++i] != '\0')
			str[i] = left_str[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[gnl_strlen(left_str) + gnl_strlen(buff)] = '\0';
	free(left_str);
	return (str);
}

// ORIGINAL GNL:

static char	*read_to_buffer(int fd, char *buffer);
static char	*buffer_to_string(char *buffer);
static char	*buffer_cleanup(char *old_buffer);

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*string;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = read_to_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	string = buffer_to_string(buffer);
	buffer = buffer_cleanup(buffer);
	return (string);
}

static char	*read_to_buffer(int fd, char *buffer)
{
	char	*auxiliar;
	int		aux_len;

	aux_len = 1;
	auxiliar = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!auxiliar)
		return (NULL);
	while (!gnl_strchr(buffer, '\n') && aux_len != 0)
	{
		aux_len = read(fd, auxiliar, BUFFER_SIZE);
		if (aux_len == -1)
		{
			free(auxiliar);
			return (NULL);
		}
		auxiliar[aux_len] = '\0';
		buffer = gnl_strjoin(buffer, auxiliar);
	}
	free(auxiliar);
	return (buffer);
}

static char	*buffer_to_string(char *buffer)
{
	int		i;
	char	*to_string;

	i = 0;
	if (buffer[i] == '\0')
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	i++;
	to_string = malloc(sizeof(char) * (i + 1));
	if (!to_string)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		to_string[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		to_string[i++] = '\n';
	to_string[i] = '\0';
	return (to_string);
}

static char	*buffer_cleanup(char *old_buffer)
{
	int		i;
	int		j;
	int		buffer_len;
	char	*new_buffer;

	i = 0;
	j = 0;
	while (old_buffer[i] != '\n' && old_buffer[i] != '\0')
		i++;
	if (old_buffer[i] == '\0')
	{
		free(old_buffer);
		return (NULL);
	}
	buffer_len = gnl_strlen(old_buffer) - i;
	new_buffer = malloc(sizeof(char) * (buffer_len + 1));
	if (!new_buffer)
		return (NULL);
	i++;
	while (old_buffer[i] != '\0')
		new_buffer[j++] = old_buffer[i++];
	new_buffer[j] = '\0';
	free(old_buffer);
	return (new_buffer);
}

/* NEWER VERSION THAT IS HALFWAY THROUGH:

static void	*gnl_error(char *err);
static char	*read_to_buffer(int fd, char *buffer);
static char	*buffer_to_string(char *buffer);
static char	*buffer_cleanup(char *old_buffer);

// This implementation is not super clean
char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*string;

	if (BUFFER_SIZE <= 0)
		return (gnl_error(GNL_ERR_BUFFER_SIZE));
	if (fd < 0)
		return (gnl_error(GNL_ERR_FD));
	buffer = read_to_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	string = buffer_to_string(buffer);
	buffer = buffer_cleanup(buffer);
	return (string);
}

static char	*read_to_buffer(int fd, char *buffer)
{
	char	*auxiliar;
	int		aux_len;

	aux_len = 1;
	auxiliar = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!auxiliar)
		return (gnl_error(GNL_ERR_MALLOC));
	while (!gnl_strchr(buffer, '\n') && aux_len != 0)
	{
		aux_len = read(fd, auxiliar, BUFFER_SIZE);
		if (aux_len == -1)
		{
			free(auxiliar);
			return (gnl_error(GNL_ERR_READ));
		}
		auxiliar[aux_len] = '\0';
		buffer = ft_strjoin(buffer, auxiliar);
	}
	free(auxiliar);
	return (buffer);
}

static char	*buffer_to_string(char *buffer)
{
	int		i;
	char	*to_string;

	i = 0;
	if (buffer[i] == '\0')
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	i++;
	to_string = malloc(sizeof(char) * (i + 1));
	if (!to_string)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		to_string[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		to_string[i++] = '\n';
	to_string[i] = '\0';
	return (to_string);
}

static char	*buffer_cleanup(char *old_buffer)
{
	int		i;
	int		j;
	int		buffer_len;
	char	*new_buffer;

	i = 0;
	j = 0;
	while (old_buffer[i] != '\n' && old_buffer[i] != '\0')
		i++;
	if (old_buffer[i] == '\0')
	{
		free(old_buffer);
		return (NULL);
	}
	buffer_len = ft_strlen(old_buffer) - i;
	new_buffer = malloc(sizeof(char) * (buffer_len + 1));
	if (!new_buffer)
		return (gnl_error(GNL_ERR_MALLOC));
	i++;
	while (old_buffer[i] != '\0')
		new_buffer[j++] = old_buffer[i++];
	new_buffer[j] = '\0';
	free(old_buffer);
	return (new_buffer);
}

static void	*gnl_error(char *err)
{
	ft_printf_fd(2, GNL_ERR_PREFIX);
	ft_printf_fd(2, err);
	ft_printf_fd(2, "\n");
	return (NULL);
}

*/