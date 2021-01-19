/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 05:37:53 by matraore          #+#    #+#             */
/*   Updated: 2020/12/13 05:09:26 by matraore         ###   ########.fr       */
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
void			cpy_mat3x3(t_mat3x3 *dst, t_mat3x3 src);
t_mat3x3		identity_mat3x3(void);

#endif
