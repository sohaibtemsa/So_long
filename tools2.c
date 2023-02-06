/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stemsama <stemsama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:23:37 by stemsama          #+#    #+#             */
/*   Updated: 2023/01/31 17:10:07 by stemsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void	check_recto(char **lstnbr)
{
	int	nbr_colone;
	int	j;

	nbr_colone = ft_strlen(lstnbr[0]);
	j = 1;
	while (lstnbr[j])
	{
		if (nbr_colone != ft_strlen(lstnbr[j]))
			affiche_er(3);
		j++;
	}
}

void	ft_lstclear_double(char **lstmap)
{
	int	i;

	i = 0;
	while (lstmap[i])
		free(lstmap[i++]);
	free(lstmap);
}
