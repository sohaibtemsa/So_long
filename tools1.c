/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stemsama <stemsama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 19:32:12 by stemsama          #+#    #+#             */
/*   Updated: 2023/02/03 09:08:20 by stemsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str++)
	{
		i++;
	}
	return (i);
}

void	check_line1(char *line1)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(line1);
	while (i < size - 1)
	{
		if (line1[i] == '1')
			i++;
		else
			affiche_er(1);
	}
}

void	check_line_fin(char *line1)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(line1);
	while (i < size)
	{
		if (line1[i] == '1')
			i++;
		else
			affiche_er(1);
	}
}

void	check_line_extrem(char *linee)
{
	int	size;

	size = ft_strlen(linee);
	if (linee[size - 1] != '\n')
		check_line_fin(linee);
	if (linee[0] != '1' || linee[size - 2] != '1')
		affiche_er(1);
}

void	affiche_er(int a)
{
	if (a == 1)
		write(2, "map non valide\n", 15);
	else if (a == 2)
		write(2, "error\n", 6);
	else if (a == 3)
		write(2, "map n'est pas rectangle\n", 24);
	exit(1);
}
