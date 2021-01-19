/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 16:09:00 by matraore          #+#    #+#             */
/*   Updated: 2021/01/19 17:15:10 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "../librairies/libft/libft.h"
# include "../librairies/get_next_line/get_next_line.h"
# include "minirt.h"
# include  "outils.h"
# include "tool.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

typedef	void	(*t_pars_func)(t_data *g_win, char **input);

typedef struct	s_parser
{
	char		*id;
    int         x;
	t_pars_func	func;
}				t_parser;



t_tuple				parse_vector(char *str, t_data *d);
void	parse_ambiant(t_data *g_win, char **array);
void        get_scene_info(t_data *g_win, const char *filename);
static int	parse_element(t_data *g_win, char *lines);
void	parse_resolution(t_data *g_win, char **array);
t_color     parse_color(char **array, t_data *g_win);
int         fdigit(char *str);
int         fdigit_d(char *str);
int         ft_array_length(char **array);
void     parse_camera(t_data *g_win, char **array);
int         check_camera(t_data *g_win, char **str);
void			multi_camera(t_cam **cams, t_cam *new_cam);
t_cam		*create_cam();
t_light		*create_light();
int         check_light(t_data *g_win,char **str);
void			checked_value_light(char **array, t_light *light, t_data *g_win);
void     parse_light(t_data *g_win, char **lines);
void     parse_sphere(t_data *g_win, char **array);
void			checked_value_sphere(t_data *g_win,char **arr, t_object *obj);
void     parse_plan(t_data *g_win, char **array);
void			checked_value_plan(t_data *g_win, char **arr, t_object *obj);
int         check_plan(t_data *g_win,char **str);


#endif