/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 09:11:22 by matraore          #+#    #+#             */
/*   Updated: 2021/01/19 16:30:38 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minirt.h"

void handle_argument_error(int argc, char **argv, t_data *d)
{
    int     length;
    char    *file;

    if (argc != 2 && argc != 3)
        error_exit("Le nombre d'argument invalide", d);
    if (argc == 3)
    {
        if (!(ft_strncmp(argv[2], "--save", 5)))
                printf("ok");
        else
            error_exit("Argument invalide", d);    
    }
    length = ft_strlen(argv[1]);
    file = argv[1];
    file += length - 3;
    if (ft_strncmp(file, ".rt", 3))
        error_exit("Fichier non supporte", d);
}

int main(int argc, char **argv)
{
    t_data  *g_win;
    char    *filename;

    
    handle_argument_error(argc, argv, g_win);
    filename = ft_strdup(argv[1]);
    g_win = tools_malloc(sizeof(t_data));
    g_win->list_cam = NULL;
    g_win->list_light = NULL;
    g_win->objects = NULL;
    get_scene_info(g_win, filename);
    // if (!(initialise_win(g_win)))
    //    error_exit("Echec d'ouverture de la fenetre", g_win);
    // mlx_loop(g_win->mlx_info.mlx);
    return (0);
}
