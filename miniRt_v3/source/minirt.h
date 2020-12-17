/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 08:11:26 by matraore          #+#    #+#             */
/*   Updated: 2020/12/16 01:29:52 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <mlx.h>
# include <stddef.h>
# include <stdlib.h>

typedef	struct s_img
{
	void *img;
	char *addr;
	int	bits_per_pixel;
	int	line_lenght;
	int endian;
} t_data;

typedef	struct		s_reso
{
	int				size_x;
	int				size_y;
}					t_reso;

typedef	struct		s_minilib
{
	void			*win_ptr;
	void			*mlx_ptr;
	char			*win_title;
	t_reso			res;
}					t_minilib;

t_minilib			g_window;

void				initialized_win(char *str);
void				open_window();
int					win_running();
int					ft_close(int keycode);
int					ft_exit(int keycode);
int					ft_exit2(int keycode);


#endif
