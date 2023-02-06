/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stemsama <stemsama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:39:19 by stemsama          #+#    #+#             */
/*   Updated: 2023/02/04 18:00:13 by stemsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

char	*get_map(int fd, m_list	*data)
{
	char	*line;
	char	*action_tmp;

    action_tmp = NULL;
    data->nbr_line = 0;
	line = get_next_line(fd);
	if (line == '\0')
		affiche_er(1);
	data->nbr_colone = ft_strlen(line) - 1;
	check_line1(line);
	if (!line)
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	while (line != NULL)
	{
		data->nbr_line += 1;
		check_line_extrem(line);
		action_tmp = ft_strjoin(action_tmp,line);
		line = get_next_line(fd);
	}
	return (action_tmp);
}

void	check_map_player(char **lstmap, m_list *data)
{
	int	i;
	int	j;

	i = 0;
	lstmap = data->lstmap;
	while (lstmap[i])
	{
		j = 0;
		while (lstmap[i][j])
		{
			if (lstmap[i][j] == 'P')
			{
				data->line_player = i;
				data->colone_player = j;
			}
			j++;
		}
		i++;
	}
}

int	main(void)
{
	int		fd;
	char	*line;
	m_list	*data;

	data = malloc(sizeof(m_list));
	if (!data)
		affiche_er(2);
	fd = open("map.ber", O_RDONLY);
	line = get_map(fd, data);
	if ( data->nbr_line > 28 || data->nbr_colone > 51)
		affiche_er(1);
	if (line[ft_strlen(line) - 1] != '1')
		affiche_er(1);
	parsing1(data, line);
	data->lstmap = ft_split(line, '\n');
	data->lstmap2 = ft_split(line, '\n');
	check_map_player(data->lstmap, data);
	if (check_valid_path(data,data->line_player, data->colone_player) == 0)
		affiche_er(1);
	check_recto(data->lstmap);
	faire_map(data);
	// ft_lstclear_double(data->lstmap);
}


int	check_valid_path(m_list *data, int i, int j)
{
	static int c=0;
	static int e=0;
	
	if (data->lstmap2[i][j] == 'E')
		e = 1;
	if (data->lstmap2[i][j] == '1' || data->lstmap2[i][j] == 'E')
		return 0;
	else if (data->lstmap2[i][j] == 'C')
		c++;
	data->lstmap2[i][j] = '1';
	if (data->lstmap2[i][j + 1] != '1')
		check_valid_path(data, i, j + 1);
	if (data->lstmap2[i][j - 1] != '1')
		check_valid_path(data, i, j - 1);
	if (data->lstmap2[i + 1][j] != '1')
		check_valid_path(data, i + 1, j);
	if (data->lstmap2[i - 1][j] != '1')
		check_valid_path(data, i - 1, j);
	if (c == data->c && e == 1)
		return 1;
	return (0);
}

void	parsing1(m_list *data, char *str)
{
	int	i;
	int	e;
	int	p;

	i = 0;
	p = 0;
	e = 0;
	while (str[i])
	{
		if (str[i] == 'P')
			p++;
		else if (str[i] == 'E')
			e++;
		else if (str[i] == 'C')
			data->c++;
		else if (str[i] != '1' && str[i] != '0' && str[i] != '\n' && str[i] != '\0' && str[i] != 'C')
			affiche_er(1);
		i++;
	}
	if (p != 1 || e != 1 || data->c < 1)
		affiche_er(1);
}
