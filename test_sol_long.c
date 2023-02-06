/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sol_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stemsama <stemsama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 09:16:05 by stemsama          #+#    #+#             */
/*   Updated: 2023/02/03 09:59:32 by stemsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	close(int keycode, t_vars *vars)
{
	if (keycode == 51)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit (0);
	}
	return (0);
}

int	mouse_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook!\n");
	return (0);
}


int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 920, 180, "Hello world!");
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_string_put ( vars.mlx, vars.win, 100, 100, 0101, "Temsamani" );
	mlx_loop(vars.mlx);
}

