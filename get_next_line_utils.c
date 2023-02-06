/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stemsama <stemsama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:55:50 by stemsama          #+#    #+#             */
/*   Updated: 2022/11/18 15:55:50 by stemsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_g(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strchr_g(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return (1);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin_g(char *storage, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = -1;
	j = 0;
	if (!storage)
	{
		storage = (char *)malloc(1 * sizeof(char));
		storage[0] = '\0';
	}
	if (!buffer)
		return (free(storage) ,NULL);
	str = malloc(sizeof(char) * ((ft_strlen_g(storage) + ft_strlen_g(buffer)) + 1));
	if (str == NULL)
		return (free(storage) ,NULL);
	if (storage)
		while (storage[++i] != '\0')
			str[i] = storage[i];
	while (buffer[j] != '\0')
		str[i++] = buffer[j++];
	str[ft_strlen_g(storage) + ft_strlen_g(buffer)] = '\0';
	free(storage);
	return (str);
}

char	*get_line(char *storage)
{
	int		i;
	char	*line;

	i = 0;
	if (!storage[i])
		return (NULL);
	while (storage[i] && storage[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
	{
		line[i] = storage[i];
		i++;
	}
	if (storage[i] == '\n')
	{
		line[i] = storage[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_rest(char *storage)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	if (!storage[i])
	{
		free(storage);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen_g(storage) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (storage[i])
		str[j++] = storage[i++];
	str[j] = '\0';
	free(storage);
	return (str);
}
