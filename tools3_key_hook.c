/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3_key_hook.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stemsama <stemsama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:55:27 by stemsama          #+#    #+#             */
/*   Updated: 2023/02/03 09:50:02 by stemsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void	m_p_r(m_list *data)
{
	if (data->lstmap[data->line_player][data->colone_player + 1] == 'C')
		data->c = data->c - 1;
	if (data->lstmap[data->line_player][data->colone_player + 1] != '1')
	{
		if (data->lstmap[data->line_player][data->colone_player + 1] == 'E')
		{
			if (data->c == 0)
			{
				write(1, "GAME OVER\n", 11);
				exit(0);
			}
			else
				return ;
		}
		data->lstmap[data->line_player][data->colone_player + 1] = 'P';
		data->lstmap[data->line_player][data->colone_player] = '0';
		data->colone_player++;
		data->nbr_mv++;
		ft_putnbr_fd(data->nbr_mv, 1);
		write(1, "\n", 1);
	}
}

void	m_p_l(m_list *data)
{
	if (data->lstmap[data->line_player][data->colone_player - 1] == 'C')
		data->c = data->c - 1;
	if (data->lstmap[data->line_player][data->colone_player - 1] != '1')
	{
		if (data->lstmap[data->line_player][data->colone_player - 1] == 'E')
		{
			if (data->c == 0)
			{
				write(1, "GAME OVER\n", 11);
				exit(0);
			}
			else
				return ;
		}
		data->lstmap[data->line_player][data->colone_player - 1] = 'P';
		data->lstmap[data->line_player][data->colone_player] = '0';
		data->colone_player--;
		data->nbr_mv++;
		ft_putnbr_fd(data->nbr_mv, 1);
		write(1, "\n", 1);
	}
}

void	m_p_u(m_list *data)
{
	if (data->lstmap[data->line_player - 1][data->colone_player] == 'C')
		data->c = data->c - 1;
	if (data->lstmap[data->line_player - 1][data->colone_player] != '1')
	{
		if (data->lstmap[data->line_player - 1][data->colone_player] == 'E')
		{
			if (data->c == 0)
			{
				write(1, "GAME OVER\n", 11);
				exit(0);
			}
			else
				return ;
		}
		data->lstmap[data->line_player - 1][data->colone_player] = 'P';
		data->lstmap[data->line_player][data->colone_player] = '0';
		data->line_player--;
		data->nbr_mv++;
		ft_putnbr_fd(data->nbr_mv, 1);
		write(1, "\n", 1);
	}
}

void	m_p_d(m_list *data)
{
	if (data->lstmap[data->line_player + 1][data->colone_player] == 'C')
		data->c = data->c - 1;
	if (data->lstmap[data->line_player + 1][data->colone_player] != '1')
	{
		if (data->lstmap[data->line_player + 1][data->colone_player] == 'E')
		{
			if (data->c == 0)
			{
				write(1, "GAME OVER\n", 11);
				exit(0);
			}
			else
				return ;
		}
		data->lstmap[data->line_player + 1][data->colone_player] = 'P';
		data->lstmap[data->line_player][data->colone_player] = '0';
		data->line_player++;
		data->nbr_mv++;
		ft_putnbr_fd(data->nbr_mv, 1);
		write(1, "\n", 1);
	}
}

int	move_player(int	key, m_list *data)
{
	if (key == 1 || key == 125)
		m_p_d(data);
	else if (key == 13  || key == 126)
		m_p_u(data);
	else if (key == 0  || key == 123)
		m_p_l(data);
	else if (key == 2  || key == 124)
		m_p_r(data);
	else if (key == 53 || key == 51)
		{
			write(1, "GAME OVER\n", 11);
			exit(0);
		}
	return (0);
}