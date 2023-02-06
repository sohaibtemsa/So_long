/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stemsama <stemsama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:12:47 by stemsama          #+#    #+#             */
/*   Updated: 2023/02/04 17:57:28 by stemsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
#include <fcntl.h>
#include <mlx.h>
#include "get_next_line.h"
#include "libft/libft.h"


typedef struct o_list
{
	int				nbr_mv;
	int				nbr_line;
	int				nbr_colone;
	int				line_player;
	int				colone_player;
	int				e;
	int				p;
	int				c;
	char			**lstmap;
	char			**lstmap2;
	void			*back_gd;
	void			*player;
	void			*exit;
	void			*wall;
	void			*collective;
	void			*mlx_ptr;
	void			*win_ptr;
	int				*width;
	int				*height;
}	m_list;

//--------------------------------------------> main_p:
void	check_map_player(char **lstmap, m_list *data);
char	*get_map(int fd, m_list	*data);
void	parsing1(m_list *data, char *str);
int		check_valid_path(m_list *data, int i, int j);

//--------------------------------------------> tools1:
size_t	ft_strlen(const char *str);
void	check_line_fin(char *line1);
void	check_line_extrem(char *linee);
void	affiche_er(int a);
void	check_line1(char *line1);

//--------------------------------------------> tools3_key_hook:
void	m_p_r(m_list *data);
void	m_p_l(m_list *data);
void	m_p_u(m_list *data);
void	m_p_d(m_list *data);
int		move_player(int	key, m_list *data);

//--------------------------------------------> tools2:
void	check_recto(char **lstnbr);
void	ft_lstclear_double(char **lstNbr);

//--------------------------------------------> faire_map:
void	faire_map(m_list *data);
void	prend_limage(m_list *data);
void	appliquer_limage(m_list *data);
int		update_win(m_list *data);


#endif