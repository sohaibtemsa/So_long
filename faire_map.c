/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   faire_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stemsama <stemsama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:39:38 by stemsama          #+#    #+#             */
/*   Updated: 2023/02/04 14:21:12 by stemsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"


void	prend_limage(m_list *data)
{
	int	a;

	a = 50;
	data->height = &a;
	data->width = &a;
	data->player = mlx_xpm_file_to_image(data->mlx_ptr, "recherche/z_player.xpm", 
		data->width, data->height);
	data->back_gd = mlx_xpm_file_to_image(data->mlx_ptr, "recherche/back_g_1.xpm", 
		data->width, data->height);
	data->wall = mlx_xpm_file_to_image(data->mlx_ptr, "recherche/player.xpm", 
		data->width, data->height);
	data->exit = mlx_xpm_file_to_image(data->mlx_ptr, "recherche/exit1.xpm", 
		data->width, data->height);
	data->collective = mlx_xpm_file_to_image(data->mlx_ptr, "recherche/collective.xpm", 
		data->width, data->height);
}

void	appliquer_limage(m_list *data)
{
	int	i;
	int	j;
	char **lstmap;

	lstmap = data->lstmap;
	i = 0;
	while (lstmap[i])
	{
		j = 0;
		while (lstmap[i][j])
		{
			if (lstmap[i][j] == 'P')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->back_gd,j * 50, i * 50);
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player,j * 50, i * 50);
			}
			else if (lstmap[i][j] == 'E')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->back_gd,j * 50, i * 50);
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->exit,j * 50, i * 50);
			}
			else if (lstmap[i][j] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall,j * 50, i * 50);
			else if (lstmap[i][j] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->back_gd,j * 50, i * 50);
			else if (lstmap[i][j] == 'C')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->back_gd,j * 50, i * 50);
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->collective,j * 50, i * 50);	
			}
			j++;
		}
		i++;
	}	
}

int	update_win(m_list *data)
{
	prend_limage(data);
	appliquer_limage(data);
	return (0);
}
void	faire_map(m_list *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->nbr_colone * 50, data->nbr_line * 50, "So Long !");
	update_win(data);
	mlx_loop_hook(data->mlx_ptr, &update_win, data);
	// mlx_key_hook(data->win_ptr, &move_player, data);
	mlx_hook(data->win_ptr, 2, 0, &move_player, data);
	mlx_loop(data->mlx_ptr); 
}
