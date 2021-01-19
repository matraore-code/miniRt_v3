/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 03:40:35 by matraore          #+#    #+#             */
/*   Updated: 2021/01/19 15:40:08 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLES_H
# define TUPLES_H
# include "../tools/tools.h"

typedef struct	s_tuple
{
	double		x;
	double		y;
	double		z;
}				t_tuple;

t_tuple			create_tuple(double p_x, double p_y, double p_z);
t_tuple			*malloc_tuple(double p_x, double p_y, double p_z);
void			destroy_tuple(t_tuple to_destroy);
void			free_tuple(t_tuple *to_free);

t_tuple			add_tuple(t_tuple a, t_tuple b);
t_tuple			sub_tuple(t_tuple a, t_tuple b);
t_tuple			mult_tuple(t_tuple a, t_tuple b);
t_tuple			div_tuple(t_tuple a, t_tuple b);
t_tuple			scale_tuple(double scalar, t_tuple v);
t_tuple			rev_dir_tuple(t_tuple v);
void			cpy_tuple(t_tuple *dst, t_tuple src);
double			cos_tuple(t_tuple a, t_tuple b);
double			quadnorm_tuple(t_tuple v);
double			norm_tuple(t_tuple v);
t_tuple			normalize_tuple(t_tuple v);
double			dot_tuple(t_tuple a, t_tuple b);
t_tuple			cross(t_tuple a, t_tuple b);
double			longueur_tuple(t_tuple a);
double		distance_tuples(t_tuple a, t_tuple b);

#endif
