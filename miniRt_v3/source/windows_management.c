/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows_management.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 08:25:35 by matraore          #+#    #+#             */
/*   Updated: 2020/12/16 04:46:45 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdlib.h>
#include <stdio.h>


void	initialized_win(char *str)
{
	g_window.mlx_ptr = mlx_init();
	g_window.win_ptr = NULL;
	g_window.win_title = str;
	g_window.res.size_x = 600;
	g_window.res.size_y = 600;
}

void	open_window()
{
	g_window.win_ptr = mlx_new_window(g_window.mlx_ptr,
	g_window.res.size_x, 
	g_window.res.size_x,
	g_window.win_title);
}

int		win_running(t_minilib window)
{
	mlx_loop(window.mlx_ptr);
	return (1);
}

int	ft_exit(int keycode)
{
	if (keycode == 53)
	{
		mlx_destroy_window(g_window.mlx_ptr, g_window.win_ptr);
		exit(1);
	}
	return(0);	// return (ft_close(keycode, window));
}

int	ft_exit2(int keycode)
{
		exit(1);
}