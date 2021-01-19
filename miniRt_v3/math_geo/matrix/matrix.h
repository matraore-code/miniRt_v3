/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 05:37:53 by matraore          #+#    #+#             */
/*   Updated: 2021/01/19 16:29:34 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H
# include "../tuples/tuples.h"
# include "../tools/tools.h"
# include <math.h>

typedef struct	s_mat3x3
{
	t_tuple		c1;
	t_tuple		c2;
	t_tuple		c3;
}				t_mat3x3;

t_mat3x3		create_mat3x3(t_tuple a, t_tuple b, t_tuple c);
t_mat3x3		*malloc_mat3x3(t_tuple a, t_tuple b, t_tuple c);
void			destroy_mat3x3(t_mat3x3 to_destroy);
void			free_mat3x3(t_mat3x3 *to_free);

t_mat3x3		transpose_mat3x3(t_mat3x3 mat);
t_mat3x3		invert_mat3x3(t_mat3x3 mat);
t_tuple		mult_mat3x3_tuple(t_mat3x3 mat, t_tuple v);
t_mat3x3		mult_mat3x3_mat3x3(t_mat3x3 mat1, t_mat3x3 mat2);
t_mat3x3		scale_mat3x3(double scalar, t_mat3x3 mat);
t_mat3x3		identity_mat3x3(void);
double      ft_sqr(double a);

#endif
