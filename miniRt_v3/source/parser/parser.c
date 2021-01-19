/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 03:10:21 by matraore          #+#    #+#             */
/*   Updated: 2020/12/17 05:35:47 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../includes/parser.h"
static int g_res;
static int g_am;
// static int	parse_camera(const char *lines)
// {
// 	char **array;

// 	array = ft_split(lines, ' ');
// 	printf("c : {%s} ", array[1]);
// 	printf("{%s}\n", array[3]);
// 	return (0);
// }

t_parser			g_parser[] = {
	{"R", 1, &parse_resolution},
	{"A", 1, &parse_ambiant},
	{"c", 1, &parse_camera},
	{"l", 1, &parse_light},
	{"pl", 2, &parse_plan},
	{"sp", 2, &parse_sphere},

};

static void	checke_elemt(t_data *g_win, char *c)
{
	char	**str;
	int i ;
	int j;

	 i = 0;
	 j = 0;
	while (c[i])
	{
		if (c[i] == '\t')
			c[i] = ' ';
		i++;
	}
	str = ft_split(c, ' ');
	while (g_parser[j].id)
    {
        if (!ft_strcnmp(str[0], g_parser[i].id, g_parser[i].x))
		{
			g_parser[i].func(str, g_win);
			return ;
		}
		j++;
    }
	error_exit("ERREUR DE FICHIER ID INCONU", g_win);
}

void		is_defined(t_data *g_win)
{
	if (!(g_win->res.is_def))
		error_exit("RESOLUTION NON DEFINIE", g_win);
	if (!(g_win->ambi.is_def))
		error_exit("LUMIERE AMBIANTE NON DEFINIE", g_win);
	if (!(g_win->list_cam->content))
		error_exit("La scene doit contenir une camera", g_win);
	if (!(g_win->list_light->content))
		error_exit("La scene doit contenir une lumiere", g_win);
}

void        get_scene_info(t_data *g_win, const char *filename)
{
    char        *lines;
    int         fd;
	int			i;

	i = 0;
	g_res = 0;
	g_am = 0;
	if ((fd = open(filename, O_RDONLY)) < 0)
		error_exit("echec d'ouverture du fichier", g_win);
	while (1)
	{
		i = get_next_line(fd, &lines);
		if(*lines != '#')
	 		checke_elemt(g_win, lines);
	 	if (i == 0)
	 		break;
		free(lines);
	}
    is_defined(g_win);
	g_win->camera = g_win->list_cam->content;
	g_win->lights = g_win->list_light->content;
}